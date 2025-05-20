/*! @file Exponential.h 
	@brief A class for Exponential functions 
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/ 


// Guardia per evitare inclusioni multiple del file header
#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

// Inclusione delle librerie standard
#include <iostream>  // per operazioni di input/output
#include <cmath>     // per funzioni matematiche
#include <cstring>   // per operazioni su stringhe

#include "CFunction.h" //Implementazione della classe base "Function"

using namespace std;

/// @class Exponential
/// @brief to manage an object of the form:  k * b^(c*x)
// Dichiarazione della classe Exponential che eredita dalla classe Function
class Exponential: public Function {

protected:
    double b_coeff;  // Base dell'esponenziale
    double k_coeff;  // Coefficiente davanti alla base
    double c_coeff;  // Coefficiente dell'esponente

public:

    /// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Exponential();                                              // Costruttore di default
    Exponential(double b_coeff, double k_coeff, double c_coeff);// Costruttore con parametri --> inizializzo l'oggetto passando il valore dei parametri
    Exponential(const Exponential& E);                          // Costruttore di copia
    ~Exponential();                                             // Distruttore
    /// @}

    /// @name OPERATORS 
	/// @{
    Exponential& operator=(const Exponential& E);   // Operatore di assegnazione
    bool operator==(const Exponential& E);          // Operatore di comparazione
    /// @}

    /// @name BASIC HANDLING
	/// @{
    void Reset();               // Reset ai valori di default, funge anche come inizializzazione standard									
	/// @}

    /// @name GETTERS / SETTERS
	/// @{
    void SetExponential(double b_coefficient, double k_coefficient, double c_coefficient); // Setter dei coefficienti Exponential

    double GetValue(double in); // Getter del valore della funzione esponenziae dato un valore X
    /// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);     // Mostra un messaggio di errore
    void WarningMessage(const char *string);   // Mostra un messaggio di avviso
    void Dump();                               // Stampa il contenuto di exponential
	/// @}    
};

#endif // Fine guardia di inclusione