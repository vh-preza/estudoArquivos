//binary search in a file

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Endereco {
  char logradouro[72];
  char bairro[72];
  char cidade[72];
  char uf[72];
  char sigla[2];
  char cep[8];
  char lixo[2];
} Endereco;

int main(void) {
  FILE *file;

  file = fopen("cep_ordenado.dat", "rb");
  if (file == NULL) {
    printf("Faha ao abrir o arquivo\n");
    return 0;
  }

  fseek(file, 0, SEEK_END);

  int left = 0;
  int right = ftell(file) / sizeof(Endereco) - 1;

  char cepDesejado[8];

  printf("Insira o cep que deseja encontrar:\n");
  scanf("%s", cepDesejado);

  bool encontrado = false;
  int mid, temp;

  Endereco endereco;

  while (left <= right) {
    mid = left + (right - left) / 2;

    fseek(file, mid * sizeof(Endereco), SEEK_SET);
    fread(&endereco, sizeof(Endereco), 1, file);

    temp = strncmp(endereco.cep, cepDesejado, 8);

    if (temp > 0) {
      right = mid - 1;
    } else if (temp < 0) {
      left = mid + 1;
    } else {
      printf("CEP encontrado: %.8s\nLogradouro: %.72s\nBairro: %.72s\nCidade: %.72s\nUF: %.72s\nSigla: %.2s\n", endereco.cep, endereco.logradouro, endereco.bairro, endereco.cidade, endereco.uf, endereco.sigla);
      encontrado = true;
      break;
    }
  }

  if (!encontrado) {
    printf("CEP não encontrado\n");
  }

  fclose(file);
}