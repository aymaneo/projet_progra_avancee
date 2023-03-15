#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jeton.h"
#include "analyseur_lexical.h"

int main(){
    void *memory=malloc(sizeof(int));
    int *erreur_pg=(int *)memory;
    *erreur_pg=0;
    char c[] = "sin(x+3)"; //Création de la première chaine de caractère de test
    typejeton tabth[6];   //Création d'un tableau avec les résultats théoriques
    tabth[0].lexem=FONCTION;
    tabth[0].valeur.fonction=SIN;

    tabth[1].lexem=PAR_OUV;

    tabth[2].lexem=VARIABLE;

    tabth[3].lexem=OPERATEUR;
    tabth[3].valeur.operateur=PLUS;

    tabth[4].lexem=REEL;
    tabth[4].valeur.reel=3;

    tabth[5].lexem=PAR_FERM;

    typejeton tab[100] = analyse_lexicale(erreur_pg, c);

    for(int i=0;i<strlen(tabth);i++){
        if(tabth[i].lexem!=tab[i].lexem){
            printf("trop pas bien");
            return -1;
        }
        else if(tabth[i].valeur.fonction!=tab[i].valeur.fonction){
            printf("trop pas bien");
            return -1;
        }
        else if(tabth[i].valeur.operateur!=tab[i].valeur.operateur){
            printf("trop pas bien");
            return -1;
        }
        else if(tabth[i].valeur.reel!=tab[i].valeur.reel){    
            printf("trop pas bien");
            return -1;
        }
    }
    printf("trop bien");
    return 0; 
}