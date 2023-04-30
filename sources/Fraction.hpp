#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
namespace ariel{

class Fraction {
public:
    Fraction();
    Fraction(int num, int den = 1);
    Fraction(float num);
   
    friend std::ostream &operator<<(std::ostream& out_put, const Fraction& franc){
        out_put << franc.m_num << "/" << franc.m_den;
        return out_put;}
    friend std::istream &operator>>(std::istream& out_put,  Fraction& franc){
       char temp='a';
        out_put >> franc.m_num >> temp >> franc.m_den;
        return out_put;
    };
    Fraction operator+(const Fraction& other) const;
    friend Fraction operator+( const Fraction& fracconst ,float num);
    friend Fraction operator+( float num,const Fraction& fracconst );
    

    Fraction operator-(const Fraction& other) const;
    friend Fraction operator-( const Fraction& fracconst ,float num);
    friend Fraction operator-( float num,const Fraction& fracconst );

    Fraction operator*(const Fraction& other) const;
    friend Fraction operator*(float num, const Fraction& frac);
    friend Fraction operator*( const Fraction& frac,float num );

    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(const Fraction& frac, float num);
    friend Fraction operator/(float num,const Fraction& frac);

    Fraction operator++();
    Fraction operator++(int);

    Fraction operator--();
    Fraction operator--(int);

    bool operator>(const float value) ;
    bool operator>(const Fraction& other) ;
    friend bool operator>(float num,const Fraction& frac);
    friend bool operator>=(float num,const Fraction& frac);
    bool operator>=(const float value) ;
    bool operator>=(const Fraction& other) ;
    
    bool operator<(const float value) ;
    bool operator<(const Fraction& other) ;
    friend bool operator<(float num,const Fraction& frac);
    friend bool operator<=(float num,const Fraction& frac);
    bool operator<=(const float value);
    bool operator<=(const Fraction& other) ;

    bool operator==(const Fraction& other) const;
    bool operator==(float num ) const;
    Fraction reduce();
private:
    int m_num;
    int m_den;
    
    static int gcd(int num, int den);
};
}
#endif // FRACTION_HPP
