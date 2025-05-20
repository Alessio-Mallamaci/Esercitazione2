/*! @file Polynomial.cpp 
	@brief Implementation of Polynomial class 
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/

#include "Polynomial.h"

/// @brief default constructor
//Implementazione costruttore di default
Polynomial::Polynomial() {
	cout << endl << "-- Polynomial -- costruttore di default --" << endl;
	Init() ; 							
}

/// @brief constructor
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
// Implementazione costruttore parametrico utile a inizializzare l'oggetto Polynomyal passando l'array dei coefficienti e le dimensioni
Polynomial::Polynomial(const double* coefficients, int size) {
	
	cout << endl << "-- Polynomial -- inizializzazione con parametri --" << endl;
	Init() ; 							

    SetPolynomial(coefficients, size);  // Imposta i coefficienti tramite metodo dedicato
}

/// @brief destructor
// Implementazione distruttore --> Libera memoria dinamica per evitare errore di "memory leak"
Polynomial::~Polynomial() {
    cout << endl << "-- Polynomial -- distruttore --" << endl;
	Reset(); 
}

/// @brief copy constructor
/// @param p reference to the object that should be copied 
//Implementazione costruttore di copia (passo by reference un altro oggetto Polynomial)
Polynomial::Polynomial(const Polynomial& p) {
	
	cout << endl << "-- Polynomial -- costruttore di copia --" << endl;
	
	int i; //Inizializzo varaibile contatore utilizzata per il ciclo for
	
	// Controlla se l'oggetto passato ha dei coefficienti, altrimenti stampa messaggio di errore e termina l'esecuzione del programma
	if (p.coeff == NULL) {
		ErrorMessage("Copy constructor: the object to be copied has no coefficients");
		exit(-1);
	}
	degree = p.degree; // Copia il grado del polinomio passato
	

	coeff = new double[degree + 1]; // Alloca dinamicamente spazio in memoria per i nuovi coefficienti
	// Controlla se il puntatore del coefficiente del polinomio punta a qualcosa, altrimenti stampa messaggio di errore ed esce dal programma
	if (coeff == NULL) {
		ErrorMessage("Copy constructor: cannot allocate memory");
		exit(-1);
	}
	
	// Copia i coefficienti del polinomio passato
    for (i=0; i<=degree; i++)
		coeff[i]= p.coeff[i];
}


/// @brief overload operator =
/// @param p reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazione operatore di assegnazione (=) --> Restituisce un riferimento all’oggetto stesso, ovvero *this.
Polynomial& Polynomial::operator=(const Polynomial& p) {
    
	cout << endl << "-- Polynomial -- operatore di assegnazione (=) --" << endl;
	int i; //Inizializzo varaibile contatore utilizzata per il ciclo for
	
	if (this != &p) { // Protezione contro autoassegnazione --> verifica se l'oggetto corrente (this) è diverso dall'oggetto che stiamo cercando di assegnare

		// Controlla se l'oggetto corrente (this) ha già un array di coefficienti allocato e nel caso lo dealloca
		if (coeff != NULL)
			delete coeff;

        degree = p.degree; // Il grado del polinomio corrente (this) viene impostato uguale al grado del polinomio p


        coeff = new double[degree + 1]; //Alloca dinamicamente un nuovo array di coefficienti per l'oggetto corrente
		
		//  Controlla se l'allocazione dinamica dell'array di coefficienti è fallita, nel caso stampa messaggio di errore e termina il programma
		if (coeff == NULL) { 
			ErrorMessage("Operator =: cannot allocate memory");
			exit(-1);
		}

		// Ciclo che copia i coefficienti da p all'oggetto corrente (this):
        for (i=0; i<=degree; i++)
			coeff[i]= p.coeff[i];
    }

    return *this; //Restituisci this --> è un puntatore all'oggetto corrente, cioè l'oggetto su cui è chiamato il metodo
}


/// @brief overload of operator == 
/// @param p reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
// Implemenetazione operatore di comparazione (==) --> confronta se due oggetti polinomio sono uguali
bool Polynomial::operator==(const Polynomial& p) {
	
	cout << endl << "-- Polynomial -- operatore di comparazione --" << endl;

	int i; //Inizializzo variabile contatore utilizzata per il ciclo for
	
	//Confronta se sono dello stesso grado
	if (degree != p.degree)
		return false;
	
	//Confronta se ogni singolo coefficiente è uguale
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true; //Se va tutto bene restituisci vero
}


/// @brief sets the coefficients of the polynomial 
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
//Implementazione setter dei parametri dell'oggetto polinomio --> Metodo per impostare i coefficienti del polinomio
void Polynomial::SetPolynomial(const double* coefficients, int size) {

	int i; //Inizializzo variabile contatore utilizzata per il ciclo for 
	
	// Verifico che la dimensione dell'array sia >=1
	if (size < 1) {
		ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
		exit(-1);
	}
	
	// Se l’oggetto Polynomial su cui è chiamato il metodo ha già dei coefficienti allocati: chiama Reset() per liberare memoria e azzerare il grado, così si evita un memory leak.
	if (coeff != NULL)
		Reset();
	
	
	degree= size - 1; 			// Imposta il grado del polinomio
    coeff = new double[size];	// Alloca dinamicamente un nuovo array di double per contenere i coefficienti.

	// Controllo di sicurezza in caso di fallimento dell’allocazione.
	if (coeff == NULL) {
		ErrorMessage("SetPolynomial: cannot allocate memory");
		exit(-1);
	}
	
	// Copia uno ad uno tutti i coefficienti passati come parametro
	for (i=0; i<=degree; i++)
		coeff[i]= coefficients[i];
}


/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
// Implementazione getter del metodo che restituisce un double (che rappresenta il valore del polinomio calcolato nel punto in)
double Polynomial::GetValue(double in) {
        
		int i;					//Inizializzo variabile contatore utilizzata per il ciclo for 
		double x = in;			//Inizializza x con il valore dell’input in.
		double result = 0.0;	//Inizializza la variabile result, che conterrà il valore finale del polinomio valutato in x
        
		result = coeff[0]; 		//Il primo termine del polinomio è il termine noto, quindi viene assegnato direttamente al risultato iniziale
		
		//Ciclo che somma tutti i coefficienti a punto X elevato al corrsipettivo grado
		for (i=1; i<=degree; i++) {
			result += coeff[i]*x;
			x *= in;			/* x^i */
		}
        
		return result; //restituisce il valore del risultato
}

