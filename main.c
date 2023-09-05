/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *arq_entrada, *arq_saida;
  char nome_arq_ent[15] = "";
  char nome_arq_saida[15] = "";
  char ent_nome[12] = "";

  menu();
  return 0;
}

void menu()	 /* Menu de entrada */
{

  int IN;

  printf("Boa noite!\nPor favor, escolha o algorítimo de ordenação:\n1 - \n2 - \n3 - \n4 - Sair\n");
  scanf("%d", &IN);

  switch(IN)
    {
    case 1:
      primAlg();
      break;

    case 2:
      segAlg();
      break;

    case 3:
      terAlg();
      break;

    case 4:
      printf("Saindo!");
      exit(0);
      break;

    default:
      menu();
      break;
    }
}

void nomear_arq() /*Lê e cria os nomes dos arquivos*/
{
    printf("Por favor, dê o nome do arquivo:\n");
    scanf("%s", &ent_nome);
    
    nome_arq_ent = ("%s.txt", &ent_nome);
    nome_arq_saida = ("%s(ordenado).txt", &ent_nome);

    
}

void lerArquivo() /*Abrir e ler arquivo */
{
  arq_entrada = fopen(nome_arq_ent, "r");
  if(nome_arq_ent == NULL)
    {
      printf ("Erro na abertura do arquivo!");
    }

}

void salvarArquivo() /*Salva o arquivo */
{
    arq_saida = fopen(nome_arq_saida, "w");
    if(nome_arq_saida_arq == NULL)
    {
        printf ("Erro na criação do arquivo!\a");
    }
    
    for(int i=0, i < sizeof(vet), i++)
    {
        fprintf(arq_saida, "%d ", vet[i]);
    }
    fclose(arq_saida);
  
    printf("Dados gravados com sucesso!");
  
    getch();
    return(0);
}

float[] primAlg()
{
  lerArquivo();

  salvarArquivo();
}

float[] segAlg()
{
  lerArquivo();

  salvarArquivo();
}

float[] terAlg()
{
  lerArquivo();

  salvarArquivo();
}
