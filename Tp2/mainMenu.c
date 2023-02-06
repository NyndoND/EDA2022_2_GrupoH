#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    do{
    printf("Trabalho Pratico 2\n");
    printf("1. Carregar arquivo de dados\n");
    printf("2. Emitir Relatorio\n");
    printf("3. Sair\n");
    scanf("%d",&num);

    switch(num){
        case 1:
            printf("Nome do arquivo a ser carregado:\n");
            break;
        case 2:
        break;
        case 3:
        break;
    }

    }while(num!=3);
    return 0;
}
