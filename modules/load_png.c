/*
Aluno: Marcos Felipe dos Santos Soares
Disciplina: Algoritmos e Estrutura de dados II
-------------------------------------------------------------------------
    Neste arquivo encontra-se todas as funções utilizadas para carregar
    a imagem PNG e acessar sua matriz de pixels.

    Biblioteca utilizada para manipular PNG:
    - SOIL: https://github.com/littlstar/soil

------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include "../libs/SOIL/SOIL.h"
#include "load_png.h"
int is_PNG(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) exit(-1);
    png_byte header[8];
    fread(header, 1, 8, file);
    int resposta = (png_sig_cmp(header, 0, 8)) ? 1 : 0;
    fclose(file);
    return resposta; 
}
int load(char* path, Img* imagem, int bmp){
    int channel;
    if(bmp == 1){
        imagem->img = (unsigned char*) SOIL_load_image(path, &imagem->largura, &imagem->altura, &channel, SOIL_LOAD_RGB);
        if(!imagem->img)
        {
            printf("Erro ao carregar o arquivo!\n");
            return 0;
        }
        return 1;
    }else{
        if(is_PNG(path)){
            printf("O arquivo informado não é um PNG!\nTente novamente...\n");
            exit(-1);
        }
        imagem->img = (unsigned char*) SOIL_load_image(path, &imagem->largura, &imagem->altura, &channel, SOIL_LOAD_RGB);
        if(!imagem->img)
        {
            printf("Erro ao carregar o arquivo!\n");
            return 0;
        }
    }
    return 1;
}

