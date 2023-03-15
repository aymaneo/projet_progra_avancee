#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jeton.h"
#include "analyseur_lexical.h"
#define max 100


typejeton analyse_lexicale(int *erreur_pg, char c[])
{
    typejeton tab[max];
    char ch3[3];
    char ch4[4];
    char ch6[6];
    c="sin(x+3)";
    int j,l=0;
    
    for(int i=0;i<strlen(c);i++)
    {
        if(i==0 && c[i]=='-')
        {
            tab[j].lexem=FONCTION;
            tab[j].valeur.fonction=VAL_NEG;
            j++;
        }
        if ((c[i])==' ')
        {
            continue;
        }
        else if (c[i]=='+')
        {
            tab[j].lexem=OPERATEUR;
            tab[j].valeur.operateur=PLUS;
            j++;
        }
        else if (c[i]=='-')
        {
            tab[j].lexem=OPERATEUR;
            tab[j].valeur.operateur=MOINS;
            j++;
        }
        else if (c[i]=='*')
        {
            tab[j].lexem=OPERATEUR;
            tab[j].valeur.operateur=FOIS;
            j++;
        }
        else if (c[i]=='/')
        {
            tab[j].lexem=OPERATEUR;
            tab[j].valeur.operateur=DIV;
            j++;
        }
        else if (c[i]=='^')
        {
            tab[j].lexem=OPERATEUR;
            tab[j].valeur.operateur=PUIS;
            j++;
        }  
        else if (isdigit(c[i]))
        {
            tab[j].lexem=REEL;
            tab[j].valeur.reel=c[i];
            j++;
        }
        else if(c[i]=='x')
        {
          
        }
        else if(isalpha(c[i]))
        {
            l=0;
            if(i>=2){
                for(int k=i-2;k<=i;k++){
                    ch3[l]=c[k];
                    l++;
                    if(strcmp(ch3,"ABS")==0)
                    {
                        tab[j].valeur.fonction=ABS;
                        j++;
                    }
                    else if (strcmp(ch3,"SIN")==0)
                    {
                        tab[j].valeur.fonction=SIN;
                        j++;
                    }
                    else if (strcmp(ch3,"LOG")==0)
                    {
                        tab[j].valeur.fonction=LOG;
                        j++;
                    }
                    else if(strcmp(ch3,"COS")==0)
                    {
                        tab[j].valeur.fonction=COS;
                        j++;
                    }
                    else if (strcmp(ch3,"TAN")==0)
                    {
                        tab[j].valeur.fonction=TAN;
                        j++;
                    }
                    else if (strcmp(ch3,"EXP")==0)
                    {
                        tab[j].valeur.fonction=EXP;
                        j++;
                    }
                    else if (strcmp(ch3,"COS")==0)
                    {
                        tab[j].valeur.fonction=COS;
                        j++;
                    }
                }
            }
            if(i>=3)
            {
                for(int k=i-3;k<=i;k++)
                {
                    ch4[l]=c[k];
                    l++;
                    if (strcmp(ch4,"SQRT")==0)
                    {
                        tab[j].valeur.fonction=SQRT;
                        j++;
                    }
                    else if (strcmp(ch4,"SINC")==0)
                    {
                        tab[j].valeur.fonction=SINC;
                        j++;
                    }
                }
            }
            if(i>=5)
            {
                for(int k=i-5;k<=i;k++){
                    ch6[l]=c[k];
                    l++;
                    if (strcmp(ch6,"ENTIER")==0)
                    {
                        tab[j].valeur.fonction=ENTIER;
                        j++;
                    }
                }
            }
        }
        else if(c[i]=='(')
        {
            tab[j].lexem=PAR_OUV;
            j++;
        }
        else if(c[i]==')')
        {
            tab[j].lexem=PAR_FERM;
            j++;
        }
        else if(c[i]=='|')
        {
            tab[j].lexem=BAR;
            j++;
        }
        else if(c[i]=='\0')
        {
            tab[j].lexem=FIN;
            j++;
        }
            
      else 
      {
          *erreur_pg=100;
      }
   }
   return * tab;
}
