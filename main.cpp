/*! \file main.h
	\brief Short general check
	\author Elisa Angelinelli

*/


#include <iostream>
#include "CscaleneT.h"
#include "CisoscelesT.h"
#include "CequilateralT.h"

int main() {
	Triangle *A, *B, *C; 
	float s1,s2,s3;
	
	ScaleneT scalA(10, 5, 8);
    ScaleneT scalB(10, 1, 2);
	IsoscelesT isoA(3, 3, 4);
	IsoscelesT isoB(1, 2, 3);
    EquilateralT equiA(1, 1, 1);
    EquilateralT equiB( 4, 4, 5);
	
	A = &scalA;
	B = &scalB;
	C = &isoA;

	cout << endl;
	cout << "**** triangle A ****" << endl;
	A->Dump();
	cout << "**** ***** ****" << endl;
	cout << "**** triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** triangle C ****" << endl;
	C->Dump(); 
	cout << "**** ***** ****" << endl;
	
	cout << endl;
	cout << "**** scalene A ****" << endl;
	scalA.Dump();
	cout << "**** ***** ****" << endl;
	cout << "**** scalene B ****" << endl;
	scalB.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** isosceles A ****" << endl;
	isoA.Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** isosceles B ****" << endl;
	isoB.Dump();
	cout << "**** equilateral A ****" << endl;
	equiA.Dump();
	cout << "**** equilateral B ****" << endl;
	equiB.Dump();
	
	scalB = scalA;
	
	cout << endl;
	cout << "**** triangle A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	scalA.SetFirstSide(7);
	cout << endl;
	cout << "**** triangle A ****" << endl;
	A->Dump(); 
	cout << "**** ***** ****" << endl;
	cout << "**** triangle B ****" << endl;
	B->Dump(); 
	cout << "**** ***** ****" << endl;
	
	B->GetSides(s1,s2,s3);
	cout << "triangle B - sides:" << s1 << " " << s2 << " "<< s3 << endl; 
	
	C->GetSides(s1,s2,s3);
	cout << "triangle C - sides:" << s1 << " " << s2 << " "<< s3 << endl;
	
	isoA.SetThirdSide(5);
	C->GetSides(s1,s2,s3);
	cout << "triangle C - sides:" << s1 << " " << s2 << " "<< s3 << endl;

	return 0;

}