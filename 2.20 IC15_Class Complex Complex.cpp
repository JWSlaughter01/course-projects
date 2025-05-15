#include "Complex.h"

//write the parametrized constructor
Complex::Complex(double r, double i) {
   real = r;
   imaginary = i;
}

//we are assuming string is of format "10.1 20.2"
Complex::Complex(string input) {
  real = imaginary = 0; //additional safety!
  istringstream(input) >> real >> imaginary;
}
Complex::~Complex()
{
    cout <<"Destructor called" << endl;
}

//Write getters and setters
//getters
double Complex::getReal() {
   return real;
}

double Complex::getImaginary() {
   return imaginary;
}

//setters
void Complex::setReal(double r) {
   real = r;
}

void Complex::setImaginary(double i) {
   imaginary = i;
}


//write overloaded operators for + and =+
Complex Complex::operator+(const Complex& other) const {
   return Complex(real + other.real, imaginary + other.imaginary);
}

void Complex::operator+=(const Complex& other) {
   real += other.real;
   imaginary += other.imaginary;
   //return *this;
   //I originally had this function as a double and I was getting errors
   //checked header file and this was a void function
}


//return conjugate?
/*
   cout << "The conjugate of c3 assigned to c4 is : ";
   Complex c4 = ~c3; //(a, b) -> (a, -b)
   cout << c4 << endl; //~ operator should return conjugate of complex number: (a,b) --> (a,-b)
*/
Complex Complex::operator~() {
   return Complex(real, -imaginary);
}


//treat input like cin
//tried to model off of the ostream& code that was already present below
istream& operator>>(istream& input, Complex& object) {
   input >> object.real >> object.imaginary;
   return input;
}


//treat output like cout
ostream& operator<<(ostream& output, const Complex &object) {
  output << "(" << object.real << ","
                << object.imaginary << ")";
  return output;
}
