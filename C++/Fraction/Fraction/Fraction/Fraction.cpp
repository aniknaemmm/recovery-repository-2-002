#include "Fraction.h"


Fraction::Fraction()
{
	numerator = 0;
	denumenator = 1;
}

Fraction::Fraction(int num,int denum)
{
	numerator = num;
	denumenator = denum;
}

Fraction::Fraction(int num)
{
	numerator = num;
	denumenator = 1;
}

Fraction::Fraction(double num)
{


}

Fraction::~Fraction()
{
}

Fraction Fraction::operator+()const 
{
	Fraction temp(*this);
	if (temp.numerator < 0)
		temp.numerator *= (-1);
	return temp;
}

Fraction Fraction::operator+(const Fraction& obj)const
{
	Fraction temp;
	if (obj.denumenator != denumenator)
	{
		temp.denumenator = denumenator*obj.denumenator;
		temp.numerator = numerator*obj.denumenator + obj.numerator*denumenator;
	}
	else
	{
		temp.denumenator = denumenator;
		temp.numerator = obj.numerator + numerator;
	}
	return temp;
}

Fraction Fraction::operator-()const
{
	Fraction temp(*this);
	if (temp.numerator>0)
		temp.numerator *= (-1);
	return temp;
}

Fraction Fraction::operator-(const Fraction& obj)const 
{
	Fraction temp;
	if (obj.denumenator != denumenator)
	{
		temp.denumenator = denumenator*obj.denumenator;
		temp.numerator = numerator*obj.denumenator - obj.numerator*denumenator;
	}
	else
	{
		temp.denumenator = denumenator;
		temp.numerator = numerator-obj.numerator;
	}
	return temp;
}

Fraction& Fraction::operator+=(const Fraction& obj)
{	
	Fraction temp(*this),result;
	result = temp + obj;
	numerator = result.numerator;
	denumenator = result.denumenator;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& obj)
{
	Fraction temp(*this), result;
	result = temp - obj;
	numerator = result.numerator;
	denumenator = result.denumenator;
	return *this;
}

Fraction Fraction::operator*(const Fraction& obj)const
{
	Fraction temp;
	temp.denumenator = denumenator*obj.denumenator;
	temp.numerator = numerator*obj.numerator;
	return temp;
}

Fraction Fraction::operator/(const Fraction& obj)const
{
	Fraction temp;
	temp.denumenator = denumenator*obj.numerator;
	temp.numerator = numerator*obj.denumenator;
	return temp;
}
