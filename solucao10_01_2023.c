#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto
{
  char category[40] ;
  float amount;
};

//juntar categorias 
int main()
{
  int i;
  FILE *fp ;
  struct Produto aux ;
  struct Produto p[20] ;
  fp = fopen ( "arquivo.cvs", "r" ) ;
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
    //Imprimindo os valores ordenados
    for (int l=0; l<19; l++)
    {
        printf("\n%f %s", p[l].amount, p[l].category );
    }

    fclose ( fp ) ;
    return 0;
}
 
