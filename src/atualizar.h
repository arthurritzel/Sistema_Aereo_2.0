int atualizar(){
    int idat, subs, exist = 0, new, new2 = 1, atualizado = 1;

    printf("Digite o ID do Filme que deseja atualizar\nDigite 0 para cancelar\n->");
    scanf("%i", &idat);
    if (idat == 0){
        return 0;
    }
    
    for (int i = 0; i < 20; i++){
        if(idat == voo [i].id){
            exist = 1;
        }
    }

    if(exist == 0){//verifica existencia do voo
        printf("\nFilme nao encontrado!\n");
    }else {  
        do{   
            printf("-------------------\n");
            for (int i = 0; i < 20; i++){
                if(idat == voo[i].id){
                    printf("Quais dados deseja substituir?\n");
                    printf("-------------------\n");
                    printf("id: %i\n", voo[i].id);
                    printf("[1] Partida: %s\n", voo[i].partida);
                    printf("[2] Destino: %s\n", voo[i].destino);
                    printf("[3] Horario: %s\n", voo[i].hora);
                    printf("[4] Valor: %.2f\n", voo[i].valor);
                    printf("[5] Alterar todos os dados\n");
                    printf("[6] Cancelar\n");
                    printf("-------------------\n");
                    new = i;                                        
                    scanf("%i", &subs);
                }
            }

            switch (subs) {                               
            case 1:
                printf("Partida: ");
                fflush(stdin);
                gets(voo[new].partida);
                strcat(voo[new].partida, "\n"); 
                atualizado=1;                                         
            break; 
            case 2:
                printf("Destino: ");
                fflush(stdin);
                gets(voo[new].destino);  
                strcat(voo[new].destino, "\n"); 
                atualizado=1;                                           
            break;
            case 3:
                printf("Horario: ");
                fflush(stdin);
                gets(voo[new].hora); 
                strcat(voo[new].hora, "\n");     
                atualizado=1;                                         
            break;
            case 4:
                printf("Valor: ");
                fflush(stdin);
                scanf("%f",&voo[new].valor); 
                atualizado=1;                                            
            break;    
            case 5:
                printf("Partida: ");
                fflush(stdin);
                gets(voo[new].partida);    
                strcat(voo[new].partida, "\n"); 
                fflush(stdin); 

                printf("Destino: ");
                fflush(stdin);
                gets(voo[new].destino);
                strcat(voo[new].destino, "\n");  
                fflush(stdin); 

                printf("Horario: ");
                fflush(stdin);
                gets(voo[new].hora);
                strcat(voo[new].hora, "\n");     
                fflush(stdin); 

                printf("Valor: ");
                fflush(stdin);
                scanf("%f",&voo[new].valor);      
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
    finit();
}