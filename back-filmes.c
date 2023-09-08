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
        strcpy(filme[0].nome, "Matrix"); // Nome do filme
        strcpy(filme[0].sala, "Sala A"); // Cidade de exibição
        strcpy(filme[0].hora, "11:30"); // Horário de exibição
        filme[0].valor = 20.0;   

        filme[1].id = 2;
        strcpy(filme[1].nome, "Titanic");
        strcpy(filme[1].sala, "Sala B");
        strcpy(filme[1].hora, "14:45");
        filme[1].valor = 18.0;

        filme[2].id = 3;
        strcpy(filme[2].nome, "Jurassic Park");
        strcpy(filme[2].sala, "Sala C");
        strcpy(filme[2].hora, "10:00");
        filme[2].valor = 22.5;

        filme[3].id = 4;
        strcpy(filme[3].nome, "Star Wars");
        strcpy(filme[3].sala, "Sala D");
        strcpy(filme[3].hora, "13:15");
        filme[3].valor = 21.0;

        filme[4].id = 5;
        strcpy(filme[4].nome, "Indiana Jones");
        strcpy(filme[4].sala, "Sala E");
        strcpy(filme[4].hora, "16:30");
        filme[4].valor = 19.5;

        filme[5].id = 6;
        strcpy(filme[5].nome, "O Rei Leão");
        strcpy(filme[5].sala, "Sala F");
        strcpy(filme[5].hora, "12:45");
        filme[5].valor = 17.0;

        filme[6].id = 7;
        strcpy(filme[6].nome, "Pulp Fiction");
        strcpy(filme[6].sala, "Sala G");
        strcpy(filme[6].hora, "15:00");
        filme[6].valor = 20.0;

        filme[7].id = 8;
        strcpy(filme[7].nome, "E.T.");
        strcpy(filme[7].sala, "Sala H");
        strcpy(filme[7].hora, "11:15");
        filme[7].valor = 18.5;

        filme[8].id = 9;
        strcpy(filme[8].nome, "Forrest Gump");
        strcpy(filme[8].sala, "Sala I");
        strcpy(filme[8].hora, "14:30");
        filme[8].valor = 21.5;

        filme[9].id = 10;
        strcpy(filme[9].nome, "Avatar");
        strcpy(filme[9].sala, "Sala J");
        strcpy(filme[9].hora, "17:45");
        filme[9].valor = 23.0;
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