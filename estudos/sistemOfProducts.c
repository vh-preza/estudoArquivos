//sistem that organizes products and sales in a file
//1 - include product
//2 - register sale
//3 - search by code
//4 - search by description
//5 - reports of the minimum of product


#include <stdio.h>
#include <string.h>

typedef struct _Produto {
    char descricao[40];
    int quantidadeEstoque;
    int minimoEstoque;
    float precoVenda;
} Produto;

void menu();
void incluirProduto(FILE *);
void registrarVenda(FILE *);
int buscarCodigo(FILE *, int, Produto *);
void buscarDescricao(FILE *, Produto *);
void relatorioProdutosMin(FILE *);

int main() {
    int escolha, codigo;
    FILE * file;
    Produto produto;

    file = fopen("teste.dat", "rb+");

    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    menu();
    scanf("%d", &escolha);

    while(escolha != 6)
    {
        switch(escolha) {
            case 1:
                incluirProduto(file);
                break;
            case 2:
                registrarVenda(file);
                break;
            case 3:        
                printf("Insira o codigo do produto: ");
                scanf("%d", &codigo);

                buscarCodigo(file, codigo, &produto);
                break;
            case 4:
                buscarDescricao(file, &produto);
                break;
            case 5:
                relatorioProdutosMin(file);
        }

        menu();
        scanf("%d", &escolha);
    }

    fclose(file);
}

void menu() {
    printf("Controle De Estoque\n\n1 - Incluir produtos\n2 - Registrar venda\n3 - Buscar por codigo\n"           
        "4 - Buscar por descricao\n5 - Relatorio de produtos com Estoque Abaixo do Minimo\n6 - Sair\n");
}

void incluirProduto(FILE * file) {
    Produto produto;

    printf("Insira a descricao do produto: ");
    scanf("%s", produto.descricao);
    printf("Insira a quantidade do produto: ");
    scanf("%d", &produto.quantidadeEstoque);
    printf("Insira a quantidade minima do produto: ");
    scanf("%d", &produto.minimoEstoque);
    printf("Insira o preco do produto: ");
    scanf("%f", &produto.precoVenda);

    fseek(file, 0, SEEK_END);  
    fwrite(&produto, sizeof(Produto), 1, file);
}

void registrarVenda(FILE * file) {
    int codigo, quantidadeVendida;

    printf("Insira o codigo do produto: ");
    scanf("%d", &codigo);

    Produto temp;
    if(buscarCodigo(file, codigo, &temp) == 1) {
        return;
    }

    printf("Insira a quantidade vendida: ");
    scanf("%d", &quantidadeVendida);

    fseek(file, codigo * sizeof(Produto), SEEK_SET);

    if (temp.quantidadeEstoque >= quantidadeVendida) {
        temp.quantidadeEstoque -= quantidadeVendida;
        fwrite(&temp, sizeof(Produto), 1, file);
        printf("Venda registrada com sucesso.\n");
    }
    else {
        printf("Nao ha estoque suficiente para esta venda.\n");
    }
}

int buscarCodigo(FILE * file, int codigo, Produto * produto) {
    fseek(file, 0, SEEK_END);
  
    if(ftell(file) / sizeof(Produto) <= codigo) {
        printf("Codigo invalido.\n");
        return 1;
    }

    fseek(file, codigo * sizeof(Produto), SEEK_SET);
    fread(produto, sizeof(Produto), 1, file);

    return 0;
}

void buscarDescricao(FILE * file, Produto * produto) {
    char desc[40];

    printf("Insira a descricao desejada: ");
    scanf("%s", desc);

    fseek(file, 0, SEEK_SET);

    fread(produto, sizeof(Produto), 1, file);

    while (!feof(file)) {
        if(strcmp(produto->descricao, desc) == 0) {
            printf("Produto encontrado.\n");
            return;
        }
        fread(produto, sizeof(Produto), 1, file);
    }

    printf("Produto nao encontrado.\n");
}

void relatorioProdutosMin(FILE * file) {
    fseek(file, 0, SEEK_SET);

    Produto temp;

    printf("Produtos com estoque abaixo do minimo:\n");

    fread(&temp, sizeof(Produto), 1, file);

    while (!feof(file)) {
        if (temp.quantidadeEstoque < temp.minimoEstoque) {
            printf("%s\n", temp.descricao);
        }

        fread(&temp, sizeof(Produto), 1, file);
    }
}