/*! @file Power.cpp 
	@brief Implementation of Power class 
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/

#include "Power.h" 

/// @brief default constructor
//Implementazione costruttore di default
Power::Power() {
	cout << endl << "-- Power -- costruttore di default --" << endl;
	SetPower(0, 0);
}

/// @brief constructor
///	@param e_coeff to store the coefficient e
///	@param k_coeff to store the coefficient k
// Implementazione costruttore parametrico utile a inizializzare l'oggetto Power
Power::Power(double e_coeff, double k_coeff) {
	
	cout << endl << "-- Power -- inizializzazione con parametri --" << endl;
	
	SetPower(0, 0);
	SetPower(e_coeff, k_coeff);
}

/// @brief copy constructor
/// @param Pow reference to the object that should be copied 
//Implementazione costruttore di copia (passo by reference un altro oggetto Power)
Power::Power(const Power& Pow) {
	
	cout << endl << "-- Power -- costruttore di copia --" << endl;
	
	SetPower(Pow.e_coeff, Pow.k_coeff);
}

/// @brief destructor
// Implementazione distruttore
Power::~Power() {
	
	cout << endl << "-- Power -- distruttore --" << endl;
	
	SetPower(0, 0);
}

/// @brief overload operator =
/// @param Pow reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazione operatore di assegnazione (=) --> Restituisce un riferimento all’oggetto stesso, ovvero *this.
Power& Power::operator=(const Power& Pow) {
	
	if (this != &Pow) {	// Protezione contro autoassegnazione --> verifica se l'oggetto corrente (this) è diverso dall'oggetto che stiamo cercando di assegnare

		e_coeff = Pow.e_coeff;
		k_coeff = Pow.k_coeff;
    }

    return *this; 
}

/// @brief overload of operator == 
/// @param Pow reference to the object on the right side of the operator 
/// @return true if the two objects have the same coefficients
// Implemenetazione operatore di comparazione (==) --> confronta se due oggetti Power sono uguali
bool Power::operator==(const Power& Pow) {
	
	cout << endl << "-- Power -- operatore di comparazione --" << endl;

	//Verifico se i coefficienti
	if (e_coeff != Pow.e_coeff) {
		return false;
	}
	if (k_coeff != Pow.k_coeff) {
		return false;
	}

	return true;
}

/// @brief sets the coefficients of the Power 
///	@param e_coefficients to store the coefficient e
///	@param k_coefficients to store the coefficient k
//Implementazione setter dei parametri dell'oggetto power --> Metodo per impostare i coefficienti della potenza
void Power::SetPower(double e_coefficient, double k_coefficient) {

	e_coeff = e_coefficient;
	k_coeff = k_coefficient;
}

/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
// Implementazione getter del metodo che restituisce un double (che rappresenta il valore della potenza calcolata nel punto in)
double Power::GetValue(double in){
	
	// Impedisce la forma indeterminata 0^0
	if (in == 0 && e_coeff == 0){
		ErrorMessage (" An indeterminate form of the type 0^0");
		return NAN;
	}

	return k_coeff * pow(in, e_coeff);	// --> k * [x^e]
}


/// @brief writes a warning message 
/// @param string message to be printed
//Stampa messaggoi di avviso
void Power::WarningMessage(const char *string){

	cout << endl << "WARNING -- Power --";
	cout << string << endl;
}


/// @brief writes an error message 
/// @param string message to be printed
//Stampa messaggio di errore
void Power::ErrorMessage(const char *string){

	cout << endl << "ERROR -- Power --";
	cout << string << endl;
}


/// @brief gives the status of the object 
//Stampa tutte le caratteristiche dell'oggetto
void Power::Dump(){

	cout << "Power:" << k_coeff << "*x^" << e_coeff << endl << endl;
	cout << "Base Coefficient(k):" << k_coeff<< endl;
	cout << "Exponent(e):" << e_coeff << endl;
}