#include <stdio.h>

int main(int argc, char** argv){
    FILE *entrada, *saida;
    int c;



    entrada = fopen("C:\\Users\\User\\Documents\\programas\\testeDeProgramas\\vitin.txt","r");

    if(entrada == NULL){
        fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }
    
    saida = fopen("C:\\Users\\User\\Documents\\programas\\testeDeProgramas\\vitin2.txt","w");

    if(saida == NULL){
        fclose(entrada);
        fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
        return 1;
    }

    c = fgetc(entrada);
     
    while(c != EOF){ 
        fputc(c,saida);
        c = fgetc(entrada); 
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