/// @brief default initialization of the object
//Implementazione inizializzazione standard
void Polynomial::Init() {

	degree = -1;      // Indica un polinomio non inizializzato (grado = -1)
    coeff = NULL;     // Nessun coefficiente allocato
}


/// @brief resets the polynomial 
// Implementazione del metodo reset --> azzera completamente lo stato interno del polinomio
void Polynomial::Reset() {
	
	degree = -1; //Imposta il grado del polinomio a -1, che è un valore sentinella per indicare che il polinomio è non inizializzato o vuoto.))
	
	// Controlla se l’array coeff è già stato allocato in memoria --> Se è diverso da NULL, significa che contiene dei coefficienti validi da deallocare.
	if (coeff != NULL) {
		delete coeff; //Dealloca memoria
		coeff = NULL; //Imposta il puntatore a NULL
	}
}


/// @brief writes an error message 
/// @param string message to be printed
//Stampa messaggio di errore
void Polynomial::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Polynomial --";
	cout << string << endl;
}


/// @brief writes a warning message 
/// @param string message to be printed
//Stampa messaggoi di avviso
void Polynomial::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Polynomial --";
	cout << string << endl;
}


/// @brief gives the status of the object 
//Stampa tutte le caratteristiche dell'oggetto
void Polynomial::Dump() {

	int i;
	
	//Stampa questo se oggetto polinomio NON inizializzato ed esci dal metodo
	if (degree == -1) {
		cout << "Uninitialized polynomial" << endl;
		return;
	}
	
	//Stampa questo se oggetto polinomio NON ha coefficienti disponibili ed esci dal metodo
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "No coefficients available" << endl;
		return;
	}
	
	//Ciclo for che attraversa tutti i coefficienti del polinomio, dall'indice 0 fino al grado massimo
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) { 											//Viene stampato solo se il coefficiente è diverso da 0, in modo da non visualizzare termini nulli
			cout << (coeff[i] > 0 && i > 0 ? " +" : " ") << coeff[i];	//Stampa il coefficiente con il formato corretto: Se il coefficiente è positivo e non è il primo termine (i > 0), stampa " +" Altrimenti stampa solo " " (per il primo termine o per numeri negativi) poi stampa il valore del coefficiente stesso
                if (i > 0) { 											//Se l’indice è maggiore di 0, vuol dire che stiamo stampando un termine con la variabile x 
                    cout << "x";										
                    if (i > 1) 											//Se l’esponente è maggiore di 1, stampa anche l’esponente in forma esplicita.
                        cout << "^" << i;							
                }
        }
    }
	cout << endl;
}