#include <stdio.h>
#include <string.h>

//this code is used to mantain an inventory off tool in a shop, 
//insert a tool in the file

typedef struct _Ferramenta {
    char nomeFerramenta[17];
    int qtd;
    float custo;
    char lixo[2];
}Ferramenta;

int main(int argc, char** argv){

    FILE *file;
    Ferramenta ferramenta;
    Ferramenta temp;
    int num;
    int reg;

    file = fopen("ferramentas.dat","rb+");

    if(file == NULL)
    {
        printf("erro ao abrir o arquivo");
        return 1;

    }

    printf("insira o numero de registro\n");
    scanf("%d", &num);
    printf("insira o nome da ferramenta\n");
    scanf("%s", ferramenta.nomeFerramenta);
    printf("insira a quantidade de ferramentas\n");
    scanf("%d", &ferramenta.qtd);
    printf("insira o custo da ferramenta\n");
    scanf("%f", &ferramenta.custo);

    fseek(file, num*sizeof(ferramenta),SEEK_SET);
    fread(&temp,sizeof(ferramenta),1,file);

    if(strcmp(temp.nomeFerramenta,"")){
        printf("registro ja utilizado!\n");
        return 1;
    }

    fseek(file,num*sizeof(ferramenta),SEEK_SET);
    fwrite(&ferramenta,sizeof(ferramenta),1,file);

    printf("escrita feito com sucesso!");

    fclose(file);
    return 0;
}