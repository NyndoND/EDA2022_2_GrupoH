#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Definindo o Produto
typedef struct
{
  char category[30];
  float amount;
} Produto;

int main()
{
  FILE *fp;
  Produto *p, aux, teste;
  fp = fopen("amazonTest.csv", "r");

  if (fp == NULL)
  {
    printf("Não foi possível abrir o arquivo!\n");
  }
  else
  {
    printf("Arquivo aberto com sucesso!\n");
  }

  // Alocando o tamanho de 1 produto
  p = (Produto *)malloc(1 * sizeof(Produto));

  // criando outro arquivo para formatar e manipular o dataSet
  FILE *fpCopia;
  fpCopia = fopen("amazonDatasetCopia.csv", "w");
  int i = 0;

  while(fscanf(fp, "%s %f", teste.category, &teste.amount) != EOF){
    p = (Produto*) realloc(p, (i+1) * sizeof(Produto));
    p[i].amount = teste.amount;
    strcpy(p[i].category,teste.category);
    i++;
  };

  // do {
  //   //p = (Produto*) realloc(p, (i+2) * sizeof(Produto));
  //   if(i > 100){
  //     fscanf(fp, "%s %f", teste[i].category, &teste[i].amount);
  //   } else {
  //     fscanf(fp, "%s %f", p[i].category, &p[i].amount);
  //   }
  //   i++;
  // }while(fscanf(fp, "%s %f", teste[i].category, &teste[i].amount) != EOF);
 
  printf("aqui");

  // Ordenado os pecos bubble
  for (int h = i; h > 0; h--)
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

  for (int l = 0; l < i; l++)
  {
    //Printado no arquivo de saida
    fprintf(fpCopia, "%s %f\n", p[l].category, p[l].amount);
  }
  printf("\n %s %f\n", teste.category, teste.amount);
  fclose(fpCopia);

  printf("Arquivo de saida gerado!\n"); // se o código executar até aqui, quer dizer que foi gerado um arquivo de saída

  free(p);
  fclose(fp);
  fclose(fpCopia);
  // fclose(fpSaida);
  return 0;
}