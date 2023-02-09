#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int salaryUsd;
  int linha;
} salary;

typedef struct ABP {
  salary s;
  struct ABP *esquerda;
  struct ABP *direita;
} TABP;

TABP *create(salary s) {
  TABP *a = (TABP *)malloc(sizeof(TABP));
  a->s = s;
  a->esquerda = NULL;
  a->direita = NULL;

  return a;
}

void adicionar(TABP *a, salary s) {
  if (s.salaryUsd < a->s.salaryUsd) {
    if (a->esquerda == NULL) {
      a->esquerda = create(s);
    } else {
      adicionar(a->esquerda, s);
    }
  } else {
    if (a->direita == NULL) {
      a->direita = create(s);
    } else {
      adicionar(a->direita, s);
    }
  }
}

void imprime(TABP *a) {
  if (a == NULL) {
    return;
  } else {
    imprime(a->esquerda);
    printf("%d %d\n", a->s.salaryUsd, a->s.linha);
    imprime(a->direita);
  }
}

void desalocar(TABP *a) {
  if (a == NULL) {
    return;
  } else if (a->esquerda == NULL && a->direita == NULL) {
    free(a);
    a = NULL;
  } else {
    desalocar(a->esquerda);
    desalocar(a->direita);
    free(a);
    a = NULL;
  }
}

int main(int argc, char const *argv[]) {

  FILE *fp;
  TABP *raiz = NULL;
  TABP *raizAux;
  salary sAux;

  int escolha;
  char arquivo[50];

  do {
    printf("\nTrabalho Pratico 2\n");
    printf("1. Carregar arquivo de dados\n");
    printf("2. Emitir Relatorio\n");
    printf("3. Sair\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("Digite o nome do arquivo:");
      scanf("%s", arquivo);
      if (strcmp(arquivo, "dataset_salaries") == 0) {
        fp = fopen("dataset_salaries.csv", "r");

        if (fp == NULL) {
          printf("Erro na abertura do arquivo!\n");
        } else {
          printf("Arquivo aberto com sucesso!\n");
        }

        fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd);
        raiz = create(sAux);

        while (fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd) != EOF) {
          adicionar(raiz, sAux);
        }

        break;

      } else {
        printf("Esse arquivo não existe");
        break;
      }

    case 2:

      if (raiz == NULL) {
        printf("Arquivo vazio!\n");
      } else {
        raizAux = raiz;

        imprime(raizAux);
      }
      printf("\n");

      break;

    case 3:

      desalocar(raiz);

      break;

    default:

      printf("Opcao invalida! Escolha entre as opcoes 1, 2 e 3.\n");
    }

  } while (escolha != 3);

  return 0;
}