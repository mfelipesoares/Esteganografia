/*
Aluno: Marcos Felipe dos Santos Soares
Disciplina: Algoritmos e Estrutura de dados II
-------------------------------------------------------------------------
    Neste arquivo encontra-se todas as funções utilizadas para se fazer
    a esteganografia em uma imagem PNG.

    Biblioteca utilizada para manipular PNG:
    - SOIL: https://github.com/littlstar/soil

------------------------------------------------------------------------
*/
#include "load_png.h"
#include "esconde.h"
#include "../libs/SOIL/SOIL.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CARACTER_FINAL '$'

void setBit(int cor, int posicao_pixel, Img imagem, unsigned char bit_1,  unsigned char bit_2){
    switch(cor){
        case 0:
            imagem.img[posicao_pixel].r ^= (-bit_2 ^ imagem.img[posicao_pixel].r) & (0x01);
            imagem.img[posicao_pixel].r ^= (-bit_1 ^ imagem.img[posicao_pixel].r) & (0x01 << 1);
            break;
        case 1:
            imagem.img[posicao_pixel].g ^= (-bit_2 ^ imagem.img[posicao_pixel].g) & (0x01 );
            imagem.img[posicao_pixel].g ^= (-bit_1 ^ imagem.img[posicao_pixel].g) & (0x01 << 1);
            break;
        case 2:
            imagem.img[posicao_pixel].b ^= (-bit_2 ^ imagem.img[posicao_pixel].b) & (0x01);
            imagem.img[posicao_pixel].b ^= (-bit_1 ^ imagem.img[posicao_pixel].b) & (0x01 << 1);
            break;
    }
}
void gravarBitSeparador(int j, int cor, int posicao_pixel, int bit_1, int bit_2, Img imagem){
    for(j = 7; 0 <= j; j-=2){
        if (cor >= 3){
            posicao_pixel ++;
            cor=0;
        }
        bit_1 = (CARACTER_FINAL >> j) & 0x01;
        bit_2 = (CARACTER_FINAL >> j-1) & 0x01;
        setBit(cor, posicao_pixel, imagem, bit_1, bit_2);
        cor ++;
    }
}
void esconde(Img imagem, char * frase_a_esconder){
    //Variaveis de controle:
    int tamanho_frase = strlen(frase_a_esconder);
    int posicao_pixel = 0 ;
    unsigned char bit_1;
    unsigned char bit_2;
    int cor = 0 ;
    int i = 0;
    int j = 0;
    //Looping principal:
    while(i <= tamanho_frase){
        for(j = 7; 0 <= j; j-=2){
             bit_1 = ((frase_a_esconder[i] >> j) & 0x01);
             bit_2 = (frase_a_esconder[i] >> j-1) & 0x01;
            if (cor >= 3){
                posicao_pixel ++;
                cor=0;
            }
            setBit(cor,posicao_pixel,imagem, bit_1, bit_2);
            cor ++;
        }
        i++;
    }
    gravarBitSeparador(j, cor, posicao_pixel, bit_1, bit_2, imagem);
    SOIL_save_image("saida.bmp", SOIL_SAVE_TYPE_BMP, imagem.largura, imagem.altura, 3, imagem.img);
    free(imagem.img);
}