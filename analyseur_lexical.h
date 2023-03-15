#ifndef analyseur_lexical_h
#define analyseur_lexical_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jeton.h"

typejeton analyse_lexicale(int *erreur_pg,char c[]);

#endif 