//Specification file complexType.h
   
#ifndef H_complexNumber
#define H_complexNumber

#include <iostream>

using namespace std; 

class complexType
{
      //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const complexType&);
    friend istream& operator>>(istream&, complexType&);

public:
    void setComplex(const double& real, const double& imag);
      //Function to set the complex numbers according to 
      //the parameters.
      //Postcondition: a = real; b = imag;

    void getComplex(double& real, double& imag) const; 
	  //Function to retrieve the complex number. 
      //Postcondition: real = a; imag = b;
  
    complexType(double real = 0, double imag = 0);  
      //Constructor
      //Initializes the complex number according to 
      //the parameters.
      //Postcondition: a = real; b = imag;

    complexType operator+
                     (const complexType& otherComplex) const;
      //Overload the operator +

    complexType operator*
                     (const complexType& otherComplex) const;
      //Overload the operator *

    bool operator == (const complexType& otherComplex) const;
      //Overload the operator ==

private:
    double a;       //variable to store the real part
    double b;  //variable to store the 
                           //imaginary part
};

ostream& operator<<(ostream& osObject,  
                    const complexType& complex)

{
    osObject << "(";                    //Step a
    osObject << complex.a;       //Step b
    osObject << ", ";                   //Step c
    osObject << complex.b;  //Step d
    osObject << ")";                    //Step e

    return osObject;    //return the ostream object
}

istream& operator>>(istream& isObject, complexType& complex)
{
    char ch;

    isObject >> ch;                     //Step a
    isObject >> complex.a;       //Step b
    isObject >> ch;                     //Step c
    isObject >> complex.b;  //Step d
    isObject >> ch;                     //Step e

    return isObject;    //return the istream object
}

bool complexType::operator==
                    (const complexType& otherComplex) const
{
    return (a == otherComplex.a && 
            b == otherComplex.b);
}


    //Constructor 
complexType::complexType(double real, double imag)
{
    a = real;
    b = imag;
}

    //Function to set the complex number after the object 
    //has been declared.
void complexType::setComplex(const double& real, 
                             const double& imag)
{
    a = real;
    b = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
    real = a;
    imag = b;
}

	//overload the operator +
complexType complexType::operator+
 			   (const complexType& otherComplex) const
{
    complexType temp;

    temp.a = a + otherComplex.a;
    temp.b = b 
                         + otherComplex.b;

	return temp;
}

    //overload the operator *
complexType complexType::operator*
 				(const complexType& otherComplex) const
{
    complexType temp;

    temp.a = (a * otherComplex.a) -
                 (b * otherComplex.b);
    temp.b = (a * otherComplex.b)
                   + (b * otherComplex.a);
    return temp;
}


#endif
