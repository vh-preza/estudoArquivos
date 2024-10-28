#include <stdio.h>

int main(int argc, char** argv)
{
    FILE *entrada, *saida;
    int c;

    if(argc!=3)
    {
        fprintf(stderr, "erro na chamada de comando\n");
        return 1;
    }

    entrada = fopen(argv[1], "rb");

    if(!entrada)
    {
        fprintf(stderr,"erro ao abrir arquivo para leitura");
        fclose(entrada);
        return 1;
    }

    saida = fopen(argv[2], "wb");

    if(!saida)
    {
        fprintf(stderr,"erro ao abrir arquivo para escrita");
        fclose(saida);
        return 1;
    }

    c = fgetc(entrada);

    while(c!= EOF)
    {
        fputc(c, saida);
        c = fgetc(entrada);
    }

    fclose(entrada);
    fclose(saida);
}
