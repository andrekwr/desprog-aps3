#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t)
{
  if (fscanf(file, "%d", p) != 1)
  {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }

  char c;
  do
  {
    c = getc(file);
  } while (c != '\n');

  fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1])
{
  //A base que se algum tamanho de lista for zero, a combinação recebe zero.
  if (n == 0 || m == 0)
  {
    length[n][m] = 0;
    return 0;
  }

  //Se o n-ésimo caractere do primeiro vetor é igual ao m-ésimo caractere do segundo vetor.
  if (a[n - 1] == b[m - 1])
  {
    int comp = mlcs_w(a, n - 1, b, m - 1, length) + 1;
    length[n][m] = comp;
    return comp;
  }

  //Verificar se o elemento atual foi calculado.
  if (length[n][m] != -1)
  {
    return length[n][m];
  }

  //Subsequência 1 e 2.
  int sub_1 = mlcs_w(a, n - 1, b, m, length);
  int sub_2 = mlcs_w(a, n, b, m - 1, length);

  //A matriz recebe o maior valor dentre a primeira parte ou a segunda.
  if (sub_1 > sub_2)
  {
    length[n][m] = sub_1;
    return sub_1;
  }
  length[n][m] = sub_2;
  return sub_2;
}

int mlcs(char a[], int n, char b[], int m)
{
  //Definir o tamanho da matriz.
  int length[MAX_SIZE + 1][MAX_SIZE + 1];

  //Inicializar a matriz e popular com -1.
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      length[i][j] = -1;
    }
  }

  //Chama a função mlcs_w
  int total = mlcs_w(a, n, b, m, length);
  return total;
}

int dlcs(char a[], int n, char b[], int m)
{
  //Definir o tamanho da matriz.
  int length[MAX_SIZE + 1][MAX_SIZE + 1];

  // Vamos considerar para os loops
  // n = i iterador de n (da lista a)
  // m = j iterador de m (da lista b)
  int i = 0;
  int j = 0;

  while (i < n + 1)
  {
    while (j < m + 1)
    {

      //A base que se algum tamanho de lista for zero, a combinação recebe zero.
      if (i == 0 || j == 0)
      {
        length[i][j] = 0;
        j++;
      }

      //Se o n-ésimo caractere do primeiro vetor é igual ao m-ésimo caractere do segundo vetor.
      else if (a[i - 1] == b[j - 1])
      {
        length[i][j] = length[i - 1][j - 1] + 1;
        j++;
      }

      //length[i][j] recebe o maior valor dentre length[i-1][j] e length[i][j-1] caso contrário.
      else
      {
        if (length[i - 1][j] > length[i][j - 1])
        {
          length[i][j] = length[i - 1][j];
        }
        else
        {
          length[i][j] = length[i][j - 1];
        }
        j++;
      }
    }
    i++;
  }

  return length[n][m];
}
