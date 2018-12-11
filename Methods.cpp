#include "Head.h"

// Integral
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

		while (x + h <= b) {
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
	uns n = 10;
	double h = (b - a) / static_cast<double>(2 * n);
	double Ih = 0, Ih_2 = 0;
	double x;
	double eps = 1e-4;				//or 1e-5
	uns k = 0, i = 0;

	while (true)					//endless loop
	{
		k++;
		x = a;

		Ih_2 = func(x);
		for (x, i = 0; x <= b; x += h, i++)
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

// Multiple integral
// Cube Simpson
void cu_Simpson(double &a, double &b, double &c, double &d, double &res)
{
	uns n, m = n = 5;
	double eps = 1e-8;//
	double hx = (b - a) / (2 * n), hy = (d - c) / (2 * m);
	double x = a, y = c, grd = 0;

	while (true)
	{
		res = 0;
		x = a; y = c;
		for (uns i, j = i = 0; x <= b, y <= d; x += hx, y += hy, i++, j++)
		{		
			if (i % 2 == 0 && j % 2 == 0){
				res += func(x, y);
			} else {
				if (i % 2 == 0 || j % 2 == 0) 
			{
					res += 4 * func(x, y);
				} else res += 16 * func(x, y);
			}
		}

		res *= hx * hy / 9.;

		if (fabs(res - grd) < 15. * eps)
			break;
		grd = res;
	}
}