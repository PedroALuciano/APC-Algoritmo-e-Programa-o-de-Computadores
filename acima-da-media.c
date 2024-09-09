//Objetivo: Calcular quantos alunos estão acima da média
//Entrada: A entrada contém muitos casos de teste. A primeira linha da entrada contém um inteiro C, indicando o número de casos de teste. Seguem C casos de teste ou instâncias. Cada caso de teste inicia com um inteiro N, que é o número de pessoas de uma turma (1 ≤ N ≤ 1000). Seguem N inteiros, separados por espaços, cada um indicando a média final (um inteiro entre 0 e 100) de cada um dos estudantes desta turma.
//Saída: Para cada caso de teste imprima uma linha dando o percentual de estudantes que estão acima da média da turma, com o valor arredondado e com 3 casas decimais.

#include <stdio.h>

int main(){
    int C,N,i; // Declaração de variáveis a serem utilizadas
    float soma_A,S;
    
    scanf("%d",&C); // leitura dos casos de teste ou instâncias
    while(C > 0){
            scanf("%d",&N); 
            soma_A = 0; // Iniciação das variáveis
            S = 0;
            int number[N];
            for(i = 0; i < N; i++){
                    scanf("%d",&number[i]); // Leitura do número de pessoas de uma turma
                    soma_A+=number[i];
            }
            soma_A /= N;
            for(i = 0; i < N; i++){ // Adiciona o percentual de alunos
                    if(number[i] > soma_A) S++;
            }
            printf("%.3f%c\n",S/N*100.000,'%'); // Cálculo da porcentagem
            C--;
    }
    return 0;
}