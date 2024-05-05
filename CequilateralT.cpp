/*! \file CequilateralT.cpp
	\brief Implementation of the functions of the class Isosceles Triangle

	Details.
*/

#include <iostream>
#include "CequilateralT.h"

/// @brief default constructor 
EquilateralT::EquilateralT() {

	cout << "EquilateralT - constructor - default" << endl;
    
	Init();

}

/// @brief constructor 
/// @param s1 first side of the EquilateralT
/// @param s2 second side of the EquilateralT
/// @param s3 third side of the EquilateralT
EquilateralT::EquilateralT(float s1, float s2, float s3) {

	Init();

	cout << "EquilateralT - constructor" << endl;

	if (s1 <= 0. || s2 <= 0. || s3 <= 0.) {
		WarningMessage("constructor: the sides of the triangle should be > 0"); 
		SetDim(0, 0, 0);
	}
    else if (s1 > (s2+s3) || s2 > (s1+s3) || s3 > (s1+s2)){
		WarningMessage("constructor: this is not a valid triangle");
        SetDim(0, 0, 0);
	}
	else if(NotAValidEquilateral(s1, s2, s3) == false){
        WarningMessage("constructor: not valid measures for an equilateral triangle");
        SetDim(0, 0, 0);
    }
    else
		SetDim(s1, s2, s3);

}

/// @brief copy constructor 
/// @param t reference to the object that should be copied 
EquilateralT::EquilateralT(const EquilateralT &t) { 

	cout << "EquilateralT - copy constructor" << endl;

	Init(t);
	
}

/// @brief destructor 
EquilateralT::~EquilateralT() {

	cout << "EquilateralT - destructor" << endl;
	Reset();

}

/// @brief overload of operator = 
/// @param t reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
EquilateralT& EquilateralT::operator=(const EquilateralT &t) { 

	cout << "EquilateralT - operator =" << endl;

	Init(t);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same sides  
bool EquilateralT::operator==(const EquilateralT &t) { 

	if (t.side1 == side1)
        return true; //we only need this because every other side is equal to these

	return false;
}


/// @brief write an error message when the object isn't a valid isosceles triangle
/// @param s1 first side
/// @param s2 second side 
/// @param s3 third side
bool EquilateralT::NotAValidEquilateral(float s1, float s2, float s3){
    if (s1 == s2 && s2 == s3)
        return true;

    return false;
}


/// @brief write an error message 
/// @param string message to be printed
void EquilateralT::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- EquilateralT --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void EquilateralT::WarningMessage(const char *string) {
	
	cout << "WARNING -- EquilateralT --";
	cout << string << endl;
    cout << endl;

}


/// @brief for debugging: all about the object
void EquilateralT::Dump() {
	cout << endl;
	cout << "---EquilateralT---" << endl; 
	cout << endl;

	Triangle::Dump();
	
	cout << endl;

}