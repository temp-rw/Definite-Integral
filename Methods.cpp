#include "Head.h"

// Linear integral
// Trapezoid method
int trapeze(double &a, double &b, double &res)
{
	double eps = 1e-4;//or 1e-5
	uns n = 10;
	double I_h2 = 0, I_h1 = 0, r = 0.5, h = (b - a) / static_cast<double> (n);		//h - step of the grid
	double x;			//argument of function
	uns k = 0;			//p = 2 - 
	
	
	while (true)
	{
		k++;
		x = a;
		I_h2 = func(a);

		while (x + h < b) {
			x += h;
			I_h2 += 2 * func(x);
		}

		I_h2 += func(b);
		I_h2 *= h / 2;

		if (fabs(I_h2 - I_h1) <= 3 * eps)
			break;
		
		h /= 2;
		I_h1 = I_h2;
	}
	res = I_h2;

	return static_cast<int>(k);
}

// Square Simpson
int sq_Simpson(double &a, double &b, double &res)	
{
	double h = (b - a) / static_cast<double>(2 * res);
	double Ih = 0, Ih_2 = 0;
	double x;
	double eps = 1e-4;				//or 1e-5
	uns k = 0, i = 0;

	while (true)					//endless loop
	{
		k++;
		x = a;

		Ih_2 = func(x);
		for (x, i = 0; x < b; x += h, i++)
		{
			if (i % 2 == 0)
				Ih_2 += 2 * func(x);
			else 
				Ih_2 += 4 * func(x);

		}
		Ih_2 += func(x);
		Ih_2 *= h / 3;
		
		if (fabs(Ih_2 - Ih) <= 15 * eps)
			break;

		h /= 2;
		Ih = Ih_2;
	}
	res = Ih_2;

	return static_cast<int>(k);
}

//Non-linear integral
//Cube Simpson
void cu_Simpson()
{

}