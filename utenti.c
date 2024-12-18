#include <stdio.h>
#include <stdlib.h>
#include "utenti.h"

void nuovaListaNodiU(ListaNodi *pl){
    *pl = NULL;
}

void nuovaListaNodiC(ListaChiamate *pc){
    *pc = NULL;
}

void insTestaC(ListaChiamate *pc, Chiamate C1){
    NodoC *aux = malloc(sizeof(NodoC));

    if(!aux){
        printf("Allocazione non riuscita\n");
        exit(100);
    }

    aux->C1 = C1;
    aux->next = *pc;
    *pc = aux;
}

void insCodaC(ListaChiamate *pc, Chiamate C1){
    while(*pc)
        pc = &(*pc)->next;
    insTestaC(pc, C1);
}

void insTestaU(ListaNodi *pl, Utente U1){
    NodoU *aux = malloc(sizeof(NodoU));

    if(!aux){
        printf("Allocazione non riuscita\n");
        exit(100);
    }

    aux->U1 = U1;
    aux->next = *pl;
    *pl = aux;
}

void insCodaU(ListaNodi *pl, Utente U1){
    while(*pl)
        pl = &(*pl)->next;
    insTestaU(pl, U1);
}

void leggiChiamate(ListaChiamate *pc){
    FILE *pft = fopen("chiamate.txt", "rt");
    Chiamate record;

    if(!pft){
        printf("Apertura file non riuscita %s\n", "chiamate.txt");
        exit(100);
    }

    while (fread(&record, sizeof(Chiamate), 1, pft) == 1){
        Chiamate C1;
        C1.numero = record.numero;
        C1.durata = record.durata;

        insCodaC(pc, C1);
    }
    fclose(pft);
}

void leggiUtenti(ListaNodi *pl){
    FILE *pfb = fopen("utenti.dat", "rb"); 
    Utente utente;

    if(!pfb){
        printf("Apertura file non riuscita %s\n", "utenti.dat");
        exit(100);
    }

    while(fread(&utente, sizeof(Utente), 1, pfb) == 1){
        Utente U1;
        U1.numero = utente.numero;
        U1.piano = utente.piano;
        U1.credito = utente.credito;

        insCodaU(pl, U1);
    }

}

char ottieniPiano(ListaNodi pl, int numero){
    while(pl){
        if(pl->U1.numero == numero)
            return pl->U1.piano;
        pl = pl->next;
    }
    return '\0'; 
}

void sottraiCreditoA(ListaNodi *pl, int numero, int durata){
    while (*pl){
        if((*pl)->U1.numero == numero)
            (*pl)->U1.credito -= 0.15+(0.08*(durata/60));
        pl = (*pl)->next; 
    }
    
}

void sottraiCreditoB(ListaNodi *pl, int numero, int durata){
    while(*pl){
        if((*pl)->U1.numero == numero)
            (*pl)->U1.credito -= 0.12*durata;
        pl = (*pl)->next; 
    }
}

void Agisci(ListaChiamate cl, ListaNodi pl){
    int durataB = 0;
    while(cl){
        switch (ottieniPiano(pl, cl->C1.numero)){
        case 'A':
            sottraiCreditoA(pl, cl->C1.numero, cl->C1.durata);
            break;
        case 'B':
            sottraiCreditoB(pl, cl->C1.numero, cl->C1.durata);
        default:
            break;
        }
        cl = cl->next;
    }
}

void stampaListaNodi(ListaNodi pl){
    while(pl){
        printf("Numero: %d  Piano: %c   Credito: %f\n", pl->U1.numero, pl->U1.piano, pl->U1.credito);
        pl = pl->next;
    }
}