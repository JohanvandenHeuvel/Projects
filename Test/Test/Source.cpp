#include "../../std_lib_facilities.h"

//----------------------------------------------

const char declare_variable = 'l';
const char print = ';';
const char quit = 'q';
const char number = '0';
const char name = 'a';
const char square_root = 's';
const char power = 'p';
const char const_name = 'c';
const char help = 'h';

const int k = 1000;

const string prompt = "> ";
const string result = "= ";

//----------------------------------------------

class Token {
public:
	char kind;
	string name;
	double value;

	Token(char ch) :kind{ ch }, value{ 0 } {} //let char represent itself
	Token(char ch, double v) :kind{ ch }, value{ v } {} //a double
	Token(char ch, string n) :kind{ ch }, name{ n } {} //for declaring variables
};

//----------------------------------------------

class Token_stream {
public:
	Token_stream() :full(false), buffer(0) {} // initialize buffer
	Token get(); // get a token from cin
	void unget(Token t) { // ??? Put token back in the buffer
		buffer = t;
		full = true;
	}
	void ignore(char c); // ???
private:
	Token buffer;
	bool full;
};

//----------------------------------------------

Token Token_stream::get()
{
	if (full == true) { // check if there is already a Token in the buffer
		full = false;
		return buffer;
	}

	char ch;
	cin.get(ch);
	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // if newline detected, return print Token
		cin.get(ch);
	}


	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case 'k':
	case ',':
		return Token(ch); // let char represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget(); // put char back into input stream
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch) || ch == '#') { // see if input stream starts with a letter
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			cin.putback(ch);
			if (s == "#")
				return Token(declare_variable);
			else if (s == "help")
				return Token(help);
			else if (s == "sqrt")
				return Token(square_root);
			else if (s == "pow")
				return Token(power);
			else if (s == "exit")
				return Token(quit);
			else if (s == "const")
				return Token(const_name);
			else
				return Token(name, s);
		}
		else
			error("Bad Token");
	}
}

//----------------------------------------------

void Token_stream::ignore(char c) // clean input till ';'
{
	if (full == true && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c)
			return;
}

//----------------------------------------------

class Variable {
public:
	double value;
	string name;
	bool constant;
	Variable(string n, double v, bool c) :name(n), value(v), constant(c) {}
};

//----------------------------------------------

class Symbol_table {
public:
	double get(string s);
	void set(string s, double d);
	bool is_declared(string s);
	double declaration(bool c);
private:
	vector<Variable> names;
};

//----------------------------------------------

Symbol_table variable;

//----------------------------------------------

double Symbol_table::get(string s)
{
	for (const Variable& v : names)
		if (v.name == s)
			return v.value;
	error("get: undefined name ", s);
}

//----------------------------------------------

void Symbol_table::set(string s, double d)
{
	for (Variable& v : names)
		if (v.name == s)
			if (!v.constant)
			{
				v.value = d;
				return;
			}
			else
				error("set: constant ", s);
	error("set: undefined name ", s);
}

//----------------------------------------------

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s)
			return true;
	return false;
}

//----------------------------------------------

Token_stream ts;

//----------------------------------------------

double expression();

//----------------------------------------------

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		else
			return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
	{
		Token t2 = ts.get();
		if (t2.kind == '=') {
			double d = expression();
			variable.set(t.name, d);
			return d;
		}
		else {
			ts.unget(t2);
			return variable.get(t.name);
		}
	}
	case square_root:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected (use space before)");
		double d = expression();
		if (d < 0)
			error("cannot take square root of negative numbers");
		t = ts.get();
		if (t.kind != ')')
			error("')' expected (use space before)");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' expected (use space before)");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		t = ts.get();
		if (t.kind != number)
			error("second argument of pow is not a number");
		int i = int(t.value);
		if (i != t.value) error("second argument of 'pow' is not an integer");
		i = double(i);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return pow(d, i);
	}
	default:
		error("primary expected");
	}
}

//----------------------------------------------

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case 'k':
			left *= k;
			t = ts.get();
			break;
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double right = primary();
			if (primary == 0)
				error("/:divide by zero");

			left /= right;
			t = ts.get();
			break;
		}
		case '%':
		{
			double right = primary();
			if (primary == 0)
				error("%:divide by zero");
			left = fmod(left, right);
			t = ts.get();
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


//----------------------------------------------

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//----------------------------------------------

double Symbol_table::declaration(bool c)
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");
	string name = t.name;

	if (is_declared(name)) error(name, " declared twice");

	Token t2 = ts.get();

	if (t2.kind != '=')
		error("= missing in declaration of ", name);

	double d = expression();
	names.push_back(Variable(name, d, c));
	return d;
}

//----------------------------------------------

double statement() // ??? See if user wants to declare a variable
{
	Token t = ts.get();
	switch (t.kind) {
	case declare_variable:
		return variable.declaration(false); //
	case const_name:
		return variable.declaration(true);
	default:
		ts.unget(t);
		return expression(); //start parse through input
	}

}

//----------------------------------------------

void clean_up_mess()
{
	ts.ignore(print); // ignore input till ';'
}

//----------------------------------------------

void calculate()
{
	while (cin)
		try {
		cout << prompt;
		Token t = ts.get();

		while (t.kind == print) // ???
			t = ts.get();
		if (t.kind == quit)	// quit the program if 'q' is entered
			return;
		if (t.kind == help)
		{
			cout << "----  instructions  ----" << endl << endl;
			cout << "-- use const 'name = value' to declare a constant" << endl;
			cout << "-- use # 'name = value' to declare a variable" << endl;
		}
		ts.unget(t); // put t back into Token Stream
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//----------------------------------------------

int main()
try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';'); // ??? read input into cin till ';' 
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';'); // ??? read input into cin till ';'
	return 2;
}