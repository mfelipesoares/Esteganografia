#ifndef __LOAD_PNG__
#define __LOAD_PNG__
typedef struct {
    unsigned char r, g, b;
} RGB;
typedef struct {
    int largura, altura;
    RGB* img;
} Img;
/// @brief Esta função verifica se um determinado arquivo é um PNG ou não.
/// @param filename PATH do arquivo a ser verificado 
/// @return retorna 1 para falso e 0 para verdadeiro
int is_PNG(const char *path);

/// @brief Esta função carrega um determinado PNG utilizando a biblioteca SOIL
/// @param name PATH do arquivo PNG
/// @param pic Struct do PNG 
/// @param bmp Verifica se o arquivo passado é um BMP
int load(char* path, Img* imagem, int bmp);
#endif //__LOAD_PNG__