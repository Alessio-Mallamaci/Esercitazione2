/*! @file Power.h
    @brief A class for power functions
    @author Alessio Mallamaci e Alessio Pedretti

    Details.
*/

//Guardia
#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

/// @class Power
/// @brief to manage an object of the form:  k * x^e
//Dichiarazione della classe derivata Power
class Power : public Function {

protected:
	double k_coeff;  // Coefficiente moltiplicativo
    double e_coeff;  // Esponente

public:
    /// @name CONSTRUCTORs and DESTRUCTOR
    /// @{
    Power();                                    // Costruttore di default
    Power(double e_coeff, double k_coeff);      // Costruttore parametrico
    Power(const Power& Pow); 	                //Costruttore di copia
    ~Power();                                   // Distruttore
    /// @}

	
    /// @name OPERATORS 
	/// @{
    Power& operator=(const Power& Pow);     //Operatore di assegnazione
	bool operator==(const Power& Pow); 		//Operatore di comparazione
	/// @}    

    /// @name GETTERS / SETTERS
	/// @{
    void SetPower(double e_coefficient, double k_coefficient);  //Setter dei coefficienti della funzine esponenziale
    double GetValue(double in);							        // Calcola il valore della potenza per un certo input
	/// @}

    /// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);     // Mostra un messaggio di errore
    void WarningMessage(const char *string);   // Mostra un messaggio di avviso
    void Dump();                               // Stampa il contenuto dellla potenza
	/// @} 

};

#endif