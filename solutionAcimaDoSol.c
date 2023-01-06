#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void minusculo(char s1[100], char s2[100]) {
  int i = 0;
  while (s1[i] != '\0') {
    s2[i] = tolower(s1[i]);
    i++;
  }
  s2[i] = '\0';
}

int word2vec(char *pNomeTxtEntrada) {
  FILE *file1;
  FILE *file2;

  char str1[80];
  char str2[80];

  strcpy(str1, pNomeTxtEntrada);
  strcpy(str2, "_Vocaculo");
  strcat(str1, ".txt");

  file1 = fopen(str1, "r");

  strcpy(str1, pNomeTxtEntrada);
  strcat(str1, str2);
  strcat(str1, ".txt");

  file2 = fopen(str1, "w");

  char frase[1000];
  char *pt;
  char comparacao[4][50] = {"não", "tão", "Não", "Tão"};
  int result;
  int result2;
  char listaPalavras[200][200];
  int qtd = 0;

  while (fgets(frase, 1000, file1) != NULL) {

    pt = strtok(frase, " \n...,");

    while (pt) {
      char palavra[100];
      minusculo(pt, palavra);

      if (strlen(palavra) >= 4) {

        int bol = 0;
        int bol2 = 0;

        for (int i = 0; i < 4; i++) {

          result = strcmp(palavra, comparacao[i]);

          if (result == 0) {
            bol = 1;
            break;
          }
        }
        if (bol != 1) {
          strcpy(listaPalavras[qtd], palavra);

          for (int z = 0; z < qtd; z++) {

            result2 = strcmp(listaPalavras[z], palavra);
            if (result2 == 0) {
              bol2 = 1;
              break;
            }
          }
          if (bol2 != 1) {
            fprintf(file2, "%s\n", palavra);
          }
          qtd++;
        }
      }

      pt = strtok(NULL, " \n...,");
    }
  }
  
  fclose(file1);
  fclose(file2);
  
  return 0;
}
int main(void) {
  char arquivo[50];
  scanf("%s", arquivo);
  word2vec(arquivo);
  return 0;
}