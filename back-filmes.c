#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTE ARQUIVO É APENAS UM BACKUP DO BANCO DE DADOS
struct dados{
        int id;
        char partida[20];
        char destino[20];
        char hora[20];
        float valor;
    }voo[20];
    int atr(){
        voo[0].id = 1;
        strcpy(voo[0].partida, "Sao Paulo");
        strcpy(voo[0].destino, "Rio de Janeiro");
        strcpy(voo[0].hora, "11:30");
        voo[0].valor = 1000;

        voo[1].id = 2;
        strcpy(voo[1].partida, "Belo Horizonte");
        strcpy(voo[1].destino, "Salvador");
        strcpy(voo[1].hora, "14:45");
        voo[1].valor = 1500;

        voo[2].id = 3;
        strcpy(voo[2].partida, "Recife");
        strcpy(voo[2].destino, "Fortaleza");
        strcpy(voo[2].hora, "09:20");
        voo[2].valor = 1200;

        voo[3].id = 4;
        strcpy(voo[3].partida, "Porto Alegre");
        strcpy(voo[3].destino, "Curitiba");
        strcpy(voo[3].hora, "08:30");
        voo[3].valor = 800;

        voo[4].id = 5;
        strcpy(voo[4].partida, "Brasilia");
        strcpy(voo[4].destino, "Manaus");
        strcpy(voo[4].hora, "13:15");
        voo[4].valor = 1800;

        voo[5].id = 6;
        strcpy(voo[5].partida, "Porto Seguro");
        strcpy(voo[5].destino, "Natal");
        strcpy(voo[5].hora, "10:40");
        voo[5].valor = 1300;

        voo[6].id = 7;
        strcpy(voo[6].partida, "Florianopolis");
        strcpy(voo[6].destino, "Foz do Iguacu");
        strcpy(voo[6].hora, "15:50");
        voo[6].valor = 900;

        voo[7].id = 8;
        strcpy(voo[7].partida, "Sao Luis");
        strcpy(voo[7].destino, "Belem");
        strcpy(voo[7].hora, "12:20");
        voo[7].valor = 1100;

        voo[8].id = 9;
        strcpy(voo[8].partida, "Goiania");
        strcpy(voo[8].destino, "Cuiaba");
        strcpy(voo[8].hora, "14:00");
        voo[8].valor = 950;

        voo[9].id = 10;
        strcpy(voo[9].partida, "Joao Pessoa");
        strcpy(voo[9].destino, "Maceio");
        strcpy(voo[9].hora, "17:30");
        voo[9].valor = 1200;

    for (int i = 10; i < 20; i++){
        voo[i].id = -1;
        strcpy(voo[i].partida, " ");
        strcpy(voo[i].destino, " ");
        strcpy(voo[i].hora, " ");
        voo[i].valor = 0;
    }
    return 0;
}
int finit(){
    FILE *file;
    file = fopen("banco-voos.txt", "w");
    for (int i = 0; i < 20; i++)
    {
        fprintf(file, "%i\n", voo[i].id);
        fprintf(file, "%s\n", voo[i].partida);
        fprintf(file, "%s\n", voo[i].destino);
        fprintf(file, "%s\n", voo[i].hora);
        fprintf(file, "%f\n", voo[i].valor);
    }
    fclose(file);
    return 0;
}
int main(){
    atr();
    finit();
}