#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto
{
  char category[40] ;
  float amount;
};
int main()
{
  int i;
  FILE *fp, *fp2;
  struct Produto aux ;
  struct Produto p[20] ;
  fp = fopen ( "arquivo.csv", "r" ) ;
  fp2 = fopen ( "saida.csv", "w" ) ;
  if ( fp == NULL )
  {
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;
  }
  for(int i=0;i <19;i++)
   fscanf ( fp, "%s %f", p[i].category, &p[i].amount) ;
     
    //Ordenado os pecos bubble
    for(int h=19; h>0; h--){       
        for (int j = 0; j < h; j++)
        {
            if (p[j].amount < p[j+1].amount)
            {
                aux.amount = p[j].amount;
                strcpy(aux.category, p[j].category);
              
                p[j].amount = p[j+1].amount;
                strcpy(p[j].category , p[j+1].category);
              
                p[j+1].amount = aux.amount;
                strcpy(p[j+1].category, aux.category);
            }
        }
    }
    for (int l=0; l<19; l++)
    {
      //Printado no arquivo de saida
      fprintf ( fp2, "\n%s %f", p[l].category, p[l].amount) ;
    }
    fclose ( fp2 ) ;
    fclose ( fp ) ;
    return 0;
}
 
