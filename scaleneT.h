/*! \file scaleneT.h
	\brief Declaration of the class ScaleneT

	Details.
*/


#ifndef SCALENET_H
#define SCALENET_H

#include <iostream>
#include "triangle.h"

using namespace std;

/// @class ScaleneT
/// @brief to manage an object with the shape of a scalene triangle
class ScaleneT : public Triangle
{
protected:

	float side1;
	float side2;
    float side3;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	ScaleneT();
	ScaleneT(float s1, float s2, float s3);
	ScaleneT(const ScaleneT &t);
	
	~ScaleneT();
	/// @}
	
	/// @name OPERATORS
	/// @{
	ScaleneT& operator=(const ScaleneT &t); 
	bool operator==(const ScaleneT &t);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const ScaleneT &t);							
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
	
	float GetArea();
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif