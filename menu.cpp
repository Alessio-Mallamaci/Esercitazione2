
/*! @file menu.cpp
	@brief Implements a menu system to manage and evaluate mathematical functions (Polynomial, Exponential, and Power).
	@author Alessio Mallamaci e Alessio Pedretti

	Details.
*/

#include <sstream>
#include "Polynomial.h"      // Include l'intestazione per la classe Polynomial
#include "Exponential.h"     // Include l'intestazione per la classe Exponential
#include "Power.h"           // Include l'intestazione per la classe Power
#include "CFunction.h"       // Include l'intestazione per la classe base Function

#include "menu.h"            // Include l'intestazione per la gestione del menu delle funzioni

/// @brief Exit the menù
/// @param vec Reference to the vector of pointers to Function objects.
// 0 – Funzione per uscire dal menù e deallocare tutta la memoria
vector <Function *> exitMenu(vector<Function *> &vec) {

	for(int i = 0; i < vec.size(); i++) {   	// Ciclo per eliminare tutte le funzioni
        delete vec[i];							// Elimina ogni funzione dal vettore
    }
    vec.erase(vec.begin(), vec.end());  		// Rimuove tutte le funzioni dal vettore
    return vec;
	
}


/// @brief Display the list of functions
/// @param vec Reference to the vector of pointers to Function objects.
// 1 – Funzione per stampare tutte le funzioni contenute nel vettore `vec`
void printFunc(vector <Function *> &vec) {

	if (vec.size() < 1)	{							// Se il vettore è vuoto
		cout << "No function found!" << endl;		// Stampa un messaggio
	} else {
		for (int i = 0; i < vec.size(); i++) {		// Itera su ogni funzione nel vettore
			vec[i]->Dump();							// Chiama il metodo `Dump()` per stampare i dettagli della funzione
			cout << "ID number : " << i << endl;	// Stampa l'ID della funzione
			cout << "------------------------------------------------------------" << endl;
		}
	}
	return;
}


/// @brief Inserts a new function into the vector based on user input.
/// @param vec Reference to the vector of pointers to Function objects.
/// @return Updated vector containing the new function.
// 2 – Funzione per inserire una nuova funzione nel vettore `vec`
vector <Function *> insertFunc(vector<Function *> &vec) {

	int func;		// Variabile per memorizzare la scelta dell'utente riguardo al tipo di funzione

	cout << "0 - Polynomial;" << endl;
	cout << "1 - Exponential;" << endl;
	cout << "2 - Power;" << endl;
	cout << "[Any other key] - Exit insertion menu." << endl;
	cout << "Please input associated function number : ";
	cin >> func;	// Legge la scelta dell'utente

	
	// Verifico se l'input è un intero valido
	if(!verifyInput() || func < 0 || func > 2) {
		cout << "The input must be an integer between 0 and 2." << endl;
		return vec;
	}

	// Se il controllo dell input va a buon fine, a seconda della scelta dell'utente, inserisce un tipo di funzione diverso nel vettore
	switch(func) {

	case 0 :	// Caso per inserire una funzione Polynomial
	{
		int n_coeff;				// Variabile per il numero di coefficienti
		bool n_coeff_flag = true;	// Flag per assicurarsi che l'input sia valido

		while(n_coeff_flag == true) {
			cout << "Please insert number of coefficients : ";
			cin >> n_coeff;		   	// Legge il numero di coefficienti

			// Verifico se l'input è un intero valido
			if(!verifyInput() || n_coeff < 1 ) {
				cout << "The input must be an integer greater than 0." << endl;
				n_coeff = 0;	
			}
			else {
				n_coeff_flag = false;
			}
		}
			
		double* coeff = new double[n_coeff + 1];						// Alloca dinamicamente un array di coefficienti
		cout << "Please insert coefficients : " <<endl ;
		for(int j = 0; j < n_coeff; j++) {								// Ciclo per inserire i coefficienti
			cout << ">>(k)<< * x ^ " << (j) << " : ";					// Chiede all'utente di inserire il coefficiente
			cin >> coeff[j];											// Legge il coefficiente
			cout << endl;
			
			// Verifico se l'input valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
				coeff[j] = 0;											// Rimuove il valore errato di `coeff[j]`				
				j--;													// Riprova a leggere lo stesso coefficiente
			}
		}

		vec.push_back(new Polynomial(coeff, n_coeff));					// Aggiunge un nuovo oggetto `Polynomial` al vettore
		break;
	}

	case 1 :	// Caso per inserire una funzione Exponential
	{
		double b_coeff;      // Coefficiente per la base
        double k_coeff_ex;   // Coefficiente per la base esponenziale
        double c_coeff;      // Coefficiente per l'esponente

        bool b_flag = true;  // Flag per il coefficiente della base
        bool k_ex_flag = true;  // Flag per il coefficiente esponenziale
        bool c_flag = true;  // Flag per il coefficiente dell'esponente

		
		while(b_flag == true) {
			cout << "Please insert base : ";
			cin >> b_coeff;														// Legge il coefficiente della base
			
			
			/*SCELTA PROGETTUALE:
			"b_coeff < 1" potrebbe sembrare un controllo ripetitivo, ma essendo un interfaccia per l'utente, abbiamo preferito controllare
			che b fosse > 0 per richiedere subito all'utente di inserire un nuovo valore, senza dover:
			- allocare un oggetto Exponential con il valore della base inserita dall'utente
			- verificare b con la funzione isValid di Exponential
			Nonostante ciò abbaimo inserito la fuzione dentro a Exponential, così che si possa usare in caso di necessità
			*/
			if(!verifyInput() || b_coeff < 1) {	// Verifico se l'input è valido 
				cout << "The input must be a double greater than 0." << endl;
			} else {
				b_flag = false;
			}
		}
		
		while(k_ex_flag == true) {
            cout << "Please insert base coefficient : ";
            cin >> k_coeff_ex;  										// Legge il coefficiente della base esponenziale
            
			// Verifico se l'input è valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
			} else {
				k_ex_flag = false;
			}
		}
		
		while(c_flag == true) {
            cout << "Please insert exponent coefficient : ";
            cin >> c_coeff;  											// Legge il coefficiente dell'esponente
            
			// Verifico se l'input è valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
			} else {
				c_flag = false;
			}
        }

		vec.push_back(new Exponential(b_coeff, k_coeff_ex, c_coeff));
		break;
	}

	case 2 :	// Caso per inserire una funzione Power
	{
		double k_coeff_pow;  	 // Coefficiente della base
        double e_coeff;      	 // Esponente

        bool k_pow_flag = true;  // Flag per il coefficiente della base
        bool e_flag = true;      // Flag per l'esponente

        while(k_pow_flag == true) {
            cout << "Please insert base coefficient : " ;
            cin >> k_coeff_pow;  										// Legge il coefficiente della base
            
			// Verifico se l'input è valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
			} else {
				k_pow_flag = false;
			}
        }

		while(e_flag == true) {
            cout << "Please insert exponent : " ;
            cin >> e_coeff;  											// Legge l'esponente
            
			// Verifico se l'input è valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
			} else {
				e_flag = false;
			}
        }

		vec.push_back(new Power(e_coeff, k_coeff_pow));					// Aggiunge un nuovo oggetto `Power` al vettore
		break;
	}

	default:	// Caso in cui l'utente inserisce un numero non valido
		cout << "Exiting insertion menu!" << endl;	// Stampa il messaggio di uscita dal menu
		break;
	}

	return vec;
}

/// @brief Deletes a specific function from the vector by its ID.
/// @param vec Reference to the vector of pointers to Function objects.
/// @return Updated vector with the selected function removed.
// 3 – Funzione per eliminare una funzione specifica dal vettore `vec`
vector <Function *> deleteFunc(vector<Function *> &vec) {
//Input sorted out
	unsigned int f_id;  		// ID della funzione da eliminare
    char del;  					// Variabile per confermare l'eliminazione
    bool del_confirm = true;  	// Flag per confermare l'eliminazione

	if(vec.size() < 1) {  						// Se il vettore è vuoto
        cout << "No functions found!" << endl;  // Stampa un messaggio che conferma che non ci sono funzioni
        return vec;  							// Ritorna il vettore senza modifiche
    }

	while(del_confirm) {														// Ciclo per confermare l'eliminazione
		cout << "Please input function ID : ";									// Chiede all'utente di inserire l'ID della funzione
		cin >> f_id;															// Legge l'ID della funzione
		cout << endl;

		// Verifico se l'input è un intero valido
		if(!verifyInput() || f_id > (vec.size() - 1) || f_id < 0) {
			cout << "The function ID must be an integer between 0 and " << vec.size() - 1 << endl;
			f_id = 0;	
		}
		else {
			vec[f_id]->Dump();													// Stampa i dettagli della funzione selezionata

			cout << "Confirm deletion of displayed function? [y/n] ," << endl;	// Chiede conferma per l'eliminazione
			cout << "(Exit deletion menu [any other key]) : " ;					// Chiede di uscire se si preme qualsiasi altro tasto
			cin >> del;															// Legge la scelta dell'utente
			cout << endl;

			switch(del) {
			// Se l'utente conferma
			case 'y' :
			case 'Y' :
				del_confirm = false;  			// Termina il ciclo di conferma
                delete vec[f_id];  				// Elimina la funzione
                vec.erase(vec.begin() + f_id);  // Rimuove la funzione dal vettore
                break;
			// Se l'utente rifiuta
			case 'n' :
			case 'N' :
				break;
			// Caso in cui l'utente inserisce un tasto non valido
			default:
				del_confirm = false;						// Termina il ciclo
				cout << "Exiting deletion menu..." << endl;	// Stampa il messaggio di uscita dal menu
				break;
			}
		}
	}

	return vec;		// Ritorna il vettore modificato
}

