#ifndef __ESCONDE__
#define __ESCONDE__
#include "load_png.h"
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
/// @brief Função utilizada para fazer a esteganografia em uma imagem PNG
/// @param imagem Struct que guarda a matriz de pixels do PNG
/// @param frase_a_esconder Stream de caracteres da frase a ser escondida na imagem
void esconde(Img imagem, char * frase_a_esconder);
/// @brief Esta função grava o bit separador
/// @param j Inteiro utilizado para iterar os bits da frase a ser escondida
/// @param cor Define o canal rgb correspondente
/// @param posicao_pixel Parametro de controle de pixel correspondente a ser gravado
/// @param bit_1 Primeiro bit significativo da frase a ser escondida
/// @param bit_2 Segundo bit significativo da frase a ser escondida
/// @param imagem Struct que guarda a matriz de pixels do PNG
void gravarBitSeparador(int j, int cor, int posicao_pixel, int bit_1, int bit_2, Img imagem);
/// @brief Esta função modifica os bits de determinado canal de cor RGB
/// @param cor Inteiro que representa o canal de cor RGB a ser alterado [ 0: Vermelho, 1: Verde e 2: Azul]
/// @param posicao_pixel Parametro de controle de pixel correspondente a ser gravado
/// @param imagem Struct que guarda a matriz de pixels do PNG
/// @param bit_1 Primeiro bit significativo da frase a ser escondida
/// @param bit_2 Segundo bit significativo da frase a ser escondida
void setBit(int cor, int posicao_pixel, Img imagem, unsigned char bit_1,  unsigned char bit_2);
#endif // __ESCONDE__