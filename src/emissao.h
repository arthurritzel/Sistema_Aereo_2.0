int emissao(int *tamanho_struct){
    int idb, i, very = 0, flag = 0, very2 = 0, cons, esc2;
    char nome[40];
    int idade;
    int assentos[7][4], k = 0, esc, very3;

    //atribui a matriz de assentos valores crescentes
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 4; j++){
            k++;
            assentos[i][j] = k;
        }
    }

    FILE *ingresso;
    ingresso = fopen("ingresso.txt", "w");
    if (ingresso == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        return 0;
    }

    do{//laco de repeticao da emissai
        very = 1;
        printf("Deseja consultar os filmes\n[1]Sim\n[2]Nao\n[3]Cancelar\n->");
        scanf("%i", &cons);
        if (cons == 1){
            //Inicia a funcao consluta que esta no aqruivo consulta.h
            consulta(tamanho_struct);
        }else if(cons == 3){
            return 0;
        }
        
        printf("Digite o id do filme para emitir: ");
        scanf("%i", &idb);
        
        for (i = 0; i < *tamanho_struct; i++){
            if(idb == filme[i].id){//verifica existencia do ID da ingresso
                fflush(stdin);
                printf("Digite seu nome completo: ");
                gets(nome);
                fflush(stdin);
                do{//laco para idade
                    printf("Digite sua idade: ");
                    scanf("%i", &idade);
                    if(16 < idade){
                    printf("----------------------------------------\n\n");
                    printf("|                 TELA                 |\n");  
                    printf("----------------------------------------\n\n");
                    for (int i = 0; i < 7; i++){// exibicao dos assentos
                        printf("\t");
                        for (int j = 0; j < 4; j++){   
                            printf("| %.2i |", assentos[i][j]);   
                        }
                        printf("\n");
                    }
                    do{//laco de verificacao do assento
                        fflush(stdin);
                        printf("Qual assento deseja: ");
                        scanf("%i", &esc);
                        if (esc >= 1 && esc <= 28){
                            very3 = 0;
                            for (int i = 0; i < 7; i++){
                                for (int j = 0; j < 4; j++){
                                    if(esc == assentos[i][j]){//substitue o assento escolhido por 0
                                        assentos[i][j] = 0;
                                    }
                                }
                            }

                        }else{
                            printf("Valor invalido!\n");
                            very3 = 1;
                        }
                    }while(very3 != 0);
                        very2 = 1;
                        printf("----------------------------------------\n");
                        printf("|             CINE PANAMBI             |\n");
                        printf("----------------------------------------\n\n");
                        printf("----------------------------------------\n");
                        printf("NOME: %s\n", nome);
                        printf("IDADE: %i\n", idade);
                        printf("----------------------------------------\n\n");
                        printf("-------------------\n");
                        printf("id: %i\n", filme[i].id);
                        printf("nome: %s\n", filme[i].nome);
                        printf("sala: %s\n", filme[i].sala);
                        printf("Horario: %s\n", filme[i].hora);
                        printf("Valor: %.2f\n", filme[i].valor);
                        printf("-------------------\n\n");
                        printf("----------------------------------------\n");
                        printf("|           MAPA DE POLTRONAS          |\n");
                        printf("----------------------------------------\n\n");
                        printf("----------------------------------------\n\n");
                        printf("|                 TELA                 |\n");  
                        printf("----------------------------------------\n\n");
                                              
                        for (int i = 0; i < 7; i++){
                                printf("\t");
                                for (int j = 0; j < 4; j++){  //exibe os assentos 
                                    if(assentos[i][j] != 0){
                                        printf("| %.2i |", assentos[i][j]);//o assento escolhido anteriormente sera o unico com valor de 0 assim sera substituido por XX 
                                    }else{
                                        printf("| xx |");
                                    }
                                }
                                printf("\n");
                            }  
                        printf("Confirmar ingresso?\n[1]Sim\n[2]Nao\n->");
                        scanf("%i", &esc2);//caso confirmada grava os dados no arquivo txt
                        if (esc2 == 1){
                            fprintf(ingresso, "----------------------------------------\n");
                            fprintf(ingresso, "|             CINE PANAMBI             |\n");
                            fprintf(ingresso, "----------------------------------------\n\n");
                            fprintf(ingresso, "----------------------------------------\n");
                            fprintf(ingresso, "NOME: %s\n", nome);
                            fprintf(ingresso, "IDADE: %i\n", idade);
                            fprintf(ingresso, "----------------------------------------\n\n");
                            fprintf(ingresso, "-------------------\n");
                            fprintf(ingresso, "id: %i\n", filme[i].id);
                            fprintf(ingresso, "nome: %s\n", filme[i].nome);
                            fprintf(ingresso, "sala: %s\n", filme[i].sala);
                            fprintf(ingresso, "Horario: %s\n", filme[i].hora);
                            fprintf(ingresso, "Valor: %.2f\n", filme[i].valor);
                            fprintf(ingresso, "-------------------\n\n");
                            fprintf(ingresso, "----------------------------------------\n");
                            fprintf(ingresso, "|           MAPA DE POLTRONAS          |\n");
                            fprintf(ingresso, "----------------------------------------\n\n");
                            fprintf(ingresso, "----------------------------------------\n\n");
                            fprintf(ingresso, "|                 TELA                  |\n");  
                            fprintf(ingresso, "----------------------------------------\n\n");
                            for (int i = 0; i < 7; i++){
                                    fprintf(ingresso, "\t");
                                    for (int j = 0; j < 4; j++){   
                                        if(assentos[i][j] != 0){
                                            fprintf(ingresso, "| %.2i |", assentos[i][j]);   
                                        }else{
                                            fprintf(ingresso, "| xx |");
                                        }
                                    }
                                    fprintf(ingresso, "\n");
                                }  
                            fclose(ingresso);
                            flag = 1;
                            very = 1;
                            printf("\nIngresso emitido com sucesso!\n");
                        }else{
                            printf("Ingresso cancelado\n");
                            very = 1;
                            flag = 1;
                        }
                        break;
                    }else{
                        printf("Voce precisa ser maior de 16 anos!\n");
                        very2 = 0;
                    }
                }while(very2 != 1);
            }
        }
        if(flag != 1){
            system("clear");
            printf("\nId invalido, tente novamente!\n");
            very = 0;
        }

    }while(very != 1);
}

