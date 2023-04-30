#include "Fraction.hpp"

#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;
Fraction::Fraction() : m_num(0), m_den(1) {}
Fraction::Fraction(float num){
    const int precision = 1000; // set the precision to a large number
    this->m_num = static_cast<int>(num * precision); // convert the float to an integer
    this->m_den = precision;

    

}
//Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
// Fraction(double value) {
//             int sign = (value < 0) ? -1 : 1;
//             value = fabs(value);
//             //int whole = static_cast<int>(value);
//             numerator = whole * sign;
//             value -= whole;
//             while (fabs(round(value) - value) > 0.0001) {
//                 value *= 10;
//                 numerator *= 10;
//             }
//             denominator = static_cast<int>(round(value));
//             simplify();
//         }
// operator double() const { return static_cast<double>(numerator) / denominator; }
Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    this->m_num = num;
    this->m_den = den;
    
}

Fraction Fraction::reduce() {
    int gcd = Fraction::gcd(m_num, m_den);
    m_num /= gcd;
    m_den /= gcd;

    return *this;
}

int Fraction::gcd(int num, int den) {
    return den == 0 ? num : gcd(den, num % den);
}

// ostream &operator<<(ostream &os, const Fraction &f) {
//     os << to_string(f.num());
//     if (f.den() != 1) {
//         os << '/' << to_string(f.den());
//     }
//     return os << m_num << '/' << m_den;
// }
// istream &operator>>(istream &os, Fraction &f) {
//     char c;
//     os  >> 5;
    
//     return os;
// }
Fraction Fraction::operator+(const Fraction& other) const {
    int num = m_num * other.m_den + m_den * other.m_num;
    int den = m_den * other.m_den;
    return Fraction(num, den).reduce();
}
Fraction ariel::operator+( const Fraction& fracconst ,float num){
   Fraction temp= Fraction(num);

    return (fracconst+temp).reduce();
}
Fraction ariel::operator+(float num,const Fraction& fracconst ){
   Fraction temp= Fraction(num);

    return (fracconst+temp).reduce();
}
Fraction Fraction::operator-(const Fraction& other) const {
    int num = m_num * other.m_den - m_den * other.m_num;
    int den = m_den * other.m_den;
    return Fraction(num, den).reduce();
}

Fraction ariel::operator-(const Fraction& other, float num) {
    Fraction temp= Fraction(num);
    return (other-temp).reduce();
}
Fraction ariel::operator-(float num,const Fraction& other)  {
    Fraction temp= Fraction(num);
    return (temp-other).reduce();
}


Fraction Fraction::operator*(const Fraction& other) const {
    int num = m_num * other.m_num;
    int den = m_den * other.m_den;
    return Fraction(num, den).reduce();
}
Fraction ariel::operator*(float num,const Fraction& franc){
    Fraction temp= Fraction(num);
    
    return (franc*temp).reduce();
}

Fraction ariel::operator*(const Fraction& franc,float num){
    Fraction temp= Fraction(num);
    
    return (franc*temp).reduce();
}
Fraction Fraction::operator/(const Fraction& other) const {
    int num = m_num * other.m_den;
    int den = m_den * other.m_num;
    return Fraction(num, den).reduce();
}
Fraction ariel::operator/(const Fraction& frac, float num) {
    // Convert the number to a fraction
    Fraction num_fraction = Fraction(num);

    
   

    return (frac/num_fraction).reduce();
}
Fraction ariel::operator/( float num,const Fraction& frac) {
    // Convert the number to a fraction
    Fraction num_fraction = Fraction(num);

    

    return (num_fraction/frac).reduce();
}

Fraction Fraction::operator++() {
    m_num += m_den;
    return (*this).reduce();
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    ++(*this);
    return temp.reduce();
}

Fraction Fraction::operator--() {
    m_num -= m_den;
    return (*this).reduce();
}

Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    --(*this);
    return temp.reduce();
}


bool Fraction::operator>(const float value)  {
    Fraction other=Fraction(value);
    return (m_num*other.m_den > other.m_num* m_den);
}
bool Fraction::operator>(const Fraction& other) {


    return (m_num*other.m_den > other.m_num* m_den);
}

bool Fraction::operator>=(const Fraction& other) {


    return (m_num*other.m_den >= other.m_num* m_den);
}
bool Fraction::operator>=(const float value)  {

    return ((m_num/m_den) >= value);
}
bool ariel::operator>(float num,const Fraction& frac){
    Fraction temp=Fraction(num);
    return (temp>frac);
}
bool ariel::operator>=(float num,const Fraction& frac){
    Fraction temp=Fraction(num);
    return (temp>=frac);
}

bool Fraction::operator<(const float value)  {
    Fraction other=Fraction(value);
    return (m_num*other.m_den < other.m_num* m_den);
}

bool Fraction::operator<(const Fraction& other) {


    return (m_num*other.m_den < other.m_num* m_den);
}
bool Fraction::operator<=(const Fraction& other) {


    return (m_num*other.m_den <= other.m_num* m_den);
}
bool Fraction::operator<=(const float value)  {

    return ((m_num/m_den) <= value);
}

bool ariel::operator<(float num,const Fraction& frac){
    Fraction temp=Fraction(num);
    return (temp<frac);
}
bool ariel::operator<=(float num,const Fraction& frac){
    Fraction temp=Fraction(num);
    return (temp<=frac);
}


bool Fraction::operator==(const Fraction& other) const{
    return (m_num*other.m_den <= other.m_num* m_den);
}
bool Fraction::operator==(float num ) const{
    Fraction temp=Fraction(num);
    
    return ( (m_num*temp.m_den) == (temp.m_num*m_den));
}
