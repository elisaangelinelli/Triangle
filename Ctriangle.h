/*! \file Ctriangle.h
	\brief Declaration of the general class Triangle
	\author Elisa Angelinelli

	Details.
*/


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

using namespace std;

/// @class Triangle
/// @brief an abstract base class for triangle
class Triangle {
protected:

	float sides[3];
	
	void SetSides(float s1, float s2, float s3);

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Triangle();
	Triangle(const Triangle &t);
	virtual ~Triangle();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Triangle& operator = (const Triangle &t); 
	bool operator == (const Triangle &t);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Triangle &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2);
	float GetArea(); //we can use Eulero's formula that is valid for all different types of triangle
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif