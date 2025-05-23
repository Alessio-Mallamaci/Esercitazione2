/*! @file menu.h 
    @brief Header for managing a menu of mathematical functions
    @author Alessio Mallamaci e Alessio Pedretti

    Details.
*/ 

// GUARDIA D'INCLUSIONE: impedisce che il file venga incluso più di una volta
#ifndef MENU_H
#define MENU_H


#include <iostream>   // per input/output
#include <vector>     // per il tipo vector
#include <limits>     // per numeric_limits
#include <string>     // per gestire stringhe (se necessario)

using namespace std;

/// @name Functions Prototypes
/// @{

//0 – Esci dal menù
vector <Function *> exitMenu(vector<Function *> &vec);

//1 – Visualizza la lista delle funzioni  (Stampa tutte le funzioni presenti nel vettore)
void printFunc(vector <Function *> &vec);

//2 – Inserisci una funzione 
vector <Function *> insertFunc(vector <Function *> &vec);

//3 – Elimina una funzione (identificata da ID)
vector <Function *> deleteFunc(vector <Function *> &vec);

//4 – Elimina tutte le funzioni (presenti nel vettore)
vector <Function *> eraseAllFunc(vector <Function *> &vec);

//5 – Seleziona una funzione (e calcola il valore in un certo punto x)
void selectFunc(vector <Function *> &vec);
/// @}


/// @name Input checking function
/// @{

//Funzione che verifica se l'input dell'utente è valido
bool verifyInput();

/// @}



#endif
