#include "Head.h"


void main()
{
	SetConsoleCP(1251);
	system("color 0A");
	SetConsoleTitleA("Лаборатрная №5");
	double a = 1., b = 2.865, result = 0.;			//a = 1.0, b = 2.835; // var #8


	int number_of_separations = trapeze(a, b, result);
	cout << "Trapezoid method\nIntegral: \t" << setprecision(9) << result << "\nNumber of doubles of separation: " << number_of_separations << endl;
	
	number_of_separations = sq_Simpson(a, b, result);
	cout << "\nSquare Simpson Method\nIntegral: \t"  << setprecision(9) << result << "\nNumber of doubles of separation: " << number_of_separations << endl;


	/*a = 0.;	b = 4.;
	double c = 1., d = 2.;*/


	system("pause");
}

//function of 1 argument
double func(double &x)				
{
	return 1 / (log10(x)*log10(x) + 1);
}

//function of 2 arguments
double func(double &x, double &y)	
{
	return x * x / (1 + y * y);
}






