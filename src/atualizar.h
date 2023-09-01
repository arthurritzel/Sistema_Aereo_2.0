int atualizar(int *tamanho_struct){
    int idat, subs, exist = 0, new, new2 = 1, atualizado = 1;

    printf("Digite o ID do Filme que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0){
        return 0;
    }
    
    for (int i = 0; i < *tamanho_struct; i++){
        if(idat == filme [i].id){
            exist = 1;
        }
    }

    if(exist == 0){//verifica existencia do filme
        printf("\nFilme nao encontrado!\n");
    }else {  
        do{   
            printf("-------------------\n");
            for (int i = 0; i < *tamanho_struct; i++){
                if(idat == filme[i].id){
                    printf("Quais dados deseja substituir?\n");
                    printf("-------------------\n");
                    printf("id: %i\n", filme[i].id);
                    printf("[1] nome: %s\n", filme[i].nome);
                    printf("[2] sala: %s\n", filme[i].sala);
                    printf("[3] Horario: %s\n", filme[i].hora);
                    printf("[4] Valor: %.2f\n", filme[i].valor);
                    printf("[5] Alterar todos os dados\n");
                    printf("[6] Cancelar\n");
                    printf("-------------------\n");
                    new = i;                                        
                    scanf("%i", &subs);
                }
            }

            switch (subs) {                               
            case 1:
                printf("nome: ");
                fflush(stdin);
                gets(filme[new].nome);
                strcat(filme[new].nome, "\n"); 
                atualizado=1;                                         
            break; 
            case 2:
                printf("sala: ");
                fflush(stdin);
                gets(filme[new].sala);  
                strcat(filme[new].sala, "\n"); 
                atualizado=1;                                           
            break;
            case 3:
                printf("Horario: ");
                fflush(stdin);
                gets(filme[new].hora); 
                strcat(filme[new].hora, "\n");     
                atualizado=1;                                         
            break;
            case 4:
                printf("Valor: ");
                fflush(stdin);
                scanf("%f",&filme[new].valor); 
                atualizado=1;                                            
            break;    
            case 5:
                printf("nome: ");
                fflush(stdin);
                gets(filme[new].nome);    
                strcat(filme[new].nome, "\n"); 
                fflush(stdin); 

                printf("sala: ");
                fflush(stdin);
                gets(filme[new].sala);
                strcat(filme[new].sala, "\n");  
                fflush(stdin); 

                printf("Horario: ");
                fflush(stdin);
                gets(filme[new].hora);
                strcat(filme[new].hora, "\n");     
                fflush(stdin); 

                printf("Valor: ");
                fflush(stdin);
                scanf("%f",&filme[new].valor);      
                fflush(stdin); 
                atualizado=1; 
            break; 
            case 6:        
                atualizado=0;   
            break;
            }
            if(atualizado == 1){
            printf("----------------------------------------\n");
            printf("|      Dados atualizados com sucesso!   |\n");
            printf("----------------------------------------\n");
            printf("\nDeseja alterar mais alguma informacao?\n");
            printf("[1]SIM\n");
            printf("[2]NAO\n");
            scanf("%i", &new2);                                  
            }else{
            printf("----------------------------------------\n");
            printf("|      Operacao Cancelada   |\n");
            printf("----------------------------------------\n");
            printf("\nDeseja alterar mais alguma informacao?\n");
            printf("[1]SIM\n");
            printf("[2]NAO\n");
            scanf("%i", &new2);                                   
            }
        }while(new2==1);                              
    }
    finit(tamanho_struct);
}