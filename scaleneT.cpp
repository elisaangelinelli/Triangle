/*! \file scaleneT.cpp
	\brief Implementation of the functions of the class Scalene Triangle

	Details.
*/

#include <iostream>
#include <math.h>
#include "scaleneT.h"

/// @brief default constructor 
ScaleneT::ScaleneT() {

	cout << "ScaleneT - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param s1 first side of the ScaleneT
/// @param s2 second side of the ScaleneT
/// @param s3 third side of the ScaleneT
ScaleneT::ScaleneT(float s1, float s2, float s3) {

	Init();

	cout << "ScaleneT - constructor" << endl;

	if (s1 <= 0. || s2 <= 0. || s3 <= 0.) {
		WarningMessage("constructor: the sides of the triangle should be > 0"); 
		SetDim(0, 0, 0);
	}
	else
		SetDim(s1, s2, s3);

}

/// @brief copy constructor 
/// @param t reference to the object that should be copied 
ScaleneT::ScaleneT(const ScaleneT &t) { 

	cout << "ScaleneT - copy constructor" << endl;

	Init(t);
	
}

/// @brief destructor 
ScaleneT::~ScaleneT() {

	cout << "ScaleneT - destructor" << endl;
	Reset();

}

/// @brief overload of operator = 
/// @param t reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
ScaleneT& ScaleneT::operator=(const ScaleneT &t) { 

	cout << "ScaleneT - operator =" << endl;

	Init(t);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same sides  
bool ScaleneT::operator==(const ScaleneT &t) { 

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
	
    //we have to include all the cases because a triangle is equal to another if they have the same sides and it doesn't matter the order of these sides

	return false;
}

/// @brief default initialization of the object
void ScaleneT::Init() {
	SetDim(0, 0, 0);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param t reference to the object that should be copied 
void ScaleneT::Init(const ScaleneT &t) {
	Init();
	SetDim(t.side1, t.side2, t.side3);
}

/// @brief total reset of the object  
void ScaleneT::Reset() {
	
	SetDim(0, 0, 0);
	
}


/// @brief set first side of the object
/// @param s1 first side 
void ScaleneT::SetFirstSide(float s1) {

	if (s1 < 0.) {
		WarningMessage("SetFirstSide: the side should be > 0");
		return;
	}

	SetDim(s1, side2, side3);

}

/// @brief set second side of the object
/// @param s2 second side 
void ScaleneT::SetSecondSide(float s2) {

	if (s2 < 0.) {
		WarningMessage("SetSecondSide: the side should be > 0");
		return;
	}

	SetDim(side2, s2, side3);

}

/// @brief set third side of the object
/// @param s3 third side 
void ScaleneT::SetThirdSide(float s3) {

	if (s3 < 0.) {
		WarningMessage("SetThirdSide: the side should be > 0");
		return;
	}

	SetDim(side1, side2, s3);

}


/// @brief get first side of the object
/// @return first side 
float ScaleneT::GetFirstSide() {

	return side1;

}

/// @brief get second side of the object
/// @return second side
float ScaleneT::GetSecondSide() {

	return side2;
}

/// @brief get third side of the object
/// @return third side
float ScaleneT::GetThirdSide() {

	return side3;
}


/// @brief set all the sides of the object
/// @param s1 first side 
/// @param s2 second side
/// @param s3 third side
void ScaleneT::SetDim(float s1, float s2, float s3) {

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
void ScaleneT::GetDim(float &s1, float &s2, float &s3) {

	s1 = side1;
	s2 = side2; 
    s3 = side3;
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float ScaleneT::GetArea() {
	//we have to use Eulero's formula
	return (sqrt((GetPerimeter()/2) * ((GetPerimeter()/2)-side1) * ((GetPerimeter()/2)-side2) * ((GetPerimeter()/2)-side3)));
}


/// @brief write an error message 
/// @param string message to be printed
void ScaleneT::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- ScaleneT --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void ScaleneT::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- ScaleneT --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void ScaleneT::Dump() {
	cout << endl;
	cout << "---ScaleneT---" << endl; 
	cout << endl;
	
	cout << "First Side = " << side1 << endl;
	cout << "Second Side = " << side2 << endl;
    cout << "Third Side = " << side3 << endl;
	
	Triangle::Dump();
	
	cout << endl;

}