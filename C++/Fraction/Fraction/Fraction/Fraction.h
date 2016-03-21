#pragma once

class Fraction
{
public:
	int numerator;
	int denumenator;
	

	Fraction();
	Fraction(int num, int den);
	Fraction(int numb);
	Fraction(double numb);

	~Fraction();

	Fraction operator+()const;
	Fraction operator-()const;
	Fraction operator+( const Fraction& obj)const;
	Fraction operator-( const Fraction& obj)const;
	Fraction& operator+=(const Fraction& obj);
	Fraction& operator-=(const Fraction& obj);
	Fraction operator*( const Fraction& obj)const;
	Fraction operator/( const Fraction& obj)const;
	Fraction& operator*=(const Fraction& obj){ return (*this) = (*this)*obj;}
	Fraction& operator/=(const Fraction& obj){ return (*this) = (*this)/obj;}
	bool operator==(const Fraction& obj)const{ return (numerator == obj.numerator) && (denumenator == obj.denumenator);}
	bool operator!=(const Fraction& obj)const{ return !((*this) == obj);	}
	bool operator>=(const Fraction& obj)const{ return ((*this) > obj) || ((*this) == obj);}
	bool operator<=(const Fraction& obj)const{ return ((*this) < obj) || ((*this) == obj);}
	bool operator> (const Fraction& obj)const{ return  numerator*obj.denumenator > obj.numerator*denumenator;}
	bool operator< (const Fraction& obj)const{ return !((*this) > obj);}
};

