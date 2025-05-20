/*! @file Exponential.cpp 
	@brief Implementation of Exponential class 
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/

#include "Exponential.h"

/// @brief default constructor
//Implementazione costruttore di default
Exponential::Exponential() {
	cout << endl << "-- Exponential -- costruttore di default --" << endl;
	Reset();
}

/// @brief constructor
///	@param b_coeff to store the base b
///	@param k_coeff to store the coefficient k
///	@param c_coeff to store the coefficient c
// Implementazione costruttore parametrico utile a inizializzare l'oggetto Exponential
Exponential::Exponential(double b_coeff, double k_coeff, double c_coeff) {
	
	cout << endl << "-- Exponential -- inizializzazione con parametri --" << endl;

	Reset();
	SetExponential(b_coeff, k_coeff, c_coeff);  // Imposta i coefficienti tramite metodo dedicato
}

/// @brief destructor
// Implementazione distruttore 
Exponential::~Exponential() {

    cout << endl << "-- Exponential -- distruttore --" << endl;
	Reset();
}

/// @brief copy constructor
/// @param E reference to the object that should be copied 
//Implementazione costruttore di copia (passo by reference un altro oggetto Exponential)
Exponential::Exponential(const Exponential& E) {

	cout << endl << "-- Exponential -- costruttore di copia --" << endl;

	SetExponential(E.b_coeff, E.k_coeff, E.c_coeff); //copia tutti i coefficienti dell'oggetto passato
}

/// @brief overload operator =
/// @param Pow reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazione operatore di assegnazione (=) --> Restituisce un riferimento all’oggetto stesso, ovvero *this.
Exponential& Exponential::operator=(const Exponential& E) {
	
	cout << endl << "-- Exponential -- operatore di assegnazione (=) --" << endl;
	
	if (this != &E) { // Protezione contro autoassegnazione --> verifica se l'oggetto corrente (this) è diverso dall'oggetto che stiamo cercando di assegnare
		SetExponential(E.b_coeff, E.k_coeff, E.c_coeff); //copia tutti i coefficienti dell'oggetto passato
    }

    return *this;//Restituisci this --> è un puntatore all'oggetto corrente, cioè l'oggetto su cui è chiamato il metodo
}

/// @brief overload of operator == 
/// @param E reference to the object on the right side of the operator 
/// @return true if the two objects have the same coefficents
// Implemenetazione operatore di comparazione (==) --> confronta se due oggetti Exponential sono uguali
bool Exponential::operator==(const Exponential& E) {
	
	cout << endl << "-- Exponential -- operatore di comparazione --" << endl;
	
	//Confronto tutti i coefficienti
	if (b_coeff != E.b_coeff) {
		return false;
	}
	if (c_coeff != E.c_coeff) {
		return false;
	}
	if (k_coeff != E.k_coeff) {
		return false;
	}

	return true; //Se va tutto bene restituisci vero
}

/// @brief sets the coefficients of the Exponential
///	@param b_coefficient to store the base b
///	@param k_coefficient to store the coefficient k
///	@param c_coefficient to store the coefficient c
//Implementazione setter dei parametri dell'oggetto Exponential --> Metodo per impostare i coefficienti di exponential
void Exponential::SetExponential(double b_coefficient, double k_coefficient, double c_coefficient) {
	// Controlla se il coefficiente b > 0, altrimenti stampa messaggio di errore e termina l'esecuzione del programma
	if (b_coeff < 0 || b_coeff == 0 ) {
		ErrorMessage("The object has coefficient b <= 0");
		exit(-1);
	}
	
	b_coeff = b_coefficient;
	k_coeff = k_coefficient;
	c_coeff = c_coefficient;
}

/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
// Implementazione getter del metodo che restituisce un double (che rappresenta il valore dell'esponenziale calcolato nel punto in)
double Exponential::GetValue(double in) {

	//Verifico se b > 0
    if (b_coeff > 0) {
        return k_coeff * (pow(b_coeff, c_coeff * in)); // --> K * [b ^ (cx)]
	}
	else {
		ErrorMessage("The object to be copied has coefficient b <= 0");
		return NAN; //invalid_argument("...");
	}
}

/// @brief resets the Exponential
// Implementazione del metodo reset --> azzera completamente lo stato interno dell' Exponential
void Exponential::Reset() {
	
	b_coeff = 1;
	k_coeff = 1;
	c_coeff = 1;
}


/// @brief writes an error message 
/// @param string message to be printed
//Stampa messaggio di errore
void Exponential::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Exponential --";
	cout << string << endl;
}


/// @brief writes a warning message 
/// @param string message to be printed
//Stampa messaggio di avviso (non viene usata ma è stata implementata nel caso in cui dovesse servire per la prossima esercitazione)
void Exponential::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Exponential --";
	cout << string << endl;
}


/// @brief gives the status of the object 
//Stampa tutte le caratteristiche dell'oggetto
void Exponential::Dump() {

	//Stampa questo se oggetto Exponential NON è inizializzato ed esci dal metodo
	if (b_coeff < 0 || b_coeff == 0) {
		cout << "Uninitialized Exponential" << endl;
		return; //esci dalla funzione
	}  

	// Stampa esplicita della funzione nella forma k * b^(c*x)
	cout << "Exponential: " << k_coeff << " * " << b_coeff << "^(" << c_coeff << "*x)" << endl;

	cout << "Base Coefficient:" << k_coeff<< endl;
	cout << "Base:" << b_coeff << endl;
	cout << "Exponent Coefficient:" << c_coeff << endl;
	cout << endl;
}