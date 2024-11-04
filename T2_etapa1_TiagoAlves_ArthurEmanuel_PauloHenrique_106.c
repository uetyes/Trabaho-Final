#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define TAM 3
#define TAM_STRING 50

typedef struct{
    char nome[TAM_STRING];
    int codigo;
} cadastro;


void line(){
    for(int i = 0;i < 50;i++){
        printf("*");//função para printar a linha
    }
    printf("\n");
}

typedef struct{
    int codigo_prato;
    int codigo_resturante;
    char descricao[TAM_STRING];
    float preco;
} restaurante;

int main(){
    
    cadastro *cad = NULL;
    restaurante *rest = NULL;
    int i, escolha = 0;
    char nome_restaurante[TAM_STRING]; 

    //alocaçoes dinamicas para trabalhar com as structs como vetores
    cad = (cadastro *) malloc (TAM * sizeof(cadastro));
    if(cad == NULL){
        printf("Erro!");
        return 1;
    }

    rest = (restaurante * ) malloc (12 * sizeof(restaurante));
    if(rest == NULL){
        printf("Erro!");
        return 1;
    }

    line();
    printf("uaiFood - Restaurante\n");
    line();

    //laço para ler os dados dos restaurantes e pratos

    for(i = 0; i < 3; +i++){
        printf("Cadastre o codigo e o nome do restaurante %d:\n", i+1);
        scanf("%d %[^\n]", &cad[i].codigo, cad[i].nome);


            printf("Cadastre o codigo do prato, codigo do restaurante, descricao e preco dos pratos %s:\n", cad[i].nome);

            for(int j = 0; j < 4;j++){
                scanf("%d %d %[^\n]", &rest[i * 4 + j].codigo_prato, &rest[i * 4 +j].codigo_resturante, rest[i * 4 +j].descricao); //nao está lendo o preço

                //encontrar o os ultimos espaços na string
                char *last_space = strrchr(rest[i * 4 + j].descricao, ' ');
                if(last_space != NULL){
                    rest[i * 4 +j].preco = atof(last_space + 1); //converter para float
                    *last_space = '\0'; //garantir que a string termine com o \0
                }

            }
    }

    //int varivael_comparavel = 0;
     while (1) {
        printf("\nLOGIN UAIFOOD RESTAURANTE\n");
        printf("Digite o codigo do restaurante (ou um numero negativo para sair):\n");
        int codigo_restaurante;
        scanf("%d", &codigo_restaurante);
        if (codigo_restaurante < 0) {
            break; // Sair do loop se o usuário digitar um número negativo
        }

        // Verificar se o restaurante existe
        int veri = 0;
        int opcao;
        for (i = 0; i < 3 ;i++) {
                if (codigo_restaurante == cad[i].codigo) {
                    veri = 1;
                    int cond = 1;
                    int cond2 = 1;
                    while(cond2){
                    printf("\n%s - Menu de Opcoes\n", cad[i].nome);//mostrar o menu
                    printf("1- Mostra pratos\n");
                    printf("0 - Logout\n");
                    scanf("%d", &escolha);
                    if (escolha == 1) {//observar se a escolha foi 1
                        while(cond){
                        printf("%s - Pratos - Menu de Opcoes\n", cad[i].nome);
                        for (int j = 0; j < 4; j++) {
                            printf("%d - %s - Preco: R$ %.2f\n", rest[i * 4 + j].codigo_prato,rest[i * 4 + j].descricao, rest[i *4 + j].preco);
                        }
                        printf("0 - Voltar ao menu anterior\n");
                        scanf("%d",&opcao);
                        if(opcao >= 1 && opcao <= 4){
                            printf("Codigo do prato: %d\nCodigo do restaurante: %d\nNome do prato: %s\nPreco: %.2f\n",rest[i * 4 + opcao - 1].codigo_prato,rest[i * 4 + opcao - 1].codigo_resturante,rest[i * 4 + opcao - 1].descricao,rest[i * 4 +opcao - 1].preco);
                        }
                        else if(escolha == 0){
                            cond = 0;
                        }
                        
                    else if(opcao > 4 || opcao < 0){
                        printf("\nPrato nao exitente.Digite um numero valido\n");
                    }
                    else{
                    break; // Sair do loop após encontrar o restaurante
                    }
                        }
                    }
                    else if(escolha == 0){// se a escolha for 0 termina o loop
                        cond2 = 0;
                    }
                }    
            }
        }
         if(!veri){
                printf("\nRestaurante nao escontrado.Tente novamente.\n");
    }
    }
  free(cad);
    free(rest);

return 0;
}