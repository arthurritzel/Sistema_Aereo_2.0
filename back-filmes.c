#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ESTE ARQUIVO É APENAS UM BACKUP DO BANCO DE DADOS
struct dados{
        int id;
        char nome[20];
        char sala[20];
        char hora[20];
        float valor;
    }filme[10];
    int atr(){
        filme[0].id = 1;
        strcpy(filme[0].nome, "Sao Paulo");
        strcpy(filme[0].sala, "Rio de Janeiro");
        strcpy(filme[0].hora, "11:30");
        filme[0].valor = 1000;

        filme[1].id = 2;
        strcpy(filme[1].nome, "Belo Horizonte");
        strcpy(filme[1].sala, "Salvador");
        strcpy(filme[1].hora, "14:45");
        filme[1].valor = 1500;

        filme[2].id = 3;
        strcpy(filme[2].nome, "Recife");
        strcpy(filme[2].sala, "Fortaleza");
        strcpy(filme[2].hora, "09:20");
        filme[2].valor = 1200;

        filme[3].id = 4;
        strcpy(filme[3].nome, "Porto Alegre");
        strcpy(filme[3].sala, "Curitiba");
        strcpy(filme[3].hora, "08:30");
        filme[3].valor = 800;

        filme[4].id = 5;
        strcpy(filme[4].nome, "Brasilia");
        strcpy(filme[4].sala, "Manaus");
        strcpy(filme[4].hora, "13:15");
        filme[4].valor = 1800;

        filme[5].id = 6;
        strcpy(filme[5].nome, "Porto Seguro");
        strcpy(filme[5].sala, "Natal");
        strcpy(filme[5].hora, "10:40");
        filme[5].valor = 1300;

        filme[6].id = 7;
        strcpy(filme[6].nome, "Florianopolis");
        strcpy(filme[6].sala, "Foz do Iguacu");
        strcpy(filme[6].hora, "15:50");
        filme[6].valor = 900;

        filme[7].id = 8;
        strcpy(filme[7].nome, "Sao Luis");
        strcpy(filme[7].sala, "Belem");
        strcpy(filme[7].hora, "12:20");
        filme[7].valor = 1100;

        filme[8].id = 9;
        strcpy(filme[8].nome, "Goiania");
        strcpy(filme[8].sala, "Cuiaba");
        strcpy(filme[8].hora, "14:00");
        filme[8].valor = 950;

        filme[9].id = 10;
        strcpy(filme[9].nome, "Joao Pessoa");
        strcpy(filme[9].sala, "Maceio");
        strcpy(filme[9].hora, "17:30");
        filme[9].valor = 1200;
    return 0;
}
int finit(){
    FILE *file;
    file = fopen("banco-filmes.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(file, "%i\n", filme[i].id);
        fprintf(file, "%s\n", filme[i].nome);
        fprintf(file, "%s\n", filme[i].sala);
        fprintf(file, "%s\n", filme[i].hora);
        fprintf(file, "%f\n", filme[i].valor);
    }
    fclose(file);
    return 0;
}
int main(){
    atr();
    finit();
}