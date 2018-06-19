#include "catch.hpp" 
#include "complex.hpp"

SCENARIO("complex new without param","[new without param]"){
    Complex complex;
    REQUIRE(complex.real() == 0);
    REQUIRE(complex.imaginary() == 0);
}

SCENARIO("complex new with pram","[new with param]"){
    Complex complex(2,-3);
    REQUIRE(complex.real() == 2);
    REQUIRE(complex.imaginary() == -3);
}

SCENARIO("complex copy","[copy]"){
    Complex complex1(2,-3);
    Complex complex2(complex1);
    REQUIRE(complex2.real() == 2);
    REQUIRE(complex2.imaginary() == -3);
}

SCENARIO("complex sum","[sum]"){
    Complex complex1(2,-3), complex2(4,2), complex3(6,-1);
    REQUIRE((complex1.add(complex2) == complex3) == true);
}

SCENARIO("complex sub","[sub]"){
    Complex complex1(2,-3), complex2(4,2), complex3(-2,-5);
    REQUIRE((complex1.sub(complex2) == complex3) == true);
}

SCENARIO("complex mul ", "[mul]") {
    Complex complex1(2, -3), complex2;
    int numbers = 2;
    complex2 = complex1.mul(numbers);
    REQUIRE(complex2.real() == 4);
    REQUIRE(complex2.imaginary() == -6);
}

SCENARIO("complex div", "[div]") {
    Complex complex1(2, -3), complex2;
    int numbers = 2;
    complex2 = complex1.div(numbers);
    REQUIRE(complex2.real() == 1);
    REQUIRE(complex2.imaginary() == -1.5);
}

SCENARIO("complex operator*","[oper*]"){
    Complex complex1(2,-3), complex2(4,2), complex3(14,-8);
    REQUIRE((complex1*complex2 == complex3) == true);
}

SCENARIO("complex operator/","[oper/]"){
    Complex complex1(-23,2), complex2(4,2), complex3(-4.4,2.7);
    REQUIRE((complex1/complex2 == complex3) == true);
}

SCENARIO("complex operator +=","[oper+=]"){
    Complex complex1(2,-3), complex2(4,2), complex3(6,-1);
    complex1 += complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator -=","[oper-=]"){
    Complex complex1(2,-3), complex2(4,2), complex3(-2,-5);
    complex1 -= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator *=","[oper-*=]"){
    Complex complex1(2,-3), complex2(4,2), complex3(14,-8);
    complex1 *= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator /=","[oper/=]"){
    Complex complex1(-23,2), complex2(4,2), complex3(-4.4,2.7);
    complex1 /= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator =","[oper=]"){
    Complex complex1(2,-3), complex2(4,2);
    complex1 = complex2;
    REQUIRE((complex1 == complex2) == true);
}

SCENARIO("complex operator ==","[oper==]"){
    Complex complex1(2,-3), complex2(2,-3);

    REQUIRE((complex1 == complex2) == true);
}
