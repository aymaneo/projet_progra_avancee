#include <stdio.h>
#include <string.h>


int main() {
    char ch[] = "sin(x+3)";
    char delimiteurs[] = "( ) + - * / "; // les délimiteurs 
    char *lex;
    char ch2[strlen(ch)];
    strcpy(ch2,ch);
    char t[100];
    int j=0;
   
    // La fonction strtok() renvoie le premier lexème trouvé dans ch
    lex = strtok(ch, delimiteurs);

    // On continue de parcourir la chaîne jusqu'à ce que tous les lexèmes soient trouvés
    while (lex != NULL) {
        printf("%s\n %s\n", lex, delimiteurs);
        lex = strtok(NULL, delimiteurs);
    }
    
    for(int i=0,i<strlen(ch2),i++){
        if(ch[i]==NULL)
        {
            t[i]=ch2[i];
        }
    }

     // La fonction strtok() renvoie le premier lexème trouvé dans ch2
    char *lex2 = strtok(ch2, delimiteurs);

    // On continue de parcourir la chaîne jusqu'à ce que tous les lexèmes 2 soient trouvés
    while (lex2 != NULL) {
        printf("%s\n %s\n", lex2, delimiteurs);
        printf("%s",t[j]);
        lex2 = strtok(NULL, delimiteurs);
        j++;
    }

    return 0;
}



