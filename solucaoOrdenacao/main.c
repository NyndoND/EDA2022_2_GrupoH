#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
  char category[100];
  float amount;
} Produto;

int main()
{
  FILE *fp;
  Produto aux;
  Produto *p;
  fp = fopen("amazonDataset.csv", "r");

  if (fp == NULL)
  {
    printf("Não foi possível abrir o arquivo!\n");
  }
  else
  {
    printf("Arquivo aberto com sucesso!\n");
  }

  // Alocação dinâmica    --> resolver problema da alocação dinâmica
  int tam = 128975; // int tam = tamanhoArquivo(fp);  -> função tamanhoArquivo está com problema
  p = (Produto *)malloc(tam * sizeof(Produto));

  // criando outro arquivo para formatar e manipular o dataSet
  FILE *fpCopia;
  fpCopia = fopen("amazonDatasetCopia.csv", "w");

  for (int i = 0; i < tam; i++)
    fscanf(fp, "%s %f", p[i].category, &p[i].amount);

  // Ordenado os pecos bubble
  for (int h = tam; h > 0; h--)
  {
    for (int j = 0; j < h; j++)
    {
      if (p[j].amount < p[j + 1].amount)
      {
        aux.amount = p[j].amount;
        strcpy(aux.category, p[j].category);

        p[j].amount = p[j + 1].amount;
        strcpy(p[j].category, p[j + 1].category);

        p[j + 1].amount = aux.amount;
        strcpy(p[j + 1].category, aux.category);
      }
    }
  }

  for (int l = 0; l < tam; l++)
  {
    //Printado no arquivo de saida
    fprintf(fpCopia, "\n%s %f", p[l].category, p[l].amount);
  }
  fclose(fpCopia);

  printf("Arquivo de saida gerado!\n"); // se o código executar até aqui, quer dizer que foi gerado um arquivo de saída

  free(p);
  fclose(fp);
  fclose(fpCopia);
  // fclose(fpSaida);
  return 0;
}