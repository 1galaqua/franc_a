#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("creat Fraction"){

    CHECK_NOTHROW(Fraction f1(1,2));
    CHECK_NOTHROW(Fraction f2(1,3));
    CHECK_THROWS(Fraction(5,0));
    
}

TEST_CASE("EQ operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(6,12);
    CHECK_EQ(f1,f2);
    CHECK_EQ(f1,0.5);
    CHECK_EQ(0.5,f1);
    CHECK_EQ(0.500,f1);
}
TEST_CASE("ADD operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(6,12);
    Fraction f4=Fraction(7,6);
    CHECK_EQ(f1+f2,1);

    Fraction f3=f1+f2;

    CHECK_EQ(f3+0.2,1.2);

    CHECK_EQ(0.2+f3,1.2);
    CHECK_EQ(f4+f2,f1+Fraction(7,6));
}
TEST_CASE("sum operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(1,4);
    CHECK_EQ(f1-0.25,f2);
    CHECK_EQ(f1-f2,0.25);
    CHECK_EQ(f2-f1,-0.25);
    CHECK_EQ(f1-f2,f2);
}
TEST_CASE("mul operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(8,12);
    Fraction f3 =Fraction(15,10);
    CHECK_EQ(f1*0.5,0.25);
    CHECK_EQ(f1*f2,Fraction(1,3));
    CHECK_EQ(0.5*f1,0.25);
    CHECK_EQ(f2*f3,1);
}
TEST_CASE("G/GE operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(7,12);
    Fraction f3=Fraction(8,17);
    Fraction f4=Fraction(19,15);
    Fraction f5=Fraction(1,3);
    Fraction f6=Fraction(1,15);
    CHECK_EQ( (f1 >= f3),true);
    CHECK_EQ((f1>0.4),true);
    CHECK_EQ((0.522>f1),true);

    CHECK_EQ((f2>f5),true);
    CHECK_EQ((f3>=f6),true);
    CHECK_EQ((f4>=f2),true);
    CHECK_EQ((0.500>=f1),true);
}
TEST_CASE("L/LE operator"){
    Fraction f1=Fraction(1,2);
    Fraction f2=Fraction(7,12);
    Fraction f3=Fraction(8,17);
    Fraction f4=Fraction(19,15);
    Fraction f5=Fraction(1,3);
    Fraction f6=Fraction(1,15);
    CHECK_EQ( (f1 <= f3),false);
    CHECK_EQ((f1<0.4),false);
    CHECK_EQ((0.522<f1),false);

    CHECK_EQ((f2<f5),false);
    CHECK_EQ((f3<=f6),false);
    CHECK_EQ((f4<=f2),false);
    CHECK_EQ((0.500<=f1),true);
}