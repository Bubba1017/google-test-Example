#include "pch.h"
//#include "gtest/gtest.h" // this is included in the pch.h file.
#include "sample1.h"
#include <iostream>
#include <stdio.h>
using namespace std;

/*
This is just an example of using google test within a C++ source
file. The functions are classes shown could be made more robust
but I created these only for the puprose of creating examples
using google test and Visual Studio 2017. You could do the same
with google test only loaded on your machine buit like the debugging
capabilities of Visual Studio.  This code is not copyrighted so feel
free use any or all it.

I like to comment my code as you see, just because if I come back to
it much later I have an easier time understanding what I did, or if
someone else needs to read it they can better understand what was done.

My general rule for comments is more is always better because I have
reverse engineered many a program that had very few comments. Even the
simplest things that you explaim what was doen and why goes a long 
way to maintaining code.

As a reminder, in programming, there are always many different ways
to generate the output and perform the same functions! 

*/

/********************   Using Functions ************************/
//
//******************* Factorial Function
//
// Returns nbr! (the factorial of nbr).  
// For all negatives and non-facotorials, result returned as a 1.
// Note this could be put into class or made more robust but 
// this is just an example to use for testing.
double Factorial(double nbr) {
    double result = 1;
    for (double ndx = 1; ndx <= nbr; ndx++) {
        result *= ndx;
    }
return result;
}

//
//******************* Prime Number 
//
// This function returns true if the number passed in is a prime number.
// Note this could be put into class but this is just an example.
bool IsPrime(int nbr) {
    if (nbr <= 1) return false;         // No can do if a number is less than 1
    if (nbr % 2 == 0) return nbr == 2;  // If and even number divisable by 2, not a potential prime
    // Now, we know that nbr is odd and nbr >= 3.
    // Next action is to try and divide nbr by every odd number
    // Try to divide nbr by every odd number oddNbr, starting from 3
    for (int oddNbr = 3; ; oddNbr += 2) {
        if (oddNbr > nbr / oddNbr) break; // do odd numbers only up to the sq. root of nbr

        // the oddNbr is now <= nbr/oddNbr < nbr.
        // and if nbr is divisible by oddNbr at this point, the nbr is not a prime
        if (nbr % oddNbr == 0) return false;
    }
    // at this point nbr is a prime number so let them know.
    return true;
}

//
/********************   Using Classes ************************/
//
//******************* Circle Class
//
// This Class is used to calculate the circumference or area of a circle
// given the radius. The class is initialized with a radius value when
// instantiated (which could be done in different ways).
class Circle {
    double radius;
public:
    
    //Constructor with a value to initialize the radius
    Circle(double r) { radius = r; }
    
    // Public methods 
    double circum() { return 2 * 3.14159265* radius; }
    double area() { return 3.14159265 * (radius * radius); }
    void setRadius(double rad) { radius = rad; }

};

//
//*******************  Class Cylinder
//
// This class is used to calculate the volume of a cylinder 
// given the radius and height variables 
class Cylinder {
    Circle base; // create a circle so we have a base to work from.
    double height;
public:
    // Constructor and initialization
    Cylinder(double r, double h) : base(r), height(h) {}

    // public methods
    double volumne() { return base.area() * height; }
    void setHeight(double h) { height = h;}
    void setBase(double b) { base = b;}
};

//
//******************* Class BoxSize
//
// Initialized with the length and width it calculates
// the area of the box.
class BoxSize {
    double length;
    double width;
public:
    // Constructor.
    BoxSize(double l, double w) : length(l), width(w) {}
        
    // public methods.
    // note: You could adjust for negative numbers by using abs().
    double area() { return (length*width); }
    void setLength(double len) { length = len; }
    void setWidth(double wid) { width = wid; }
};

