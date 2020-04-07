#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t) {
  if (fscanf(file, "%d", p) != 1) {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }

  char c;
  do {
    c = getc(file);
  } while (c != '\n');

  fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
  if (n == 0 || m == 0) {
    length[n][m] = 0;
    return 0;
  }

  if (a[n-1] == b[m-1]) {
    int comp = mlcs_w(a, n-1, b, m-1, length) + 1;
    length[n][m] = comp;
    return comp;
  }

  if (length[n][m] != -1) {
    return length[n][m];
  }

  int sub_1 = mlcs_w(a, n-1, b, m, length);
  int sub_2 = mlcs_w(a, n, b, m-1, length);

  if (sub_1 > sub_2) {
    length[n][m] = sub_1;
    return sub_1;

  } 
  length[n][m] = sub_2;
  return sub_2;
  
}

int mlcs(char a[], int n, char b[], int m) {
  int length[MAX_SIZE + 1][MAX_SIZE + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      length[i][j] = -1;
    }
  }

  int total = mlcs_w(a, n, b, m, length);

  return total;
}



int dlcs(char a[], int n, char b[], int m) {
  int j = 0;
  int i = 0;

  int counter = 0;

  printf("%s \n", "N");
  printf("%d \n", n);
  printf("%s \n", "M");
  printf("%d \n", m);

  if (n > m) {
    printf("%s \n", "N >");
    for (i; i <= (n-1); i ++) {
      for (j; j <= (m-1); j++) {
        if (a[i] == b[j]) {
          printf("%s \n", "N >");
          printf("%c \n", a[i]);
          counter += 1;
          break;
        }
      }
      if (j >= (m-1)) {
        break;
      } 
    }
    printf("%s \n", "PASSOU 1");
    printf("%s \n", "Counter start");
    printf("%d \n", counter);
    printf("%s \n", "Counter end");
    return counter;
  }

  if (n < m) {
    // printf("%s \n", "M >");
    for (i; i < (m-1); i ++) {
      for (j; j < (n-1); j++) {
        if (a[i] == b[j]) {
          printf("%s \n", "M >");
          printf("%c \n", a[i]);
          counter += 1;
          break;
        }
      }
      if (j >= (m-1)) {
        break;
      }
    }
    printf("%s \n", "PASSOU 2");
    printf("%s \n", "Counter start");
    printf("%d \n", counter);
    printf("%s \n", "Counter end");
    return counter;
  }

  if (n == m) {
    // printf("%s \n", "M >");
    for (i; i < (m-1); i ++) {
      for (j; j < (n-1); j++) {
        if (a[i] == b[j]) {
          printf("%s \n", "M >");
          printf("%c \n", a[i]);
          counter += 1;
          break;
        }
      }
      if (j >= (m-1)) {
        break;
      }
    }
    printf("%s \n", "PASSOU 3");

    printf("%s \n", "Counter start");
    printf("%d \n", counter);
    printf("%s \n", "Counter end");
    return counter;
  }
}
