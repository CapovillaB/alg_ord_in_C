/* APS 4º SEMESTRE - UNIP - Estrutura de Dados - Prof. Luiz Forçan e Prof. Alvaro Nunes */
// Algoritimos de ordenação de arquivos númericos txt em linguagem C.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variaveis globais
FILE *arq_entrada, *arq_saida;
char nome_arq_ent[30];
char nome_arq_saida[30];
char ent_nome[20];
char st[5];
int count = 0;
int vet_size = 0;
int* vet;


void merge(int v[], int ini, int meio, int fim);
void menu();

void nomearArquivo() // Lê e cria os nomes dos arquivos e tamanho de vetores
{
  printf("Por favor, insira o nome do arquivo:\n");
  scanf("%s", ent_nome);
  printf("Por favor, insira o numero de linhas do arquivo:\n");
  scanf("%d", &vet_size);
  
  char *txt = ".txt";
  char *ordenado = " ord).txt";

  strcpy (nome_arq_ent, ent_nome);
  strcat(nome_arq_ent, txt);
  strcpy (nome_arq_saida, ent_nome);
  strcat (nome_arq_saida, st);
  strcat(nome_arq_saida, ordenado);
  
  
  printf("entrada: '%s'\n", nome_arq_ent);
  printf("saida: '%s'\n" , nome_arq_saida);
  
  
  vet = realloc(vet, vet_size * sizeof(int));

}

void lerArquivo() // Abre e le o arquivo
{
  arq_entrada = fopen(nome_arq_ent, "r");
  count = 0; // zera contador global
  if (arq_entrada == NULL)
  {
    printf("Erro na abertura do arquivo!\n\a");
  }

  int linha; // buffer de entrada
  int i = 0;
  fscanf(arq_entrada, "%d", &linha);
  while (!feof(arq_entrada))
  {
    vet[i] = linha;
    i++;
    fscanf(arq_entrada, "%d", &linha);
  }

  fclose(arq_entrada);
}

void salvarArquivo() // Salva o arquivo com vetor ordenado e número de iterações
{
  arq_saida = fopen(nome_arq_saida, "w");
  if (nome_arq_saida == NULL)
  {
    printf("Erro na criação do arquivo!\n\a");
  }
  fprintf(arq_saida, "Iterações: %d\n\n", count);

  for (int i = 0; i <= vet_size; i++)
  {
    fprintf(arq_saida, "%d\n", vet[i]); // corrigir
  }
  fclose(arq_saida);

  printf("Dados gravados com sucesso!");
}



void swap(int *a, int *b) // swap para os sorts
{
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int v[], int a, int b) // para o quick()
{
  int pivot = v[b]; // escolhe o pivot no fim do vetor

  int i = (a - 1); // indice do menor elemento e indica a posição na direita do pivot até o momento

  for (int j = a; j <= b - 1; j++)
  {

    if (v[j] < pivot)
    { // se o elemento é menor que o pivot, eleva o indice do menor elemento
      i++;
      swap(&v[i], &v[j]);
      count++;
    }
  }
  swap(&v[i + 1], &v[b]);
  count++;
  return (i + 1);
}

void mergesort(int v[], int ini, int fim)
{
    if (ini < fim) {
        int meio = ini + (fim - ini) / 2;
 
        // ordena as duas metades
        mergesort(v, ini, meio);
        mergesort(v, meio + 1, fim);
 
        merge(v, ini, meio, fim);
    }
}

void bubble(int v[], int n)
{
  int i = 0;
  int j = 0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (v[j] > v[j + 1])
      {
        swap(&v[j], &v[j + 1]);
        count++;
      }
    }
  }
}

// vet --> vetor de entrada aleatório
// ini --> indice inicial
// meio --> meio do vetor
// fim --> indice final
void merge(int v[], int ini, int meio, int fim)
{
  int i, j, k;
  int n1 = meio - ini + 1;
  int n2 = fim - meio;

  int L[n1], R[n2]; // cria os vetores temporarios

  for (i = 0; i < n1; i++) // copia os dados do vetor origem para os temporarios
  {
    L[i] = v[ini + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = v[meio + 1 + j];
  }

  i = 0;
  j = 0;
  k = ini;
  while (i < n1 && j < n2) // junta (merge) tudo de novo organizando
  { 
    if (L[i] <= R[j])
    {
      v[k] = L[i];
      i++;
    }
    else
    {
      v[k] = R[j];
      j++;
    }
    k++;
    count++;
  }

  while (i < n1) //copia para vetor original o que sobro no vetor temporario LEFT
  {
    v[k] = L[i];
    i++;
    k++;
    count++;
  }

  while (j < n2) //copia para vetor original o que sobro no vetor temporario RIGHT
  {
    v[k] = R[j];
    j++;
    k++;
    count++;
  }
}

// vet --> vetor de entrada aleatório
// a --> indice inicial
// b --> indice final
void quick(int v[], int a, int b)
{
  if (a < b)
  {
    // di --> indice da divisao
    int di = particao(v, a, b);

    // organiza os elementos separadamente
    quick(v, a, di - 1);
    quick(v, di + 1, b);
  }
}

void bubble_sort()
{

  nomearArquivo();
  lerArquivo();
  clock_t start_time = clock(); // Registra o tempo inicial
  bubble(vet, vet_size);
  clock_t end_time = clock(); // Registra o tempo final
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.6f segundos\n", elapsed_time);
  salvarArquivo();
  menu();
}

void quick_sort()
{

  nomearArquivo();
  lerArquivo();
  clock_t start_time = clock();
  quick(vet, 0, vet_size);
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.6f segundos\n", elapsed_time);
  salvarArquivo();
  menu();
}

void merge_sort()
{
nomearArquivo(); 
  lerArquivo();
  clock_t start_time = clock();
  mergesort(vet, 0, vet_size);
  clock_t end_time = clock();
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.6f segundos\n", elapsed_time);
  salvarArquivo();
  menu();
}


void menu() // Menu de entrada
{

  int IN;

  printf("Boa noite!\nPor favor, escolha o algorítimo de ordenação:\n1 - BubbleSort \n2 - MergeSort\n3 - QuickSort\n4 - Sair\n");
  scanf("%d", &IN);

  switch (IN)
  {
  case 1:
    strcpy(st, "(BS");
    bubble_sort();
    break;

  case 2:
   strcpy(st, "(MS");
    merge_sort();
    break;

  case 3:
   strcpy(st, "(QS");
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


// Driver
int main()
{
  menu();
  return 0;
}
