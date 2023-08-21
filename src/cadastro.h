int cadastro(){
    int idcad = 0;
    int veryc = 1;
    do{//laco de verificacao de existencia de id
        printf("Digite o id do filme\nDigite 0 para cancelar\n-> ");
        scanf("%i", &idcad);
        if (idcad == 0){
            return 0;
        }
        
        for (int i = 0; i < 20; i++){
            if(idcad == voo[i].id){
                printf("Esse id ja esta cadastrado!\n");
                veryc = 0;
                break;
            }else{
                veryc = 1;
            }
        }
    }while(veryc != 1);
    for (int i = 0; i < 20; i++){//procura o preimeiro espaco da struct com id -1(vazio)
        if (voo[i].id == -1){
            voo[i].id = idcad;
            fflush(stdin);
            printf("Digite o ponto de partida do voo: ");
            gets(voo[i].partida);
            strcat(voo[i].partida, "\n");
            fflush(stdin);
            printf("Digite o destino do voo: ");
            gets(voo[i].destino);
            strcat(voo[i].destino, "\n");
            fflush(stdin);
            printf("Digite o horario do voo: ");
            gets(voo[i].hora);
            strcat(voo[i].hora, "\n");
            fflush(stdin);
            printf("Digite o valor do voo: ");
            scanf("%f", &voo[i].valor);
            fflush(stdin);
            printf("VOO CADASTRADO COM SUCESSO!\n");
            break;
        }
    }
    finit();
}