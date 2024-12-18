typedef struct {
    int numero;
    char piano;
    float credito;
} Utente;

typedef struct nodoU{
    Utente U1;
    struct NodoU *next;
} NodoU;

typedef struct{
    int numero;
    int durata;
} Chiamate;

typedef struct nodoC{
    Chiamate C1;
    struct NodoC *next;
} NodoC;

typedef NodoU *ListaNodi;
typedef NodoC *ListaChiamate;

void nuovaListaNodiU(ListaNodi *pl);
void nuovaListaNodiC(ListaChiamate *pc);
void insTestaC(ListaChiamate *pc, Chiamate C1);
void insCodaC(ListaChiamate *pc, Chiamate C1);
void insTestaU(ListaNodi *pl, Utente U1);
void insCodaU(ListaNodi *pl, Utente U1);
void leggiChiamate(ListaChiamate *CL);
void leggiUtenti(ListaNodi *pl);
char ottieniPiano(ListaNodi pl, int numero);
void sottraiCreditoA(ListaNodi *pl, int numero, int durata);
void sottraiCreditoB(ListaNodi *pl, int numero, int durata);
void Agisci(ListaChiamate cl, ListaNodi pl);
void stampaListaNodi(ListaNodi pl);