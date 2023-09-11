#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//RODAR O CODIGO A PARTIR DO .EXE ASSIM O CAMINHO DE ACESSO AO BANCO DE DADOS FICA CORRETO!
struct dados{
        int id;
        char nome[20];
        char sala[20];
        char hora[20];
        float valor;
    }*filme;

void logo(){
    //funcao apenas para mostrar a logo ao usuario
    printf("             ___________________________________________________\n");
    printf("            /  ________     __     __       __    _______    / /\n");
    printf("           /  / ______//   / //   / ||     / //  / _____//  / / \n");
    printf("          /  / /          / //   /  / |   / //  / /____    / /\n");
    printf("         /  / /          / //   /  / | |_/ //  / _____//  / /\n");
    printf("        /  / /______    / //   /  /   |   //  / /_____   / /\n");
    printf("       /  /________//  /_//   /  /    |__//  /_______// / /\n");
    printf("      /________________________________________________/_/\n");
    printf("      |___________________| PANAMBI |_________________/_/\n");
    printf("      /                                              / /\n");
    printf("     /                  ( )___( )                   / /\n");
    printf("    /                 _Y         Y_                / /\n");
    printf("   /                  |   @   @   |               / /\n");
    printf("  /                    Y  (* *)  Y               / /\n");
    printf(" /                      Y______ Y               / /\n");
    printf("/______________________________________________/_/\n");
}
int init(int *tamanho_struct){
    //le os dados do arquivo banco-filmes.txt e armazena na struct, o arquivo esta sendo usado como banco de dados
    FILE *file;
    file = fopen("banco-filmes.txt", "r");
    if (file == NULL){
        printf("Problemas na consulta do banco de dados\n");
        return 0;
    }
    
    char vet[20], aux[20];
    int cont = 0, i = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, mal = 0;

    while (fgets(vet, 100, file) != NULL){
        
        if(mal == 0){
            filme = (struct dados*) malloc(sizeof(struct dados));
            mal++;
            if(filme == NULL){
                printf("Erro na alocacao");
                    
            }   
        }
        
        if(cont == 0){
            strcpy(aux, vet);
            filme[i].id = atoi(aux);
            i++;
            *tamanho_struct += 1;
            filme = (struct dados*) realloc(filme, (*tamanho_struct+1) * sizeof(struct dados));
        }

        if(cont == 1){
            strcpy(aux, vet);
            strcpy(filme[i2].nome, aux);
            i2++;
        }
        if(cont == 2){
            strcpy(aux, vet);
            strcpy(filme[i3].sala, aux);
            i3++;
        }
        if(cont == 3){
            strcpy(aux, vet);
            strcpy(filme[i4].hora, aux);
            i4++;
        }
        if(cont == 4){
            strcpy(aux, vet);
            filme[i5].valor = atof(aux);
            i5++;
        }
        cont++;
        if (cont >=5){
            cont = 0;
        }   
        
    }
    fclose(file);
    return 0;
}

int finit(int *tamanho_struct){
    //armazena todos os dados da struct filmes no arquivo banco-filmes.txt
    FILE *file;
    file = fopen("banco-filmes.txt", "w");
    if (file == NULL){
        printf("Problemas na gravacao do banco de dados\n");
        return 0;
    } 
    for (int i = 0; i < *tamanho_struct; i++)
    {
        fprintf(file, "%i\n", filme[i].id);
        fprintf(file, "%s", filme[i].nome);
        fprintf(file, "%s", filme[i].sala);
        fprintf(file, "%s", filme[i].hora);
        fprintf(file, "%f\n", filme[i].valor);
    }
    fclose(file);
    return 0;
}

#include "src/consulta.h"
#include "src/cadastro.h"
#include "src/excluir.h"
#include "src/atualizar.h"
#include "src/emissao.h"

int main(){
    int tamanho_struct = 0;
   
    init(&tamanho_struct);

    int escolha, very = 0, very3 = 0, esc = 0, flag = 0, very4 = 0, esc_cl;
    char senha[15], confsenha[15] = "12345";
    
    do{//laco de repeticao do sistema
        system("clear");
        logo();

        // Primeira perguta ao usuario
        printf("Selecione sua opcao\n[1]Cliente\n[2]ADM\n[3]Sair\n->");
        scanf("%i", &esc);
        switch (esc){
        case 1:
            do{//laco de repeticao das escolhas do cliente
                very4 = 1;
                very = 1;
                flag = 0;
                system("clear");
                logo();

                printf("Seja bem vindo!\n\nSelecione sua acao\n[1]Consultar filmes\n[2]Emitir ingresso\n[3]Voltar\n->");
                scanf("%i", &esc_cl);
                switch (esc_cl){
                case 1:
                    system("clear");
                    printf("------------------------------------------\n");
                    printf("|           Consulta de Filmes           |\n");
                    printf("------------------------------------------\n");
                    //Inicia a funcao consluta que esta no aqruivo consulta.h
                    consulta(&tamanho_struct);

                    break;
                case 2:
                    system("clear");
                    printf("----------------------------------------\n");
                    printf("|            Emitir Ingresso           |\n");
                    printf("----------------------------------------\n");
                    //Inicia a funcao emissao que esta no aqruivo emissao.h
                    emissao(&tamanho_struct);

                    break;
                case 3:
                    very4 = 0;
                    flag = 1;
                default:
                    break;
                }
                if(flag != 1){
                    printf("[1]Voltar\n->");
                    scanf("%i", &very4);
                }
            }while(very4 != 0);
            break;
        case 2:
            do{//laco de repeticao para conferencia da senha
                flag = 0;
                fflush(stdin);
                //realizando a leitura e conferencia da senha
                printf("Digite a senha de acesso: ");
                gets(senha);
                fflush(stdin);
                if(!strcmp(senha, confsenha)){
                    do{//laco de repeticao para crud
                        very3 = 2;
                        very4 = 0;
                        flag = 0;
                        system("clear");
                        logo();

                        printf("Escolha sua acao!\n[1]Consultar filmes\n[2]Cadastrar filmes\n[3]Atualizar filme\n[4]Excluir filme\n[5]Voltar\n->");
                        scanf("%i", &escolha);
                        switch (escolha){
                        case 1:
                            /* Consulta */
                            system("clear");
                            very = 1;
                            printf("------------------------------------------\n");
                            printf("|           Consulta de filmes           |\n");
                            printf("------------------------------------------\n");
                            //Inicia a funcao consulta que esta no aqruivo consulta.h
                            consulta(&tamanho_struct);

                            break;
                        case 2:
                            /* Cadastro */
                            system("clear");
                            very = 1;
                            printf("------------------------------------------\n");
                            printf("|           Cadastro de filme            |\n");
                            printf("------------------------------------------\n");
                            //Inicia a funcao cadastro que esta no aqruivo cadastro.h
                            cadastro(&tamanho_struct);

                        break;
                        case 3:
                            /* Atualizacao */
                            system("clear");
                            very = 1;
                            printf("------------------------------------------\n");
                            printf("|           Atualizacao de filme         |\n");
                            printf("------------------------------------------\n");
                            //Inicia a funcao atualizar que esta no aqruivo atualizar.h
                            atualizar(&tamanho_struct);

                        break;
                        case 4:
                            /* Excluir */
                            system("clear");
                            very = 1;
                            printf("------------------------------------------\n");
                            printf("|              Excluir filme             |\n");
                            printf("------------------------------------------\n");
                            //Inicia a funcao excluir que esta no aqruivo excluir.h
                            excluir(&tamanho_struct);

                        break;
                        case 5:
                            very = 1;
                            very4 = 0;
                            flag = 1;
                            break;
                        default:
                            system("clear");
                            printf("Opcao invalida!\n");
                            very = 1;
                            break;
                        }
                        if(flag != 1){
                            printf("[1]Voltar\n->");
                            scanf("%i", &very4);
                        }
                    }while(very4 != 0);
                }else{
                    printf("Senha Invalida!\n");
                    printf("Tentar novamente?\n[1]Sim\n[2]Nao\n->");
                    scanf("%i", &very3);
                }
            }while(very3 != 2);
            break;

        case 3:
            printf("Ate a proxima!");
            very = 0;
            break;
        default:
            break;
        }
    }while(very != 0);
    finit(&tamanho_struct);
    free(filme);
}   