//Objetivo: Identicar placas de carros e o dia do rodizio que podem circular
//Entrada: A primeira linha de entrada representa a quantidade de testes N (0 <= N < 1000) que deverão ser considerados. As demais entradas são cadeia de caracteres com tamanho máximo S (1 <= S <= 100) que representam cada placa que deverá ser analisada, de tal forma que, cada placa fique em uma única linha de entrada. O formato esperado para uma placa veicular válida em São Paulo é "AAA-9999", tal que A é um caracter válido em [A-Z], e 9 um dígito numérico válido em [0-9].
//Saída: O conjunto de valores válidos como saída são: MONDAY, TUESDAY, WEDNESDAY, THURSDAY e FRIDAY, de acordo com a tabela de restrições predefinida, e FAILURE caso a placa não apresente o padrão definido.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    int N; //Declaração de variáveis
    char plate_car[110];
    scanf("%d ", &N); //Leitura do número que indica a quantidade de testes a serem feitos
    
    while (N--) {
        scanf ("%[^\n]%*c", plate_car); //Leitura das placas
        
        if (!(strlen(plate_car) == 8 && isupper(plate_car[0]) && isupper(plate_car[1]) //Identificador de placas inexistentes
        && isupper(plate_car[2]) && plate_car[3] == '-' && isdigit(plate_car[4])
        && isdigit(plate_car[5]) && isdigit(plate_car[6]) && isdigit(plate_car[7])))
            printf("FAILURE\n");
        else { //Caso a placa seja verdadeira identificar o dia que não poderá rodar
            switch (plate_car[7]) {
                case '1':
                case '2':
                    printf("MONDAY\n"); //Saída dos dias que não poderão rodar
                    break;
                case '3':
                case '4':
                    printf("TUESDAY\n");
                    break;
                case '5':
                case '6':
                    printf("WEDNESDAY\n");
                    break;
                case '7':
                case '8':
                    printf("THURSDAY\n");
                    break;
                case '9':
                case '0':
                    printf("FRIDAY\n");
                    break;
            }
        }
    }
    
    return 0;
}