/// @brief Deletes all functions from the vector after confirmation.
/// @param vec Reference to the vector of pointers to Function objects.
/// @return Cleared vector with all elements removed.
// 4 – Funzione per eliminare tutte le funzioni nel vettore `vec`
vector <Function *> eraseAllFunc(vector<Function *> &vec) {
//Input sorted out
	if(vec.size() < 1) {  						// Se il vettore è vuoto
        cout << "No function found!" << endl;  	// Stampa un messaggio se non ci sono funzioni
        return vec;  							// Ritorna il vettore senza modifiche
    }

	bool erase_flag = true;						// Flag per confermare l'eliminazione
	char del;  									// Variabile per confermare l'eliminazione

	while(erase_flag == 1) {													// Ciclo per confermare l'eliminazione di tutte le funzioni
		cout << "Confirm deletion of all functions? [y/any other key] : "; 		// Chiede conferma per eliminare tutte le funzioni
        cin >> del;  															// Legge la scelta dell'utente
        cout << endl;
		
		// Verifico se l'input è un intero valido
		if(!verifyInput()) {
			cout << "The function ID must be a character." << endl;
		} 
		else {
            erase_flag = 0;  // Termina il ciclo di conferma

            switch(del) {
			// Se l'utente conferma
			case 'y' :
			case 'Y' :
				for(int i = 0; i < vec.size(); i++) {   	// Ciclo per eliminare tutte le funzioni
                    delete vec[i];							// Elimina ogni funzione dal vettore
                }
                vec.erase(vec.begin(), vec.end());  		// Rimuove tutte le funzioni dal vettore
                break;
			// Caso in cui l'utente rifiuta
            default: 
				cout << "Exiting deletion menu..." << endl;	// Stampa il messaggio di uscita dal menu
				break;
			}
		}
	}
	return vec;		// Ritorna il vettore modificato
}

/// @brief Selects a function from the vector by ID and evaluates it at a given point.
/// @param vec Reference to the vector of pointers to Function objects.
// 5 – Funzione per selezionare una funzione dal vettore `vec` e calcolare il suo valore in un punto x
void selectFunc(vector<Function *> &vec) {
	unsigned int f_id;  	// ID della funzione da selezionare
    double x;            	// Variabile per il valore di x in cui calcolare la funzione
    bool sel_flag = 1;  	// Flag per continuare a selezionare

    while(sel_flag == 1) {  					// Ciclo per selezionare una funzione e calcolarne il valore
        cout << "Please input function ID : ";  // Chiede all'utente di inserire l'ID della funzione
        cin >> f_id;  							// Legge l'ID della funzione
        cout << endl;

		// Verifico se l'input è un intero valido
		if(!verifyInput() || f_id >= vec.size() || f_id < 0) {
			cout << "The function ID must be an integer between 0 and " << vec.size() - 1 << endl;
		} 
		else {
            vec[f_id]->Dump();  												// Stampa i dettagli della funzione selezionata

            cout << "Please input x value in which to calculate function : ";  	// Chiede all'utente di inserire un valore per `x`
            cin >> x;  															// Legge il valore di `x`
            cout << endl;

			// Verifico se l'input è un intero valido
			if(!verifyInput()) {
				cout << "The input must be a double." << endl;
			}
			else {
                cout << "Value for " << x << " is : ";  				// Stampa il valore di `x`
                cout << vec[f_id]-> GetValue(x) << endl;			  	// Calcola e stampa il valore della funzione in `x`
                sel_flag = 0;  											// Termina il ciclo
            }
		}
	}
}


/// @brief Verifies whether the previous input operation was successful and the input stream is in a good state.
/// @return Returns true if the input stream is valid, false otherwise. If invalid, clears the error state and discards remaining input.
// Funzione per verificare se l'input è valido
bool verifyInput() {
	// Controlla se lo stream di input ha fallito (es. tipo errato)
    if (cin.fail()) {
		cin.clear(); 											// Resetta lo stato di errore di cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Scarta tutti i caratteri rimanenti nel buffer fino al newline
        return false; 											// Ritorna false: input non valido
	} 
	else {
        return true; 											// Ritorna true: input valido
    }
}