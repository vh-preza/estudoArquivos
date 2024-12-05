#include <stdio.h>
#include <string.h>

//this code is used to mantain an inventory off tool in a shop, 
//list all the tool registered, the quantity off distinct tools and the summation of all the tools

typedef struct _Ferramenta {
    char nomeFerramenta[17];
    int qtd;
    float custo;
    char lixo[2];
}Ferramenta;

int main(int argc,char** argv){
    
    FILE *file;
    Ferramenta ferramenta;
    int countAll, countDiff = 0;

    file = fopen("ferramentas.dat","rb+");

    if(file==NULL){
        
        printf("erro ao abrir o arquivo");
        
        return 1;
    }

    fread(&ferramenta,sizeof(ferramenta),1,file);

    while(!feof(file)){

        if(strcmp(ferramenta.nomeFerramenta,"")){
        
        printf("%s\n", ferramenta.nomeFerramenta);
        
        countDiff++;
        countAll+= ferramenta.qtd;

        }

        fread(&ferramenta,sizeof(ferramenta),1,file);

    }

    printf("quantidade de ferramentas distintas cadastradas: %d\n", countDiff);
    printf("quantidade total de ferramentas cadastradas: %d\n", countAll);

    fclose(file);

}