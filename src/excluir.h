int excluir(int *tamanho_struct){
    int idb = 0, flag = 0, opc = 0, esc = 0;
    do{//laco de repeticao para conferencia
        flag = 0;
        printf("Digite o ID do filme que deseja excluir\nDigite 0 para cancelar\n-> ");
        scanf("%i", &idb);
        if (idb == 0){
            return 0;
        }
        
        for (int i = 0; i < 20; i++) {
            if (idb == filme[i].id) {
                flag = 1;
                printf("\nnome: %s\n", filme[i].nome);
                printf("sala: %s\n", filme[i].sala);
                printf("Horario: %s\n", filme[i].hora);
                printf("Valor: %.2f\n\n", filme[i].valor);
                printf("Tem certeza que deseja excluir esse filme? (Essa acao nao sera reversivel)\n[1]Sim\n[2]Nao\n->");
                scanf("%i", &esc);
                    if(esc == 1){
                    filme[i].id = -1;
                    strcpy(filme[i].nome, " \n");
                    strcpy(filme[i].sala, " \n");
                    strcpy(filme[i].hora, " \n");
                    filme[i].valor = 0;
                    printf("Filme excluido com sucesso!\n");
                    break;
                }
            }
        }
        if (flag != 1) {
            printf("Filme nao encontrado!\n");
            printf("Deseja digitar novamente o ID do filme?\n[1]Sim\n[2]Nao: ");
            scanf("%i", &opc);
        } else {
            opc = 2;
        } 
    }while (opc != 2);
    finit(tamanho_struct);
}