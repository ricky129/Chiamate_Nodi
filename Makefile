chiamate.o: main.o utenti.o
	 gcc -g -o utenti main.o utenti.o

main.o: utenti.c utenti.h
	 gcc -c -g main.c

utenti.o: utenti.c utenti.h
	 gcc -c -g utenti.c