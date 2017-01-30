#include "../../std_lib_facilities.h"
#include <cstdint>

//Functions--------------------------

vector<bool> sieveOfEratosthenes(const int limit)
{
	vector<bool> primes;

	for (bool b : primes)
		b = true;

	const int index_start = 2;
	int index = index_start;

	while (index <= limit)
	{
		for (int i = 2; i < limit / index; i++) //table of multiplecation
			primes[index * i] = false; //multiples of primes are not primes

		for (int i = index; index <= limit; i++)
			if (primes[i] == true)
				index = i;
	}
	return primes;
}

bool checkPrime(int number)
{
	if (number == 1 || number == 0)
		return false;
	
	if (number % 2 == 0)
		return false;
	
	for (int i = 3; i < number; i += 2) {
		if (number % i == 0)
			return false;
	}
	return true;
}

vector<long long int> vectorPrime(long long int size) 
{
	vector<long long int> primes;
	for (int i = 0; i < size; i++) { //put primes inside vector
		if (checkPrime(i))
		{
			primes.push_back(i);
		}
			
	}
	return primes;
}

int sumTable(const int& x,const int& limit)
{
	int multiple = 0;
	int sum = 0;

	for (int i = 1; multiple < limit; i++) { //add multiples of 3
		multiple = x * i;
		if (multiple < limit)
			sum += multiple;
	}
	return sum;
}

vector<int> digitsNumber(int number)
{
	vector<int>digit;
	while (number >= 1) {
		digit.push_back(number % 10);
		number /= 10;
	}
	return digit;
}

bool palindrome(vector<int>digit)
{
	for (int i = 0; i < digit.size()/2; i++)
	{
		if (digit[i] != digit[(digit.size() - 1) - i])
			return false;
	}
	return true;
}

bool divisble(const int& number,const int& limit)
{
	for (int i = 2; i <= limit; i++)
		if (number % i != 0)
			return false;
	return true;
}

int next_Fibonacci_number(int& number1, int& number2)
{
	int temp = 0;
	temp = number1 + number2;
	number1 = number2;
	number2 = temp;
	return temp;
}

//Problems---------------------------

void problem_1()
{
	const int limit = 1000; //sum of 3 and 5 multiples till n
	
	int sum = 0;

	sum += sumTable(3, limit);
	sum += sumTable(5, limit);
	sum -= sumTable(15, limit);

	cout << sum;
}

void problem_2()
{
	const int limit = 4000000; //even fibonnaci numbers till n
	
	int number1 = 0; 
	int number2 = 1;

	int temp = 0;
	int sum = 0;

	do
	{
		temp = next_Fibonacci_number(number1, number2); //does modify by reference
		if ( temp % 2 == 0)
			sum += temp;
	} while (temp < limit);
		
	cout << sum << endl;
}

void problem_3()
{
	long long int limit = 600851475143; //largest primefactor of number n 
	long long int num = limit;

	for (int i = 1; i < num; i++)
	{
		if (checkPrime(i)) {
			while (num %i == 0)
				num = num / i;
		}
	}

	cout << num;
}

void problem_4()
{
	const int limitLow = 111; // which digets here  111-999
	const int limitHigh = 999; 

	int highest = 0; 
	for (int i = limitLow; i <= limitHigh; i++)
	{
		for (int ii = limitLow; ii <= limitHigh; ii++)
		{
			if (palindrome(digitsNumber(i*ii))) {
				cout << i << "*" << ii << " = " << i*ii << endl;
				if (i*ii > highest)
					highest = i*ii;
			}
		}
	}
	cout << "Highest is " << highest;
}

void problem_5()
{
	const int limitStart = 20; //number what the result should by posbile to be divided by
	int limit = 4;
	int number = 2520;
	int number_increment = number;

	for (int i = limit; i < limitStart; number += number_increment)
		{
			if (divisble(number, limit))
			{
				limit++;
				if (limit == limitStart){
					cout << number;
					return;
				}
					
			}
		}
}

void problem_6()
{
	const int limit = 100; //how much natural numbers
	
	int sum_squared = 0; //1^2 + 2^2 + ... + 10^2 = 385
	int sum = 0;
	int squared_sum = 0; //(1 + 2 + ... + 10)^2 = 55^2 = 3025
	int difference = 0;

	for (int i = 1; i <= limit; i++)
	{
		sum += i;
		sum_squared += i*i;
	}
	squared_sum = sum * sum;
	difference = squared_sum - sum_squared;
	cout << difference;
}

void problem_7()
{
	const int limit = 10001; //Enter nth prime
	vector<int> primes;
	primes.push_back(0);
	for (int i = 2; primes.size() < limit; i++) {
		if (checkPrime(i))
			primes.push_back(i);
	}
	cout << primes[primes.size() - 1];
}

void problem_8()
{
	const int limit = 13; //Enter how much numbers on a row to multyply

	const string number = "73167176531330624919225119674426574742355349194934"
		"96983520312774506326239578318016984801869478851843"
		"85861560789112949495459501737958331952853208805511"
		"12540698747158523863050715693290963295227443043557"
		"66896648950445244523161731856403098711121722383113"
		"62229893423380308135336276614282806444486645238749"
		"30358907296290491560440772390713810515859307960866"
		"70172427121883998797908792274921901699720888093776"
		"65727333001053367881220235421809751254540594752243"
		"52584907711670556013604839586446706324415722155397"
		"53697817977846174064955149290862569321978468622482"
		"83972241375657056057490261407972968652414535100474"
		"82166370484403199890008895243450658541227588666881"
		"16427171479924442928230863465674813919123162824586"
		"17866458359124566529476545682848912883142607690042"
		"24219022671055626321111109370544217506941658960408"
		"07198403850962455444362981230987879927244284909188"
		"84580156166097919133875499200524063689912560717606"
		"05886116467109405077541002256983155200055935729725"
		"71636269561882670428252483600823257530420752963450";

	int64_t largest = 0;
	int64_t numm = 0;


	for (int i = 0; i < number.length() - limit; i++)
	{
		numm += number.at(i) - '0'; //initialize number with first number
		for (int j = 1; j < limit; j++)
		{
			numm *= number.at(i + j) - '0'; //factor rest of numbers
		}
		if (numm > largest)
			largest = numm;
		numm = 0;
	}	
	cout << largest;
}	

void problem_9()
{
	const int limit = 12;

	for (int c = 0; true ; c++)
	{
		for (int b = 0; b < c; b++)
		{
			for (int a = 0; a < b; a++)
			{
				if (pow(a, 2) + pow(b, 2) == pow(c, 2))
					if (a + b + c == 1000)
					{
						cout << a*b*c;
						return;
					}
						
			}
		}
	}
	//a + b + c is 12;
	//a < b < c
	//pow(a) + pow(b) == pow(c)
}

void problem_10()
{
	int sum = 0;
	const int limit = 2000000;

	for (int x : vectorPrime(limit))
		sum += x;

	cout << "sum of primes till " << limit << " is " << sum;
}


//Main-------------------------------

int main()
{
	cout << "Please enter the problem number:";
	int input;
	cin >> input;
	
	switch (input)
	{
	case 1: problem_1(); break;
	case 2: problem_2(); break;
	case 3: problem_3(); break;
	case 4: problem_4(); break;
	case 5: problem_5(); break;
	case 6: problem_6(); break;
	case 7: problem_7(); break;
	case 8: problem_8(); break;
	case 9: problem_9(); break;
	case 10: problem_10(); break;
	default:
		break;
	}
	cout << endl;
	keep_window_open();
	return 1;
}