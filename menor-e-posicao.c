//Objetivo: Encontrar o menor elemento de um vetor e a sua posição, mostrando esta informação.
//Entrada: A primeira linha de entrada contem um único inteiro N (1 < N < 1000), indicando o número de elementos que deverão ser lidos em seguida para o vetor X[N] de inteiros. A segunda linha contém cada um dos N valores, separados por um espaço. Vale lembrar que nenhuma entrada haverá números repetidos.
//Saída: A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço e do menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:” seguido de um espaço e da posição do vetor na qual se encontra o menor valor lido, lembrando que o vetor inicia na posição zero.

#include <stdio.h>
int main()
{
   int C, N, P, menor_valor; // Declaração de variáveis

    scanf("%d", &N); // Leitura do número
    int elementos[N];
    for(C=0; C<N; C++) 
        scanf("%d", &elementos[C]); // Leitura dos valores de N
    menor_valor = elementos[0]; // Organização no vetor
    for(C=1; C<N; C++)
    {
        if(menor_valor>elementos[C]) 
        {
            menor_valor = elementos[C];
            P=C;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor_valor, P); // Saída do menor valor e da posição
    return 0;
}