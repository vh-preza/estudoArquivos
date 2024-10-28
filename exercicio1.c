#include <stdio.h>

//contar quantas vezes ocorre a quebra de linha ( c == 10)
//contar frequencia de cada simbolo no arquivo

int main(int argc, char** argv)
{
    FILE *entrada, *saida;
    
    int c;
    
    int count[256];

    if(argc!=3)
    {
        fprintf(stderr, "erro na chamada de comando");
        return 1;
    }

    entrada = fopen(argv[1], "rb");

    if(!entrada)
    {
        fprintf(stderr, "erro ao abrir arquivo de leitura");
        fclose(entrada);
        return 1;
    }

    saida = fopen(argv[2], "wb");

    if(!saida)
    {
        fprintf(stderr, "erro ao abrir arquivo de escrita");
        fclose(saida);
        return 1;
    }

    c = fgetc(entrada);

    while(c!= EOF)
    {
        count[sizeof(c)]++;
        
        fputc(c, saida);
        c = fgetc(entrada);
    }

    fclose(entrada);
    fclose(saida);

    for(int i=0; i<256; i++)
    {
        printf("valor do algarismo %d apareceu %d vezes", i, count[i]);
    }

    printf("o arquivo tem %d linhas", count[10]);
    return 0;
}