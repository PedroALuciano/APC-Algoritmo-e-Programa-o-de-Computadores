#include <stdlib.h>
#include <stdio.h>

int CriaVetFloat(float *v, int i){
  int num_componentes;
  
  printf("Informe o numero de componentes do vetor\n");
  scanf("%d", &num_componentes);
  
  v = (float *) malloc(num_componentes * sizeof(float));
  
  //Armazenando os dados em um vetor
  for (i = 0; i < num_componentes; i++)
  {
    printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    scanf("%f",&v[i]);
  }
  
    printf("\n*********** Valores do vetor dinamico ************\n\n");
    
    for (i = 0;i < num_componentes; i++){
        printf("%.2f\n",v[i]);
    }
    
    free(v);
  
  return 0;//v[i];
}


void CriaVetInt(int *Vi, int i){
  int n_comp;
  
  printf("Informe o numero de componentes do vetor\n");
  scanf("%d", &n_comp);
  
  Vi = (int *) malloc(n_comp * sizeof(int));
  
  //Armazenando os dados em um vetor
  for (i = 0; i < n_comp; i++)
  {
    printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    scanf("%d",&Vi[i]);
  }
  
  // ------ Percorrendo o vetor e imprimindo os valores ----------
    printf("\n*********** Valores do vetor dinamico ************\n\n");
    
    for (i = 0; i < n_comp; i++){
        printf("%.2d\n",Vi[i]);
    }
    
    free(Vi);
  
  //Vi[i];
}





int main (){
    int vetor;
    int in;
    int *Vit;
    float *vit;
    
    vetop:
    printf("Informe qual vetor deseja alocar dinamicamente:\n1: Inteiro\n2: Float\n");
    scanf("%d", &vetor);
    
    switch(vetor){
        
        case 1:
            void CriaVetInt(Vit, in);
            /*printf("%d\n", Vi[i]);
            free(Vi);*/
        break;
        
        case 2:
            int CriaVetFloat(vit, in);
            /*printf("%.2f\n", v[i]);
            free(v);*/
            
        break;
        
        default:
            printf("Opçao digitada invalida!\n");
            goto vetop;
        break;
    }
    
return 0;
}