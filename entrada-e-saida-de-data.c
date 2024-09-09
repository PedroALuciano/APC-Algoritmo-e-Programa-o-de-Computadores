//Objetivo: Ler um formato de uma data e imprimir outros 3 formatos diferentes
//Entrada: A entrada consiste vários arquivos de teste. Em cada arquivo de teste tem uma linha. A linha tem o seguinte formato DD/MM/AA onde DD, MM, AA são números inteiros. Conforme mostrado no exemplo de entrada a seguir
//Saída: Para cada arquivo da entrada, terá um arquivo de saída. O arquivo de saída tem três linhas conforme os procedimentos 2, 3 e 4. Conforme mostra o exemplo de saída a seguir.

#include <stdio.h>

int main() {
    
    char data[9]; // Declaração de variável
    
    scanf("%s ", data); // Leitura do primeiro formato de data
    
    printf("%c%c/%c%c/%c%c\n", data[3], data[4], data[0], data[1], data[6], data[7]); // Saída do primeiro formato da data
    printf("%c%c/%c%c/%c%c\n", data[6], data[7], data[3], data[4], data[0], data[1]); // Saída do segundo formato da data
    printf("%c%c-%c%c-%c%c\n", data[0], data[1], data[3], data[4], data[6], data[7]); // Saída do terceiro formato da data

    return 0;
}