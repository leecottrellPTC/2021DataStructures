#include "Fraction.hpp"  
	
Fraction::Fraction()
{
	
}
	
Fraction::~Fraction()
{
	
}

Fraction Fraction::operator + (Fraction &item){
    //a/b + c/d 5 (ad + bc)/bd
    //c == a in item or the second fraction
    //d == b in item or the second fraction
    Fraction answer;
    answer.a = (this->a * item.b + this->b * item.a);
    answer.b = this->b * item.b;
    return answer;
}