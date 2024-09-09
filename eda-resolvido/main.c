/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int namefilepointposition(char *fullname){
   int i;
   for(i=0;i<strlen(fullname);i++){
       if(fullname[i]=='.'){
            break;
       }
    } 
    if(i>=strlen(fullname)){
        return -1;
    }
    else{
        return i;
    }
}


int word2vec(char *pNomeTxtEntrada){
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;
//Generating Output filename    
    if(pointidx>=0){
        for(pp=0;pp<pointidx;pp++){
            nomarq[pp] = pNomeTxtEntrada[pp];
            nomarq[pp] = '\0';//End of string
        }
    }
    else{
        strcpy(nomarq,  pNomeTxtEntrada);
        strcat(nomarq,  "_Vocabulo");
        strcat(nomarq,  ".txt");
        printf("\nRecebi no nome do arquivo: %s", nomarq);
    }
//Generating the output:

    return 1;
}


int main()
{
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocábulo!");
    else
        printf("\nGerei o vocábulo!");
    

    return 0;
}