#pragma once
#include <math.h>

class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci();

	int operator[](int n)
	{
		int a = 1, b = 0, c;
		for (int i = 0; i < n; ++i)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
	/*
	int operator[](int n)
	{
		double phi = (1.0 + sqrt(5.0)) / 2.0;
		return (pow(phi, n) - pow(-phi, -n)) / (2 * phi - 1.0);
	}
	*/
};

