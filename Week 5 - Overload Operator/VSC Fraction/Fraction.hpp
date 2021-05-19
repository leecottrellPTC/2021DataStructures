#ifndef FRACTION_H
#define FRACTION_H
#pragma once
	
class Fraction  
{
	protected:
		double a;
		double b;

	public:
		Fraction operator +(Fraction &item);
		Fraction();
		~Fraction();

};
#endif