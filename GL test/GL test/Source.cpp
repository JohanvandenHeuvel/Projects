#include "../../Graph.h"
#include "../../Window.h"
#include "../../Simple_window.h"

using namespace Graph_lib;

int main()
try
{
	Point tl{ 100,100 };

	Simple_window win{ tl,600,400, "Canvas" };

	win.wait_for_button();
}
catch (exception& e)
{
	cerr << "exception:" << e.what() << endl;
}
catch (...)
{
	cerr << "exception\n";
}