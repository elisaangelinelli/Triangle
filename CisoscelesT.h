/*! \file CisoscelesT.h
	\brief Declaration of the class IsoscelesT

	Details.
*/


#ifndef ISOSCELEST_H
#define ISOSCELEST_H

#include <iostream>
#include "Ctriangle.h"

using namespace std;

/// @class IsoscelesT
/// @brief to manage an object with the shape of an isosceles triangle
class IsoscelesT : public Triangle
{
protected:

	float side1;
	float side2;
    float side3;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	IsoscelesT();
	IsoscelesT(float s1, float s2, float s3);
	IsoscelesT(const IsoscelesT &t);
	
	~IsoscelesT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	IsoscelesT& operator=(const IsoscelesT &t); 
	bool operator==(const IsoscelesT &t);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const IsoscelesT &t);							
	void Reset();												
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetFirstSide(float s1);
	void SetSecondSide(float s2);
    void SetThirdSide(float s3);
	void SetDim(float s1, float s2, float s3);
	
	void GetDim(float &s1, float &s2, float &s3);
	float GetFirstSide();
	float GetSecondSide();
    float GetThirdSide(); 
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
    virtual bool NotAValidIsosceles(float s1, float s2, float s3);
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif