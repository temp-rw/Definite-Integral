#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>
#include <cmath>
#include <functional>
#include <vector>

//namespace
using namespace std;

//typedef
typedef unsigned uns;

// Linear integral
int trapeze(double &a, double &b, double &result);

// Square Simpson
int sq_Simpson(double &a, double &b, double &result);

// Multiple integral
// Cube Simpson
void cu_Simpson(double &a, double &b, double &c, double &d, double &res);


double func(double &x);
double func(double &x, double &y);