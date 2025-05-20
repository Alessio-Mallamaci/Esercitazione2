
/*! @file Polynomial.h 
	@brief A class for Polynomial functions 
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/ 

//GUARDIA --> per non definirlo + volte all'interno del programma
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>   // Per operazioni di input/output (es. cout)
#include <cmath>      // Per operazioni matematiche (anche se non usata qui direttamente)
#include <cstring>    // Per funzioni C-style su stringhe (non usata direttamente)

#include "CFunction.h" //Implementazione della classe base "Function"

using namespace std;

/// @class Polynomial
/// @brief to manage an object of the form:  format: c0+c1*x+ ...
//Dichiarazione della classe derivata Polynomial
class Polynomial: public Function 
{
protected:
	double* coeff; 	//puntatore all'array dei coefficienti
    int degree; 	//grado del polinomio

public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Polynomial(); 										//Costruttore di default
	Polynomial(const double* coefficients, int size); 	//Costruttore parametrico (array di coefficienti e dimensione dell'array) --> istanzio oggetto con parametri che gli fornisco io
    Polynomial(const Polynomial& p); 					//Costruttore di copia (passaggio dell'oggetto by reference)
    ~Polynomial(); 										//Distruttore (distrugge tutto una volta uscito dallo scope)
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p); //Operatore di assegnazione
	bool operator==(const Polynomial& p); 		//Operatore di comparazione
	/// @}

    /// @name BASIC HANDLING
	/// @{
    void Init();				// Inizializzazione standard
	void Reset();               // Reset ai valori di default											
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetPolynomial(const double* coefficients, int size); 	// Setter dei coefficienti del polinomio
    
    double GetValue(double in);							// Calcola il valore del polinomio per un certo input
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);     // Mostra un messaggio di errore
    void WarningMessage(const char *string);   // Mostra un messaggio di avviso
    void Dump();                               // Stampa il contenuto del polinomio
	/// @}    
};

#endif