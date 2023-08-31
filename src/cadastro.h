int cadastro(int *tamanho_struct){
    int idcad = 0;
    int veryc = 1;
    do{//laco de verificacao de existencia de id
    printf("%i", *tamanho_struct);
        printf("Digite o id do filme\nDigite 0 para cancelar\n-> ");
        scanf("%i", &idcad);
        if (idcad == 0){
            return 0;
        }
        
        for (int i = 0; i < *tamanho_struct; i++){
            if(idcad == filme[i].id){
                printf("Esse id ja esta cadastrado!\n");
                veryc = 0;
                break;
            }else{
                veryc = 1;
            }
        }
    }while(veryc != 1);
        filme = (struct dados*) realloc(filme, (*tamanho_struct+1) * sizeof(struct dados));
        filme[*tamanho_struct].id = idcad;
        fflush(stdin);
        printf("Digite o ponto de partida do filme: ");
        gets(filme[*tamanho_struct].partida);
        strcat(filme[*tamanho_struct].partida, "\n");
        fflush(stdin);
        printf("Digite o destino do filme: ");
        gets(filme[*tamanho_struct].destino);
        strcat(filme[*tamanho_struct].destino, "\n");
        fflush(stdin);
        printf("Digite o horario do filme: ");
        gets(filme[*tamanho_struct].hora);
        strcat(filme[*tamanho_struct].hora, "\n");
        fflush(stdin);
        printf("Digite o valor do filme: ");
        scanf("%f", &filme[*tamanho_struct].valor);
        fflush(stdin);
        printf("filme CADASTRADO COM SUCESSO!\n");

        *tamanho_struct += 1;
    finit(tamanho_struct);
}