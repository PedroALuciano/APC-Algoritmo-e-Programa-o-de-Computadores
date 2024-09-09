
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char cpf[15];
    
    fgets(cpf,15,stdin);
    
    for(i=0; i <=2; i++){
        printf("%c", cpf[i]);
    }
    printf("\n");
    
    for(i=4; i<=6; i++){
        printf("%c", cpf[i]);
    }

    printf("\n");
    
    for(i=8; i<=10; i++){
        printf("%c", cpf[i]);
    }
    
    printf("\n");
    
    for(i=12; i<=13; i++){
        printf("%c", cpf[i]);
    }
    
    printf("\n");
    
    return 0;
}
