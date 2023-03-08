#include <stdio.h>
#include <string.h>
//#include <jeton.h>


char detecteoperateur(char ch){
    typejeton.lexem="OPERATEUR";
    switch(ch){
        case '+':
        
             typejeton.valeur="PLUS";
             break;
        
        case '-':
        
            typejeton.valeur="MOINS";
            break;
        
        case '*':
        
            typejeton.valeur="FOIS";
            break;
        
        case '/':
        
        typejeton.valeur="DIV";
            break;
        case '^':
        {
            typejeton.valeur='PUIS';
            break;
        }
    }
    return 
}

char detectfonction(char ch){
    typejeton.lexem="FONCTION";
    if (strlen(ch)==3)
    {
        switch (ch){
            case strcmp(ch,"ABS")==0:
            
                typejeton.valeur="ABS";
            break;

            case strcmp(ch,"SIN")==0:

                typejeton.valeur="SIN";
            break;

            case strcmp(ch,"LOG")==0:

                typejeton.valeur="LOG";
            break;

            case strcmp(ch,"COS")==0:

                typejeton.valeur="COS";
            break;

            case strcmp(ch,"TAN")==0:

                typejeton.valeur="TAN";
            break;

            case strcmp(ch,"EXP")==0:

                typejeton.valeur="EXP";
            break;

            case strcmp(ch,"COS")==0:

                typejeton.valeur="COS";
            break;


        }
    }
    else if (strlen(ch)==4)
    {
        switch (ch)
        {
            case strcmp(ch,"SQRT")==0:

                typejeton.valeur="SQRT";
            break;

            case strcmp(ch,"SINC")==0:

                typejeton.valeur="SINC";
            break;

            case strcmp(ch,"ENT")==0:

                typejeton.valeur="ENT";
            break;
        }
    }






int main() {
    char str[] = "Bonjour, comment ça va ?";
    char delimiters[] = " ,.?"; // les délimiteurs sont les espaces, les virgules et les points d'interrogation
    char *token;

    // La fonction strtok() renvoie le premier lexème trouvé dans str
    token = strtok(str, delimiters);

    // On continue de parcourir la chaîne jusqu'à ce que tous les lexèmes aient été trouvés
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}