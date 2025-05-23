#include "Polynomial.h"       // Inclusione dell'header per la gestione di funzioni polinomiali
#include "Power.h"            // Inclusione dell'header per la gestione di funzioni di potenza
#include "Exponential.h"      // Inclusione dell'header per la gestione di funzioni esponenziali
#include "menu.h"             // Inclusione dell'header con funzioni di gestione menu e input/output

using namespace std;          // Uso dello spazio dei nomi standard (evita di scrivere std:: prima di cout, vector, ecc.)

int main() {

    vector<Function *> v;     // Vettore di puntatori a oggetti derivati dalla classe base Function
    bool flag = true;         // Flag principale per mantenere attivo il ciclo del menu
    bool in_flag;             // Flag secondario per controllare la validità dell'input dell'utente
    int input;                // Variabile per memorizzare la scelta dell'utente

    int test;                 // Variabile dichiarata ma non utilizzata (potenzialmente da rimuovere o usare)

    while(flag == true){      // Ciclo principale del menu: continua finché l'utente non sceglie di uscire
        in_flag = true;       // All'inizio di ogni iterazione del menu, si abilita il controllo dell'input

        // Ciclo interno per controllare la validità dell'input numerico
        while(in_flag == true) {
            // Stampa le opzioni del menu all'utente
            cout << endl;
            cout << "0 - Exit menu;" << endl;
            cout << "1 - View initialised functions;" << endl;
            cout << "2 - Add a function;" << endl;
            cout << "3 - Delete a function;" << endl;
            cout << "4 - Delete all functions;" << endl;
            cout << "5 - Select a function." << endl;
            cout << "Please input associated operation number : ";

            cin >> input;     // Acquisizione dell'input da tastiera
            cout << endl;

            // Controllo se l'input è valido (intero tra 0 e 5) e se cin non ha errori
            if(!verifyInput() || input < 0 || input > 5) {
                cout << "The function ID must be an integer between 0 and 5." << endl;
            } else {
                in_flag = false;  // Input corretto, si può uscire dal ciclo interno
            }
        }

        // Selezione dell'operazione da eseguire in base all'input dell'utente
        switch(input) {
        case 0 :
            flag = false;            // Imposta flag a false per uscire dal ciclo principale
            v = exitMenu(v);         // Chiama la funzione per gestire l'uscita (eventuale pulizia, ecc.)
            break;
        case 1 :
            printFunc(v);            // Chiama la funzione che stampa le funzioni presenti nel vettore
            break;
        case 2 :
            v = insertFunc(v);       // Inserisce una nuova funzione nel vettore
            break;
        case 3 :
            v = deleteFunc(v);       // Elimina una funzione dal vettore
            break;
        case 4 :
            v = eraseAllFunc(v);     // Elimina tutte le funzioni dal vettore
            break;
        case 5 :
            selectFunc(v);           // Permette di selezionare una funzione dal vettore per ulteriori operazioni
            break;
        default:
            break;                   // Caso di default, non fa nulla (di norma non dovrebbe mai attivarsi)
        }
    }

    // Stampa finale quando si esce dal ciclo principale del menu
    cout << "Exited from menu!" << endl << endl;
}