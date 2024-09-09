/* Eu, Pedro Luciano de Azevedo, declaro que sou o autor deste código-fonte e que não copiei de ou repassei a terceiros. 
Estou ciente de que a cópia de trabalhos nesta turma de Algoritmos e Programação de Computadores é considerada como plágio, 
constituindo-se em grave falta ética e estará sujeita a penalizações na avaliação, incluindo reprovação na disciplina.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SAIR 8
//--------------------------Declaraçoes de estruturas -------------------------
// Funções e structs que estão presentes no códigos

int valida_linha(int numero_linha, FILE *arquivo_linhas_cadastrados);
int valida_parada(int numero_parada, FILE *arquivo_paradas_cadastradas);
int existencia_linha(int numero_linha, FILE *arquivo_paradas_cadastradas);
int existencia_parada(int numero_parada, FILE *arquivo_paradas_cadastradas);
int valida_hora_min(int hora, int min);
int existencia_lat_long(float latitude, float longitude);

typedef struct{
    int numero_parada;
    float latitude;
    float longitude;
} Parada;
typedef struct{
    int hora;
    int min;
} Horario;

// -----------------------------Main----------------------------
int main()
{
    printf("**********************************************************\n");
    printf("***Ola, Bem Vindo ao sistema de Transporte Inteligente!***\n");
    printf("**********************************************************\n");
    printf(" \n");
    printf("Este é o Sistema de Gestão de Paradas e Linhas (SGPL).\n");
    printf(" \n");
//--------------------------Variáveis--------------------------
// Declaração de Variáveis 
    int hora, min;
    FILE *arquivo_paradas_cadastradas;
    FILE *arquivo_linhas_cadastrados;
    FILE *arquivo_trajetos_cadastrados;
    FILE *arquivo_temporario;
    FILE *arquivo_temporario1;
    FILE *arquivo_temporario2;
    FILE *arquivo_temporario3;
    float latitude, longitude;
    int numero_parada, numero_linha, parada_excluir, linha_excluir, find;
    char opcao;
    Parada parada;
    Horario horario;
    
    do { //Menu que será mostrado na tela
        printf("Menu de opções:\n");
        printf("1) Cadastrar Parada de Onibus\n");
        printf("2) Cadastrar Linha de Onibus\n");
        printf("3) Cadastrar Trajeto\n");
        printf("4) Listar Paradas Cadastradas\n");
        printf("5) Listar Linhas Cadastradas\n");
        printf("6) Excluir Parada de Onibus\n");
        printf("7) Excluir Linha de Onibus\n");
        printf("8) Encerrar Programa\n");
        
        scanf(" %c", &opcao); //Leitura da opção escolhida pelo usuário.
        
        switch(opcao){ //Após a escolha da opção o usuário irá fazer o procedimento que escolheu por meio deste menu.
            case '1':
                
                parada: // Ponto para qual o código irá voltar caso tente cadastrar uma parada já existente
                printf("Digite o numero da parada que deseja cadastrar (somente numeros inteiros): ");
                scanf("%d", &parada.numero_parada); 
                if (parada.numero_parada > 0){ //Verifica se o valor digitado não é negativo
                    if (!valida_parada(parada.numero_parada, arquivo_paradas_cadastradas)){ // função que está no final do código para verificar se a parada que será cadastrada já existe ou não
                        lat_lon:
                        printf("Digite a latitude da parada (no formato 00.000000): ");
                        scanf("%f", &parada.latitude); // latitude da parada a ser cadastrada
                        printf("Digite a longitude da parada (no formato 000.000000): ");
                        scanf("%f", &parada.longitude); // longitude da parada a ser cadastrada
                        if(existencia_lat_long(parada.latitude, parada.longitude)){
                            
                            arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "a"); // Abertura do arquivo onde serão salvo as paradas
                            
                            if (arquivo_paradas_cadastradas != NULL){ // Verificar se o arquivo realmente foi aberto
                                fprintf(arquivo_paradas_cadastradas, "%d;%f;%f\n", parada.numero_parada, parada.latitude, parada.longitude); // Escrever as informações digitadas pelo usuario no arquivo caso sejam válidas 
                                printf("Parada cadastrada com sucesso!\n");
                                fclose(arquivo_paradas_cadastradas); // Fechar o arquivo após utiliza-lo
                                
                            }else{
                                printf("Não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não tenha conseguido abrir o arquivo aparecerá esta mensagem na tela
                            }
                        }else{
                            printf("Latitue e longitude digitados invalidos. Digite novamente!\n");
                            goto lat_lon; // Levará o usuario até onde esta o ponto lat_lon:
                        }
                    }else{
                        printf("Já existe uma parada cadastrada com este número! Digite novamente: \n"); // Caso já tenha uma parada com o mesmo número ou com um valor negativo aparecerá esta mensagem e o usuario será direcionado para escrever um número diferente
                        goto parada; // Levará o usuario até onde esta o ponto parada:
                    }
                }else{
                    printf("Numero digitado inválido! Digite novamente.\n");
                    goto parada; // Levará o usuario até onde esta o ponto parada:
                }
                break;
                
            case '2':
                linha: // Ponto para qual o código irá voltar caso tente cadastrar uma linha já existente
                printf("Digite o numero da linha que deseja cadastrar (somente números inteiros): ");
                scanf("%d", &numero_linha);
                if(numero_linha > 0){ //Verifica se o valor digitado não é negativo
                    if (!valida_linha(numero_linha, arquivo_linhas_cadastrados)){ // Função que esta no final do código para verificar se já existe uma linha cadastrada e não deixar o usuario cadastrar linhas repetidas
                        arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "a"); // Abrir o arquivo onde serão armazenados as linhas cadastradas
                        
                        if (arquivo_linhas_cadastrados != NULL){ // Verificar se o arquivo realmente abriu
                            fprintf(arquivo_linhas_cadastrados, "%d\n", numero_linha); // Escrever no arquivo e salvar as linhas cadastradas
                            printf("Linha de Onibus cadastrado com sucesso!\n");
                            fclose(arquivo_linhas_cadastrados); // Fechar o aquivo após fazer a utilização
                            
                        }else{
                            printf("Não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não consiga abrir o arquivo aparecerá esta mensagem na tela
                        }
                    }else{
                        printf("Ja existe uma linha cadastrada com este número ou numero digitado invalido! Digite novamente: \n"); // Caso já exista uma linha cadastrada, não irá permitir cadastrar uma linha repetida ou com valor negativo
                        goto linha; // Levará o usuario até onde esta o ponto linha:
                    }
                }else{
                    printf("Numero digitado invalido! Digite novamente.\n"); // Caso o usuario digite um numero negativo
                    goto linha;
                }
                break;
            case '3':
                arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "r");
                arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "r");
                arquivo_trajetos_cadastrados = fopen("trajetos_cadastrados.txt", "a");
                
                if (arquivo_linhas_cadastrados != NULL && arquivo_paradas_cadastradas != NULL && arquivo_trajetos_cadastrados != NULL){ //Verifica se abriu os 3 arquivos solicitados
                    
                    parada1: // Ponto para qual o código irá voltar caso tente cadastrar uma parada inválida ou já existente
                    printf("Digite o numero da parada que deseja cadastrar o trajeto: ");
                    scanf("%d", &parada.numero_parada); // Ler a parada a ser adicionada no trajeto
                    if(existencia_parada(parada.numero_parada, arquivo_paradas_cadastradas)){ // Função que está no final do código e verifica se existe a parada que deseja cadastrar no trajeto
                        fprintf(arquivo_trajetos_cadastrados, "%d;", parada.numero_parada); // Escrever no arquivo e salvar as paradas cadastradas
                    }else{
                        printf("Esta parada não esta cadastrada! Digite uma parada existente!\n");
                        goto parada1; // Levará o usuario até onde esta o ponto parada1:
                    }
                    
                    linha1: // Ponto para qual o código irá voltar caso tente cadastrar uma linha inválida ou já existente
                    printf("Digite o numero da linha que deseja cadastrar no trajeto: ");
                    scanf("%d", &numero_linha); // Ler a linha a ser adicionada no trajeto
                    if(existencia_linha(numero_linha, arquivo_linhas_cadastrados)){ // Função que está no final do código e verifica se existe a linha que deseja cadastrar no trajeto
                        fprintf(arquivo_trajetos_cadastrados, "%d;", numero_linha); // Escrever no arquivo e salvar as linhas cadastradas
                    }else{
                        printf("Esta linha não esta cadastrada! Digite uma linha existente!\n");
                        goto linha1; // Levará o usuario até onde esta o ponto linha1:
                    }
                    
                    horario: // Ponto para qual o código irá voltar caso tente cadastrar um horario inválida ou já existente
                    printf("Digite as horas que deseja cadastrar no trajeto (somente as horas no formato hh): ");
                    scanf("%d", &horario.hora);
                    printf("Digite os minutos que deseja cadastrar no trajeto (somente os minutos no formato mm): ");
                    scanf("%d", &horario.min);
                    if(valida_hora_min(horario.hora, horario.min)){ // Função que faz a verificação do horario digitado
                        fprintf(arquivo_trajetos_cadastrados, "%d:%d\n", horario.hora, horario.min); //Escreve o horario digitano no arquivo com o formato HORA:MINUTO
                        printf("Trajeto cadastrado com sucesso!\n");
                    }else{
                        printf("Horario digitado invalido! Digite novamente.\n");
                        goto horario; // Levará o usuario até onde esta o ponto horario:
                    }
                    fclose(arquivo_trajetos_cadastrados); //Fecha todos os arquivos após usá-los
                    fclose(arquivo_linhas_cadastrados);
                    fclose(arquivo_paradas_cadastradas);
                }else{
                    printf("Não existem trajetos cadastrados ou não foi possivel abrir um ou mais dos arquivo. Tente novamente!\n"); // Caso não seja possível abrir o arquivo
                }
             
                break;
            case '4':
                
                arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "r");
                if (arquivo_paradas_cadastradas != NULL) { // Verificar se o arquivo realmente foi aberto 
                    while (!feof(arquivo_paradas_cadastradas)) { // Enquanto não chegar ao final do arquivo ele ira continuar lendo todas as paradas e mostrando na tela
                        fscanf(arquivo_paradas_cadastradas, "%d;%f;%f\n", &parada.numero_parada, &latitude, &longitude); // Ler os dados que estão dentro do arquivo
                        printf("Parada cadastrada: %d\n", parada.numero_parada); // Mostrar as paradas na tela, as linhas, e os horarios que passam nela
                    }
                    fclose(arquivo_paradas_cadastradas); // Fechar o arquivo após o uso
                } else {
                    printf("Não existem paradas cadastradas ou não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não tenha nenhuma parada cadastrada ou não for possível abrir o arquivo irá mostrar esta mensagem
                }
                
                arquivo_trajetos_cadastrados = fopen("trajetos_cadastrados.txt", "r"); // Abrir o arquivo para leitura
                
                if (arquivo_trajetos_cadastrados != NULL) { // Verificar se o arquivo realmente foi aberto 
                    while (!feof(arquivo_trajetos_cadastrados)) { // Enquanto não chegar ao final do arquivo ele ira continuar lendo todas as paradas e mostrando na tela
                        fscanf(arquivo_trajetos_cadastrados, "%d;%d;%d:%d\n", &parada.numero_parada, &numero_linha, &horario.hora, &horario.min); // Ler os dados que estão dentro do arquivo
                        printf("Trajetos:\n Numero da parada: %d. Numero da linha que passa nesta parada: %d. Horario: %d:%d.\n", parada.numero_parada, numero_linha, horario.hora, horario.min); // Mostrar as paradas na tela, as linhas, e os horarios que passam nela
                    }
                    fclose(arquivo_trajetos_cadastrados); // Fechar o arquivo após o uso
                } else {
                    printf("Não existem trajetos cadastrados ou não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não tenha nenhuma parada cadastrada ou não for possível abrir o arquivo irá mostrar esta mensagem
                }
                
                break;
            case '5':
                
                arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "r");
                if (arquivo_linhas_cadastrados != NULL) { // Verificar se o arquivo realmente foi aberto 
                    while (!feof(arquivo_linhas_cadastrados)) { // Enquanto não chegar ao final do arquivo ele ira continuar lendo todas as paradas e mostrando na tela
                        fscanf(arquivo_linhas_cadastrados, "%d\n", &numero_linha); // Ler os dados que estão dentro do arquivo
                        printf("Linha cadastrada: %d\n", numero_linha); // Mostrar as paradas na tela, as linhas, e os horarios que passam nela
                    }
                    fclose(arquivo_linhas_cadastrados); // Fechar o arquivo após o uso
                } else {
                    printf("Não existem linhas cadastradas ou não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não tenha nenhuma parada cadastrada ou não for possível abrir o arquivo irá mostrar esta mensagem
                }
                
                arquivo_trajetos_cadastrados = fopen("trajetos_cadastrados.txt", "r"); // Abrir o arquivo para leitura
                
                if (arquivo_trajetos_cadastrados != NULL) { // Verificar se o arquivo realmente foi aberto 
                    while (!feof(arquivo_trajetos_cadastrados)) { // Enquanto não chegar ao final do arquivo ele ira continuar lendo todas as paradas e mostrando na tela
                        fscanf(arquivo_trajetos_cadastrados, "%d;%d;%d:%d\n", &parada.numero_parada, &numero_linha, &horario.hora, &horario.min); // Ler os dados que estão dentro do arquivo
                        printf("Trajetos:\nNumero da linha: %d. Numero da parada por qual a linha passa: %d. Horario que a linha passa: %d:%d.\n", numero_linha, parada.numero_parada, horario.hora, horario.min); // Mostra na tela as linhas e as paradas no qual as linhas passam
                    }
                    fclose(arquivo_trajetos_cadastrados); // Fechar o arquivo após o uso
                } else {
                    printf("Não existem trajetos cadastradas ou não foi possível abrir o arquivo. Tente novamente!\n"); // Caso não tenha nenhuma parada cadastrada ou não for possível abrir o arquivo irá mostrar esta mensagem
                } 
                
                break;
                
            case '6':
                
                arquivo_trajetos_cadastrados = fopen("trajetos_cadastrados.txt", "r"); //Abre todos os arquivos que serão utilizados nesta função 
                arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "r");
                arquivo_temporario = fopen("arquivo_temporario.txt", "a");
                arquivo_temporario1 = fopen("arquivo_temporario1.txt", "a");
                find = 0;
                
                if (arquivo_paradas_cadastradas != NULL && arquivo_temporario1 != NULL) { //Verifica se os arquivos existem e foram abertos
                    printf("Digite o número da parada que deseja excluir: \n");
                    scanf("%d", &parada_excluir); //Faz a leitura da parada que o usuario deseja excluir
                    
                    while(!feof(arquivo_paradas_cadastradas)){ //Enquanto não for o final do arquivo
                        fscanf(arquivo_paradas_cadastradas, "%d;%f;%f\n", &parada.numero_parada, &latitude, &longitude); //Vai ler toda a linha do arquivo
                        if(parada_excluir != parada.numero_parada){ //Verifica se o numero digitado é diferente do que esta no arquivo
                            fprintf(arquivo_temporario1, "%d;%f;%f\n", parada.numero_parada, latitude, longitude); //Caso seja diferente irá gravar toda a linha em um outro arquivo
                        }else{
                            printf("Parada e trajetos vinculados à ela que será excluido: %d\n", parada.numero_parada); //Caso seja igual não será escrita no arquivo
                            find = 1; //Se existir uma parada com o mesmo numero digitado dentro do arquivo atribuirá verdadeiro a essa variável
                        }
                    }
                    fclose(arquivo_paradas_cadastradas); //fechara os dois arquivos, removera o arquivo original e renomeara o aquivo novoo com o nome do que foi removido
                    remove("cadastro_linhas.txt");
                    fclose(arquivo_temporario1);
                    rename("arquivo_temporario1.txt", "localizacao_paradas.txt");
                }else{
                    printf("Não existem paradas cadastradas ou foi possivel abrir os arquivos localizacao_paradas e arquivo_temporario1. Tente novamente!\n"); //Caso não abra o arquivo ou ele não exista, sera mostrado esta mensagem na tela
                    
                }
                
                if (arquivo_trajetos_cadastrados != NULL && arquivo_temporario != NULL) { //Verifica se os arquivos existem e foram abertos
                    while(!feof(arquivo_trajetos_cadastrados)){ //Enquanto não for o final do arquivo
                        fscanf(arquivo_trajetos_cadastrados, "%d;%d;%d:%d\n", &parada.numero_parada, &numero_linha, &horario.hora, &horario.min); //Vai ler toda a linha do arquivo
                        if(parada_excluir != parada.numero_parada){ //Verifica se o numero digitado é diferente do que esta no arquivo
                            fprintf(arquivo_temporario, "%d;%d;%d:%d\n", parada.numero_parada, numero_linha, horario.hora, horario.min); //Caso seja diferente irá gravar toda a linha em um outro arquivo
                            
                        }
                    }
                    fclose(arquivo_trajetos_cadastrados); //fechara os dois arquivos, removera o arquivo original e renomeara o aquivo novo com o nome do que foi removido
                    remove("trajetos_cadastrados.txt");
                    fclose(arquivo_temporario);
                    rename("arquivo_temporario.txt", "trajetos_cadastrados.txt");
                }else{
                    printf("Não existem trajetos cadastrados ou não foi possivel abrir os arquivos trajetos_cadastrados e arquivo_temporario. Tente novamente!\n"); //Caso não abra o arquivo ou ele não exista, sera mostrado esta mensagem na tela
                }
                
                if(find == 0){ //Caso nao for encontrada uma parada com o numero digitado
                    printf("Não foi localizada uma parada com o numero: %d\n", parada_excluir);
                }
                
                break;
            case '7':
                
                arquivo_trajetos_cadastrados = fopen("trajetos_cadastrados.txt", "r"); //Abre todos os arquivos que serão utilizados nesta função
                arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "r");
                arquivo_temporario2 = fopen("arquivo_temporario2.txt", "a");
                arquivo_temporario3 = fopen("arquivo_temporario3.txt", "a");
                find = 0;
                
                if (arquivo_linhas_cadastrados != NULL && arquivo_temporario2 != NULL){ //Verifica se os arquivos existem e foram abertos
                    
                    printf("Digite o número da linha que deseja excluir: \n");
                    scanf("%d", &linha_excluir); //Faz a leitura da linha que o usuario deseja excluir
                    
                    while(!feof(arquivo_linhas_cadastrados)){ //Enquanto não for o final do arquivo
                        fscanf(arquivo_linhas_cadastrados, "%d\n", &numero_linha); //Vai ler toda a linha do arquivo
                        if(linha_excluir != numero_linha){ //Verifica se o numero digitado é diferente do que esta no arquivo
                            fprintf(arquivo_temporario2, "%d\n", numero_linha); //Caso seja diferente irá gravar toda a linha em um outro arquivo
                            
                        }else{
                            printf("Linha e trajetos vinculados à ela serão excluidas: %d\n", numero_linha); //Caso seja igual não será escrita no arquivo
                            find = 1; //Se existir uma parada com o mesmo numero digitado dentro do arquivo atribuirá verdadeiro a essa variável
                        }
                    }
                    fclose(arquivo_linhas_cadastrados); //fechara os dois arquivos, removera o arquivo original e renomeara o aquivo novo com o nome do que foi removido
                    remove("cadastro_linhas.txt"); 
                    fclose(arquivo_temporario2);
                    rename("arquivo_temporario2.txt", "cadastro_linhas.txt");
                }else{
                    printf("Não existem linhas cadastradas ou foi possivel abrir os arquivos cadastro_linhas e arquivo_temporario2. Tente novamente!\n"); //Caso não abra o arquivo ou ele não exista, sera mostrado esta mensagem na tela
                    
                }
                
                if (arquivo_trajetos_cadastrados != NULL && arquivo_temporario3 != NULL) { //Verifica se os arquivos existem e foram abertos
                    while(!feof(arquivo_trajetos_cadastrados)){ //Enquanto não for o final do arquivo
                        fscanf(arquivo_trajetos_cadastrados, "%d;%d;%d:%d\n", &parada.numero_parada, &numero_linha, &horario.hora, &horario.min); //Vai ler toda a linha do arquivo
                        if(linha_excluir != numero_linha){ //Verifica se o numero digitado é diferente do que esta no arquivo
                            fprintf(arquivo_temporario3, "%d;%d;%d:%d\n", parada.numero_parada, numero_linha, horario.hora, horario.min); //Caso seja diferente irá gravar toda a linha em um outro arquivo
                            
                        }
                    }
                    fclose(arquivo_trajetos_cadastrados); //fechara os dois arquivos, removera o arquivo original e renomeara o aquivo novo com o nome do que foi removido
                    remove("trajetos_cadastrados.txt");
                    fclose(arquivo_temporario3);
                    rename("arquivo_temporario3.txt", "trajetos_cadastrados.txt");
                }else{
                    printf("Não existem trajetos cadastrados ou não foi possivel abrir os arquivos trajetos_cadastrados e arquivo_temporario3. Tente novamente!\n"); //Caso não abra o arquivo ou ele não exista, sera mostrado esta mensagem na tela
                }
                
                if(find == 0){ //Caso nao for encontrada uma linha com o numero digitado
                    printf("Não foi localizada uma linha com o numero: %d\n", linha_excluir);
                }
                
                break;
            case '8':
                return 0;
            break;
            default:
            printf("Opção inválida. Digite novamente!\n"); // Caso venha a ser digitada um número diferente do menu de opções
            
        }
    }while(opcao != SAIR);
    
    return 0;
}
//-------------------------------------------------Funções----------------------------------------------------------------------

// 1) Verificar se há duplicidade no cadastro de paradas

int valida_parada(int numero_parada, FILE *arquivo_paradas_cadastradas){
    
    int existente;
    int numero_parada_arquivo; // Variáveis auxiliares que serão usadas na função
    float late, longe;
    existente = 0;
    numero_parada_arquivo = 0;

    arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "r"); // Abrir o arquivo para leitura

    if(arquivo_paradas_cadastradas != NULL){ // Verificar se o arquivo foi aberto
        
        while(!feof(arquivo_paradas_cadastradas)) { // Enquanto não for o final do arquivo ele irá ficar comparando para ver se acha uma parada que ja esteja cadastrada
            fscanf(arquivo_paradas_cadastradas, "%d;%f;%f\n", &numero_parada_arquivo, &late, &longe); // Ler os dados do arquivo
            if (numero_parada == numero_parada_arquivo){ // Comparar o numero que tem no arquivo com o digitado para ver se já existe um cadastro com aquele número
                existente = 1; // Se for igual vai me retornar verdadeiro
                break;
            }
        }
        fclose(arquivo_paradas_cadastradas);
    }
    return existente;
}

// 2) Verificar se há duplicidade nas linhas ja cadastradas

int valida_linha(int numero_linha, FILE *arquivo_linhas_cadastrados){
    
    int existente; 
    int numero_linha_arquivo; // Variáveis auxiliares que serão usadas na função
    existente = 0;
    numero_linha_arquivo = 0;

    arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "r"); // Abrir o arquivo para leitura

    if(arquivo_linhas_cadastrados != NULL){ // Verificar se o arquivo foi aberto
        
        while(!feof(arquivo_linhas_cadastrados)) { // Enquanto não for o final do arquivo ele irá ficar comparando para ver se acha uma linha que ja esteja cadastrada
            fscanf(arquivo_linhas_cadastrados, "%d\n", &numero_linha_arquivo); // Ler os dados do arquivo
            if (numero_linha == numero_linha_arquivo){ // Comparar o numero que tem no arquivo com o digitado para ver se já existe um cadastro com aquele número
                existente = 1; // Se for igual vai me retornar verdadeiro
                break;
            }
        }
        fclose(arquivo_linhas_cadastrados);
    }
    return existente;
}

// 3) Verificar se a linha que deseja cadastrar o trajeto existe

int existencia_linha(int numero_linha, FILE *arquivo_linhas_cadastrados){

    int existente;
    int numero_linha_arquivo; // Variáveis auxiliares que serão usadas na função
    existente = 0;
    numero_linha_arquivo = 0;

    arquivo_linhas_cadastrados = fopen("cadastro_linhas.txt", "r"); // Abrir o arquivo para leitura

    if(arquivo_linhas_cadastrados != NULL){ // Verificar se o arquivo foi aberto
        
        while(!feof(arquivo_linhas_cadastrados)) { // Enquanto não for o final do arquivo ele irá ficar comparando para ver se acha uma linha que ja esteja cadastrada
            fscanf(arquivo_linhas_cadastrados, "%d\n", &numero_linha_arquivo); // Ler os dados do arquivo
            if (numero_linha == numero_linha_arquivo){ // Comparar os numeros das linhas para ver se há uma linha já existente com aquele número
                existente = 1; // Se for igual vai me retornar verdadeiro
                break;
            }
        }
        fclose(arquivo_linhas_cadastrados);
    }
    return existente;
}

// 4) Verificar se a parada que deseja cadastrar o trajeto existe

int existencia_parada(int numero_parada, FILE *arquivo_paradas_cadastradas){
    
int existente; 
int numero_parada_arquivo;// Variáveis auxiliares que serão usadas na função
float late, longe;
existente = 0;
numero_parada_arquivo = 0;

    arquivo_paradas_cadastradas = fopen("localizacao_paradas.txt", "r"); // Abrir o arquivo para leitura

    if(arquivo_paradas_cadastradas != NULL){ // Verificar se o arquivo foi aberto
        
        while(!feof(arquivo_paradas_cadastradas)) { // Enquanto não for o final do arquivo ele irá ficar comparando para ver se acha uma parada que ja esteja cadastrada
            fscanf(arquivo_paradas_cadastradas, "%d;%f;%f\n", &numero_parada_arquivo, &late, &longe); // Ler os dados do arquivo
            
            if (numero_parada == numero_parada_arquivo){ // Comparar os numeros das paradas para ver se há uma parada já existente com aquele número
                existente = 1; // Se for igual vai me retornar verdadeiro
                break;
            }
        }
        fclose(arquivo_paradas_cadastradas);
    }
    return existente;
}

// 5) Verificar a hora e o minuto

int valida_hora_min(int hora, int min){
	int verificar; // Variáveis auxiliares que serão usadas na função
	verificar = 0;
	if(hora >= 0 && hora < 23){ // Condicionais para validar a veracidade da hora
		if(min >= 0 && min < 59){
			verificar = 1;
		}
	}
	return verificar;
}

// 6) Verificar se a latitude e longitude digitadas são válidas

int existencia_lat_long(float latitude, float longitude){
    
    int existente; // Variáveis auxiliares que serão usadas na função
    existente = 0;

    if (latitude < 90.000000 && latitude > -90.000000 && longitude < 180.000000 && longitude > -180.000000){ //Verifica se a latitude e a longitude digitadas são válidas ou não
        existente = 1; //Caso sejam verdadeiras será atribuido verdadeiro a esta variável
    }else{
        existente = 0; //Caso seja falso será atribuido falso a esta variável
    }

    return existente;
}
