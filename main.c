#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/load_png.h"
#include "modules/revela.h"
#include "modules/esconde.h"

/*
Para esconder utilize os comando:
    [Nome do binario] path_do_png.png -e

Para revelar a mensagem escondida:
    [Nome do binario] path_de_saida.bmp -d
*/

int main(int argc, char **argv){
    Img imagem;
    if(strcmp(argv[2], "-d") == 0){
        load(argv[1], &imagem, 1);
        revelar(imagem);
    }
    else if(strcmp(argv[2], "-h") == 0){
        load(argv[1], &imagem, 0);
        esconde(imagem, argv[3]);
    } else {
        printf("Opção não reconhecida!\nTente novamente..\n");
    }
    return 0;
}