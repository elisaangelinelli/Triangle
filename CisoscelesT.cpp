/*! \file CisoscelesT.cpp
	\brief Implementation of the functions of the class Isosceles Triangle

	Details.
*/

#include <iostream>
#include "CisoscelesT.h"

/// @brief default constructor 
IsoscelesT::IsoscelesT() {

	cout << "IsoscelesT - constructor - default" << endl;
    
	Init();

}

/// @brief constructor 
/// @param s1 first side of the IsoscelesT
/// @param s2 second side of the IsoscelesT
/// @param s3 third side of the IsoscelesT
IsoscelesT::IsoscelesT(float s1, float s2, float s3) {

	Init();

	cout << "IsoscelesT - constructor" << endl;

	if (s1 <= 0. || s2 <= 0. || s3 <= 0.) {
		WarningMessage("constructor: the sides of the triangle should be > 0"); 
		SetDim(0, 0, 0);
	}
	else if (s1 > (s2+s3) || s2 > (s1+s3) || s3 > (s1+s2)){
		WarningMessage("constructor: this is not a valid triangle");
		SetDim(0, 0, 0);
	}
	else if(NotAValidIsosceles(s1, s2, s3) == false){
        WarningMessage("constructor: not valid measures for an isosceles triangle");
        SetDim(0, 0, 0);
    }
	else
		SetDim(s1, s2, s3);

}

/// @brief copy constructor 
/// @param t reference to the object that should be copied 
IsoscelesT::IsoscelesT(const IsoscelesT &t) { 

	cout << "IsoscelesT - copy constructor" << endl;

	Init(t);
	
}

/// @brief destructor 
IsoscelesT::~IsoscelesT() {

	cout << "IsoscelesT - destructor" << endl;
	Reset();

}

/// @brief overload of operator = 
/// @param t reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
IsoscelesT& IsoscelesT::operator=(const IsoscelesT &t) { 

	cout << "IsoscelesT - operator =" << endl;

	Init(t);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same sides  
bool IsoscelesT::operator==(const IsoscelesT &t) { 

	if (t.side1 == side1 && t.side2 == side2 && t.side3 == side3)
		return true;
    if (t.side1 == side1 && t.side2 == side3 && t.side3 == side2)
		return true;
    if (t.side1 == side2 && t.side2 == side3 && t.side3 == side1)
		return true;
    if (t.side1 == side2 && t.side2 == side1 && t.side3 == side3)
		return true;
    if (t.side1 == side3 && t.side2 == side1 && t.side3 == side2)
		return true;
    if (t.side1 == side3 && t.side2 == side2 && t.side3 == side1)
		return true;

	return false;
}

/// @brief default initialization of the object
void IsoscelesT::Init() {
	SetDim(0, 0, 0);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param t reference to the object that should be copied 
void IsoscelesT::Init(const IsoscelesT &t) {
	Init();
	SetDim(t.side1, t.side2, t.side3);
}

/// @brief total reset of the object  
void IsoscelesT::Reset() {
	
	SetDim(0, 0, 0);
	
}


/// @brief set first side of the object
/// @param s1 first side 
void IsoscelesT::SetFirstSide(float s1) {

	if (s1 < 0.) {
		WarningMessage("SetFirstSide: the side should be > 0");
		return;
	}

	SetDim(s1, side2, side3);

}

/// @brief set second side of the object
/// @param s2 second side 
void IsoscelesT::SetSecondSide(float s2) {

	if (s2 < 0.) {
		WarningMessage("SetSecondSide: the side should be > 0");
		return;
	}

	SetDim(side2, s2, side3);

}

/// @brief set third side of the object
/// @param s3 third side 
void IsoscelesT::SetThirdSide(float s3) {

	if (s3 < 0.) {
		WarningMessage("SetThirdSide: the side should be > 0");
		return;
	}

	SetDim(side1, side2, s3);

}


/// @brief get first side of the object
/// @return first side 
float IsoscelesT::GetFirstSide() {

	return side1;

}

/// @brief get second side of the object
/// @return second side
float IsoscelesT::GetSecondSide() {

	return side2;
}

/// @brief get third side of the object
/// @return third side
float IsoscelesT::GetThirdSide() {

	return side3;
}


/// @brief set all the sides of the object
/// @param s1 first side 
/// @param s2 second side
/// @param s3 third side
void IsoscelesT::SetDim(float s1, float s2, float s3) {
	side1 = s1;
	side2 = s2;  
    side3 = s3;
	Triangle::SetSides(s1, s2, s3);
	
	return;
}

/// @brief get all th sides of the object
/// @param s1 first side 
/// @param s2 second side
/// @param s3 third side
void IsoscelesT::GetDim(float &s1, float &s2, float &s3) {

	s1 = side1;
	s2 = side2; 
    s3 = side3;
	
	return;
}

/// @brief write an error message when the object isn't a valid isosceles triangle
/// @param s1 first side
/// @param s2 second side 
/// @param s3 third side
bool IsoscelesT::NotAValidIsosceles(float s1, float s2, float s3){
    if (s1 == s2 || s1 == s3 || s2 == s3)
        return true;

    return false;
}


/// @brief write an error message 
/// @param string message to be printed
void IsoscelesT::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- IsoscelesT --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void IsoscelesT::WarningMessage(const char *string) {
	
	cout << "WARNING -- IsoscelesT --";
	cout << string << endl;
	cout << endl;

}


/// @brief for debugging: all about the object
void IsoscelesT::Dump() {
	cout << endl;
	cout << "---IsoscelesT---" << endl; 
	cout << endl;
	
	Triangle::Dump();
	
	cout << endl;

}