/**********************************************************/
/********************   Test Cases ************************/
/**********************************************************/
// These are simple test cases and unit tests that test the
// various functions and class members. Kept them simple
// for example purposes only. There are probably different
// ways and many enhancements but I just wanted to show
// structure and how things worked in google test.
TEST(FactorialTests, SomeNumbers) {
    EXPECT_FLOAT_EQ(6.0, Factorial(3.0));
    EXPECT_FLOAT_EQ(720.0, Factorial(6.0));
    EXPECT_FLOAT_EQ(6, Factorial(3.0));
    EXPECT_FLOAT_EQ(3628800.0, Factorial(10.0));
}
TEST(FactorialTests, InvalidNumbers) {
    EXPECT_FLOAT_EQ(1.0, Factorial(0.0)); // invalid number returns 1
    EXPECT_FLOAT_EQ(1.0, Factorial(-3.0)); // invalid number returns 1
}
// Just an example of some primes and not so prime numbers
TEST(PrimeNbrTests, PositiveNumbers) {
    EXPECT_EQ(true, IsPrime(2));
    EXPECT_EQ(true, IsPrime(3));
    EXPECT_EQ(true, IsPrime(5));
    EXPECT_EQ(true, IsPrime(47));
    EXPECT_EQ(true, IsPrime(167));
//Now non-prime numbers 
    EXPECT_EQ(false, IsPrime(0));
    EXPECT_EQ(false, IsPrime(4));
    EXPECT_EQ(false, IsPrime(18));
    EXPECT_EQ(false, IsPrime(54));
    EXPECT_EQ(false, IsPrime(141));

}
// Don't need to do all these but did some just
// as an example.
TEST(PrimeNbrTests, NegativeNumbers) {
    EXPECT_EQ(false, IsPrime(-1));
    EXPECT_EQ(false, IsPrime(-3));
    EXPECT_EQ(false, IsPrime(-5));
    EXPECT_EQ(false, IsPrime(-47));
    EXPECT_EQ(false, IsPrime(-167));
    //Now non-prime numbers
    EXPECT_EQ(false, IsPrime(-0));
    EXPECT_EQ(false, IsPrime(-4));
    EXPECT_EQ(false, IsPrime(-18));
    EXPECT_EQ(false, IsPrime(-54));
    EXPECT_EQ(false, IsPrime(-141));
}
TEST(CircleTests, PositiveRadius) {
    Circle TestCircle(0.0);
    EXPECT_FLOAT_EQ(0.0, TestCircle.circum());
    TestCircle.setRadius(6.0);
    EXPECT_FLOAT_EQ(37.6991, TestCircle.circum());
    TestCircle.setRadius(100.0);
    EXPECT_FLOAT_EQ(628.3185, TestCircle.circum());

}
TEST(CircleTests, NegativeRadius) {
    Circle TestCircle(0.0);
    EXPECT_FLOAT_EQ(0.0, TestCircle.circum());
    TestCircle.setRadius(-6.0);
    EXPECT_FLOAT_EQ(-37.6991, TestCircle.circum());
    TestCircle.setRadius(-100.0);
    EXPECT_FLOAT_EQ(-628.3185, TestCircle.circum());
}

TEST(CylinderVolmneTests, PostiveNumbers) {
    Cylinder myCylinder(0, 0);
    EXPECT_FLOAT_EQ(0.0, myCylinder.volumne());
    myCylinder.setBase(10.0);
    EXPECT_FLOAT_EQ(0.0, myCylinder.volumne());
    myCylinder.setHeight(10.0);
    EXPECT_FLOAT_EQ(3141.5925, myCylinder.volumne());
    myCylinder.setBase(32.5);
    myCylinder.setHeight(12.9);
    EXPECT_FLOAT_EQ(42806.164, myCylinder.volumne());
}

TEST(CylinderVolmneTests, NegativeNumbers) {
    Cylinder myCylinder(-0, -0);
    EXPECT_FLOAT_EQ(0.0, myCylinder.volumne());
    myCylinder.setBase(-10.0);
    EXPECT_FLOAT_EQ(0.0, myCylinder.volumne());
    myCylinder.setHeight(-10.0);
    EXPECT_FLOAT_EQ(-3141.5925, myCylinder.volumne());
    myCylinder.setBase(-32.5);
    myCylinder.setHeight(-12.9);
    EXPECT_FLOAT_EQ(-42806.164, myCylinder.volumne());
}

/********************   Main Function  ************************/
int main(int argc, char* argv[]) {

    // Some variables to try different numbers with
    double Factorialnbr = 3.0;
    int primeNbr = 7;

    // Class creatations and initializations
    BoxSize myBox(10, -20.4); // Create the box size
    Circle myCircle(35.0); // Create and Initialize using constructur. 
    myCircle.setRadius(6.0); // example to reset radius if needed.
    Cylinder myCylinder(20, 45); // Create and Initialize myCylinder
    // Now before all the tests are run below, 
    // show results using printf here.
    printf("\n\n************************************\n");
    printf("1. MyBox area results %4.3f \n", myBox.area());
    printf("2. MyCircle circumference %4.3f \n", myCircle.circum());
    printf("3. MyCylinder Volumne %4.3f \n", myCylinder.volumne());
    if (IsPrime(primeNbr) == true)
        printf("4. This number is a prime number! %i \n", primeNbr);
    else
        printf("4. This number is NOT a prime number! %i \n", primeNbr);
    printf("5. Factorilal of %4.2f is %f \n",Factorialnbr, Factorial(Factorialnbr));
    printf("\n************************************\n\n");

    // And as an example, you can use the cout i/o function as well  
    // to see the same thing.
    cout << "6. MyBox area is: " << myBox.area() << '\n';
    cout << "7. MyCircle circumference is: " << myCircle.circum() << '\n';
    cout << "8. myCylinder volumne is: " << myCylinder.volumne() << '\n';
    cout << "9. Factorial nbr is: " << Factorial(Factorialnbr) << '\n';
    
    printf("************************************\n\n");

    // Now we are going to run all the tests. These too will be shown shown in
    // the output screen when you run the program as an application and
    // not running the tests only in the "Test Expolorer" window.
    // If you run the tests only by using the "Run All" option
    // in the Visual Studio Test Explorer window then the application
    // items above are not run. This then allows you bypass all the
    // executible code above in main.
    testing::InitGoogleTest(&argc, argv);   // initialize test environment
    return RUN_ALL_TESTS();                 // and run all the tests.


    //hold the command window output display until a character is entered.
    // char a;
    //cin >> a;

    return 0;
}
