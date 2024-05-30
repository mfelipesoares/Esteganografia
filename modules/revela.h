#ifndef __REVELA__
#define __REVELA__
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
/// @brief Esta função recebe uma imagem e revela o conteúdo escondido pela esteganografia.
/// @param imagem PATH do arquivo a ser verificado. 
/// @return retorna uma string com o conteúdo ocultado.
void revelar(Img imagem);
#endif // __REVELA__