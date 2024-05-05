/*! \file CequilateralT.h
	\brief Declaration of the class EquilateralT

	Details.
*/


#ifndef EQUILATERALT_H
#define EQUILATERALT_H

#include <iostream>
#include "CisoscelesT.h"

using namespace std;

/// @class EquilateralT
/// @brief to manage an object with the shape of an equilateral triangle
class EquilateralT : public IsoscelesT
{
protected:

	float side1;
	float side2;
    float side3;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	EquilateralT();
	EquilateralT(float s1, float s2, float s3);
	EquilateralT(const EquilateralT &t);
	
	~EquilateralT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	EquilateralT& operator=(const EquilateralT &t); 
	bool operator==(const EquilateralT &t);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
    bool NotAValidEquilateral(float s1, float s2, float s3);
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif