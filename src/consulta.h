int consulta(int *tamanho_struct){
    int opc = 0, idb, flag = 0, very = 0;
    printf("%i", *tamanho_struct);
    printf("Deseja:\n[1]Filtrar a busca\n[2]Apresentar todos os filmes\n[3]Cancelar\n->");
    scanf("%i", &opc);
    if(opc == 1){
        do{//laco para verificacao de filtro
            printf("Digite o id do filme: ");
            scanf("%i", &idb);
            for (int i = 0; i < *tamanho_struct; i++){
                if(idb == filme[i].id){//preocura o assento com o mesmo id digitado
                    printf("-------------------\n");
                    printf("id: %i\n", filme[i].id);
                    printf("nome: %s\n", filme[i].nome);
                    printf("sala: %s\n", filme[i].sala);
                    printf("Horario: %s\n", filme[i].hora);
                    printf("Valor: %.2f\n", filme[i].valor);
                    printf("-------------------\n");
                    flag = 1;
                }
            }
            if(flag != 1){
                printf("\nFilme nao encontrado!\n");
                printf("Deseja buscar outro filme?\n[1]Sim\n[2]Nao\n->");
                scanf("%i", &very);
            }else{
                very = 2;
            }
        }while(very != 2);
    }else if(opc == 2){
        for (int i = 0; i < *tamanho_struct; i++){
                printf("Id: %i\n", filme[i].id);
                printf("nome: %s\n", filme[i].nome);
                printf("sala: %s\n", filme[i].sala);
                printf("Horario: %s\n", filme[i].hora);
                printf("Valor: %.2f\n", filme[i].valor);
                printf("-----------------------------\n\n");
        }
    }else{
        return 0;
    }
}