/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;
//teste
int main()
{
  /* variaveis globais */
  FILE *arq_entrada, *arq_saida;
  char nome_arq_ent[15] = "";
  char nome_arq_saida[15] = "";
  char ent_nome[12] = "";
  int vet_size = 0;

  menu(); /* linha 27 */
  return 0;
}

void menu()	 /* Menu de entrada REFAZER!!! */
{

  int IN;

  printf("Boa noite!\nPor favor, escolha o algorítimo de ordenação:\n1 - \n2 - \n3 - \n4 - Sair\n");
  scanf("%d", &IN);

  switch(IN)
    {
    case 1:
      bubble_sort();
      break;

    case 2:
      merge_sort();
      break;

    case 3:
      quick_sort();
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

int nomear_arq() /* Lê e cria os nomes dos arquivos e tamanho de vetores */
{
  printf("Por favor, insira o nome do arquivo:\n");
  scanf("%s", &ent_nome);
  printf("Por favor, insira o numero de linhas do arquivo:\n");
  scanf("%d", &vet_size);
    
  nome_arq_ent = ("%s.txt", &ent_nome);
  nome_arq_saida = ("%s (ordenado).txt", &ent_nome);
    
  if (nome_arq_ent != NULL) && (nome_arq_saida != NULL)
    {
      return 1;
    }
  else
    {
      create_vets(vet-size);
      return 0;
    }
    
}

int lerArquivo() /*Abrir e ler arquivo */
{
  arq_entrada = fopen(nome_arq_ent, "r");
  if(arq_entrada == NULL)
    {
      printf ("Erro na abertura do arquivo!\n\a");
      return 1;
    }     

  int linha; //buffer de entrada
  int i = 0;
  fscanf (arq_entrada, "%d", &linha);
  while (!feof (arq_entrada))
    {
      vet[i] = linha;
      i++;
      fscanf (arq_entrada, "%d", &linha);
    }

  fclose(arq_entrada);
  return 0;
}

int salvarArquivo() /* Salva o arquivo */
{
    arq_saida = fopen(nome_arq_saida, "w");
    if(nome_arq_saida == NULL)
    {
        printf ("Erro na criação do arquivo!\n\a");
        return 1;
    }
  fprintf(arq_saida, "%d\n", vet[i]);
    
  for(int i=0; i <= sizeof(vet); i++)
  {
    fprintf(arq_saida, "%d\n", vet[i]); // corrigir
  }
  fclose(arq_saida);
  
  printf("Dados gravados com sucesso!");
  
  return 0;
}

void create_vets(int n)
{
  int *vet = (int *) malloc (n * sizeof (int));
  i = 0;
  aux = 0;
  printf ("Vetor criado\n");
}

int bubble(int[] v, int n)
{
  int aux = 0;
  int i = 0;
  int j = 0;
  int cont = 0;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n - i - 1; j++)
	{
	  if (v[j] > v[j + 1])
	    {
	      aux = v[j];
	      v[j] = v[j + 1];
	      v[j + 1] = aux;
	      cont++;
	    }
	}
    }
    return cont;
}

int merge(int[] v, int n)
{
  int aux = 0;
  int i = 0;
  int j = 0;
  int cont = 0;





  return cont;
}

int quick(int[] v, int n)
{
  int aux = 0;
  int i = 0;
  int j = 0;
  int cont = 0;




  
  return cont;
}
