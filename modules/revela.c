#include <stdio.h>
#include <stdlib.h>
#include "revela.h"
#include "../libs/SOIL/SOIL.h"

#define CARACTER_FINAL '$'

int getBit (int cor,int pixelPos,Img pic, int position){
    int bit =0;
    switch (cor){
        case 0:
            bit = (pic.img[pixelPos].r >> position) & 0x01;
            break;
        case 1:
            bit = (pic.img[pixelPos].g >> position) & 0x01;
            break;
        case 2:
            bit = (pic.img[pixelPos].b >> position) & 0x01;
            break;
    }
    return bit;
}

void revelar (Img imagem){
    unsigned char frase[1080];
    unsigned char caracter;
    int i, j;
    int cor = 0;
    int posicao_pixel = 0;
    for (i = 0;  i < (imagem.altura * imagem.largura); i++){
        caracter = 0x00;
        for(j = 7; 0 <= j; j-=2){
                if(cor >= 3){
                    posicao_pixel++;
                    cor = 0;
                }
                 caracter ^= (-(getBit(cor, posicao_pixel, imagem, 1)) ^ caracter) & (0x01 << j);
                 caracter ^= (-(getBit(cor, posicao_pixel, imagem, 0)) ^ caracter) & (0x01 << j - 1);
                 cor ++;
            }
            if (caracter == CARACTER_FINAL){
                frase[i] = caracter;
                break;
            }
            frase[i] = caracter;
    }
    printf("Mensagem escondida:\n\t%s\n", frase);
}