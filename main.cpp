#include "Head.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("Lab #5");
	system("color 0A");
	double a = 1., b = 2.835, result = 0.;			//a = 1.0, b = 2.835; // var #8


	int number_of_separations = trapeze(a, b, result);
	cout << "Trapezoid method\nIntegral value: \t" << setprecision(9) << result << "\nNumber of doubles of separation: " << number_of_separations << endl;
	
	number_of_separations = sq_Simpson(a, b, result);
	cout << "\nSquare Simpson Method\nIntegral value: \t"  << setprecision(9) << result << "\nNumber of doubles of separation: " << number_of_separations << endl;

	
	a = 0., b = 1.;//a = 0.;	b = 4.;
	double c = 1., d = 2.;
	
	cu_Simpson(a, b, c, d, result);
	cout << "\nCube Simpson Method\nIntegral value: \t" << setprecision(9) << result << endl;

	system("pause");
}

//function of 1 argument
double func(double &x)				
{
	return 1.;//1. / (log10(x)*log10(x) + 1.);
}

//function of 2 arguments
double func(double &x, double &y)	
{
	return 1.;//x * x / (1. + y * y);//sin(x + y);//
}






