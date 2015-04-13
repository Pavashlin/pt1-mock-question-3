///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	
	friend bool operator>(Fraction a, Fraction b);												//makes it easier to create functions
	friend Fraction add(int, Fraction);
	friend Fraction add(Fraction, int);
};

bool operator>(Fraction a, Fraction b)
{
	if (a.num*b.denom > b.num*a.denom)
	{
		return true;
	}
	else return false;
}

 Fraction add(int x, Fraction y)
{
	 int temp;
	 temp = x*y.denom;
	 y.num = y.num + temp;
	 return y;
}

 Fraction add(Fraction x, int y)
 {
	 int temp;
	 temp = y*x.denom;
	 x.num = x.num + temp;
	 return x;
 }

 int main()
 {
	 Fraction Jack(10, 9), Jill(1, 2);
	 int FatPenguin = 42;

	 Fraction hurry(1, 1), up(1, 1);

	 if (Jack > Jill)
	 {
		 cout << "It Works!" << endl;										//Jack is larger than Jill therefore if operator works the message "It works!" will be printed
	 }
	 else
	 {
		 cout << "Im a sad panda" << endl;									//prints im a sad panda if something goes wrong or if jill somehow becomes smaller than jack.
	 }
	
	 hurry = add(FatPenguin, Jill);
	 up = add(Jack, FatPenguin);
																			//demonstrates overloaded functions
	 hurry.print();
	 cout << endl;
	 up.print();

 }