#include <stdio.h>
#include "utenti.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Utilizzo: %s <file_utenti> <file_chiamate>\n", argv[0]);
        return 1;
    }

    ListaNodi listaUtenti;
    ListaChiamate listaChiamate;

    // Inizializza le liste
    nuovaListaNodiU(&listaUtenti);
    nuovaListaNodiC(&listaChiamate);

    Utente U1;
    insCodaU(&listaUtenti, U1);
    // Legge i dati dai file
    leggiUtenti(&listaUtenti);

    
    leggiChiamate(&listaChiamate);

    // Esegue il calcolo del credito
    Agisci(listaChiamate, &listaUtenti);

    // Stampa i risultati
    printf("Situazione degli utenti dopo le chiamate:\n");
    stampaListaNodi(listaUtenti);
    return 0;
}
