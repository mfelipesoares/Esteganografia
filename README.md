# Esteganogafia 🎩 🪄
Framework para fazer esteganografia em imagens de extensão PNG
## Como compilar
Execute o arquivo ```./compilar.sh```
## Escondendo uma informação
```bash
esteganografia [nome_do_arquivo.png] -h "Digite qualquer string aqui!"
```
## Recuperando a informação
```bash
esteganografia saida.bmp -d
```
Atenção: como já definido na função ```SOIL_save_image()```, por padrão o arquivo de saida já vem pré-definido. Portanto, o comando para recuperar a informação será o mesmo para qualquer entrada.

## Bibliotecas Necessárias
- Libpng: https://github.com/pnggroup/libpng
