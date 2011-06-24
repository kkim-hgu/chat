
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "listeGroupe.h"
#include "groupe.h"



#define MAX_ELEMS 1000
static int	nbrElems = 0;
static void*	lesGroupes[MAX_ELEMS];



void	listeGroupeAjouter (void* elem) {
	assert (elem != NULL && "elem doit etre un pointeur non NULL");
	assert (nbrElems < MAX_ELEMS && "liste groupe pleine");
	lesGroupes[nbrElems] = elem;
	nbrElems++;
}



int	listeGroupeTaille () {
	return nbrElems;
}



int	listeGroupeContient (char* nom) {
	int i;
	for (i=0; i < nbrElems; i++) {
		if ( !strcmp(donnerGroupeNom(lesGroupes[i]), nom) )
			return 1;
	}
	return 0;
}



int	listeGroupePosition (char* nom) {
	int i;
	for (i=0; i < nbrElems; i++) {
		if ( !strcmp(donnerGroupeNom(lesGroupes[i]), nom) )
			return i;
	}
	return -1;
}



void*	listeGroupeObtenir (int position) {
	assert (nbrElems > 0 && "liste groupes vide");
	return lesGroupes[position];
}



void*	listeGroupeElement (char* nom) {
	assert (nbrElems > 0 && "liste groupes vide");
	return lesGroupes[ listeGroupePosition(nom) ];
}



void*	listeGroupeEnlever (char *nom) {
	assert (nbrElems > 0 && "liste groupes vide");

	int position = listeGroupePosition (nom);
	Groupe groupe = lesGroupes[position];
	supprimerGroupe (lesGroupes[position]);

	int i;
	for ( i=position; i < (nbrElems-1); i++ )
		lesGroupes[i] = lesGroupes[i+1];

	nbrElems--;
	return groupe;
}