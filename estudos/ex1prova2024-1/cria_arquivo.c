#include <stdio.h>
#include <string.h>

//this code is used to mantain an inventory off tool in a shop, 
//create a null file with 100 registers

typedef struct _Ferramenta {
  char nomeFerramenta[17];
  int qtd;
  float custo;
  char lixo[2];
}Ferramenta;

int main(int argc, char** argv){
  
  FILE *file;
  Ferramenta ferramenta;

  ferramenta.nomeFerramenta[0] = '\0';
  ferramenta.qtd = 0;
  ferramenta.custo = 0.0;

  file = fopen("ferramentas.dat","wb+");

  if(file == NULL){
    printf("erro ao abrir o arquivo");
    return 1;        
  }

  for(int i= 0; i<100; i++){

    fwrite(&ferramenta, sizeof(ferramenta), 1, file);  
  }

  fseek(file,SEEK_SET,0);

  fread(&ferramenta, sizeof(ferramenta), 1, file);

  while(!feof(file)){
    
    printf("%s ,%d ,%f\n", ferramenta.nomeFerramenta,ferramenta.qtd,ferramenta.custo);
    fread(&ferramenta, sizeof(ferramenta), 1, file);
  }

  fclose(file);

  return 0;
}