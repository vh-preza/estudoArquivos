#include <stdio.h>
#include <string.h>

//this program displays what class the cpf, that is inserted, is registered

typedef struct _Registro{
int id_inscricao;
char curso[20];
char cpf[15];
char dataNacimento[11];
char sexo;
char email[40];
char opcaoQuadro;
}Registro;

int leRegistro(Registro *r, FILE *f){};

int main(int argc, char**argv){

    FILE *f;
    Registro *r;
    int num;
    char cpfReq[15];

    printf("insira CPF requisitado:\n");
    scanf("%s", cpfReq);

    f = fopen("teste.dat","rb+");

    if(f == NULL)
    {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    num = leRegistro(&r, &f);

    while(num!=0){

        if(!strcmp(r->cpf, cpfReq)){
            
            printf("%s\n", r->curso);
            break;
        }        
        
        num = leRegistro(&r, &f);
    }

    fclose(f);

    return 0;
}