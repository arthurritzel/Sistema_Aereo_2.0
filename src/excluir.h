int excluir(){
    int idb = 0, flag = 0, opc = 0, esc = 0;
    do{//laco de repeticao para conferencia
        flag = 0;
        printf("Digite o ID do filme que deseja excluir\nDigite 0 para cancelar\n-> ");
        scanf("%i", &idb);
        if (idb == 0){
            return 0;
        }
        
        for (int i = 0; i < 20; i++) {
            if (idb == voo[i].id) {
                flag = 1;
                printf("\nPartida: %s\n", voo[i].partida);
                printf("Destino: %s\n", voo[i].destino);
                printf("Horario: %s\n", voo[i].hora);
                printf("Valor: %.2f\n\n", voo[i].valor);
                printf("Tem certeza que deseja excluir esse filme? (Essa acao nao sera reversivel)\n[1]Sim\n[2]Nao\n->");
                scanf("%i", &esc);
                    if(esc == 1){
                    voo[i].id = -1;
                    strcpy(voo[i].partida, " \n");
                    strcpy(voo[i].destino, " \n");
                    strcpy(voo[i].hora, " \n");
                    voo[i].valor = 0;
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
    finit();
}