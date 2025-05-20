/*! @file CFunction.h
	@brief A virtual base class for functions of a single variable
	@author Paolo Gastaldo

	Details.
*/ 

//Guardia
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

//Classe funzione
class Function {
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Function(){};			//Costruttore
    virtual ~Function(){};	//Decostruttore --> funzione astratta
	/// @}

	/// @name GETTERS
	/// @{
	virtual double GetValue(double in)=0; //Getter del valore --> funzione astratta pura
	/// @}

	/// @name DEBUG 
	/// @{
	virtual void Dump()=0; //Dump --> funzione astratta pura
	/// @}

    
};

#endif