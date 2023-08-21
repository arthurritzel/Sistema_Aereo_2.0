int consulta(){
    int opc = 0, idb, flag = 0, very = 0;
    printf("Deseja:\n[1]Filtrar a busca\n[2]Apresentar todos os filmes\n[3]Cancelar\n->");
    scanf("%i", &opc);
    if(opc == 1){
        do{//laco para verificacao de filtro
            printf("Digite o id do filme: ");
            scanf("%i", &idb);
            for (int i = 0; i < 20; i++){
                if(idb == voo[i].id){//preocura o assento com o mesmo id digitado
                    printf("-------------------\n");
                    printf("id: %i\n", voo[i].id);
                    printf("Partida: %s\n", voo[i].partida);
                    printf("Destino: %s\n", voo[i].destino);
                    printf("Horario: %s\n", voo[i].hora);
                    printf("Valor: %.2f\n", voo[i].valor);
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
        for (int i = 0; i < 20; i++){
            if (voo[i].id != -1){//apresenta dodos os voos com id diferente de -1, adotamos -1 como voo excluido
                printf("Id: %i\n", voo[i].id);
                printf("Ponto de partida: %s\n", voo[i].partida);
                printf("Destino: %s\n", voo[i].destino);
                printf("Horario: %s\n", voo[i].hora);
                printf("Valor: %.2f\n", voo[i].valor);
                printf("-----------------------------\n\n");
            }
        }
    }else{
        return 0;
    }
}