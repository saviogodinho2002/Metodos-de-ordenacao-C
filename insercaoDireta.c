#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void imprimir (int X[], int n) {
  int i;
  printf("(");
  for (i=0; i<n; i++) printf("%3d ", X[i]);
  printf(")\n");
  }
void ordInsercao (int V[], int n) {
  int i, j, aux;
  for (i=1; i<n; i++) {
    aux = V[i];
    j = i-1;
    while (j > -1 && V[j] > aux) {
      V[j+1] = V[j];
      j -= 1;
      }
    V[j+1] = aux;
    }
  }



int main(){

    int vetElement1[10000],vetElement2[10000];

    for(int i=0;i<10000;i++)
            vetElement1[i] = (rand() % 10000)+1;



    clock_t Ticks[2];
    Ticks[0] = clock();

    ordInsercao(vetElement1,10000);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Médio caso: %g ms.\n", Tempo);

    for(int i = 0;i<10000;i++)
        vetElement2[9999-i] = vetElement1[i];



    clock_t Ticks1[2];
    Ticks1[0] = clock();

    ordInsercao(vetElement1,10000);

    Ticks1[1] = clock();
    Tempo = (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Melhor caso: %g ms.\n", Tempo);


    clock_t Ticks2[2];
    Ticks2[0] = clock();

    ordInsercao(vetElement2,10000);

    Ticks2[1] = clock();
    Tempo = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Pior caso: %g ms.\n", Tempo);


    return 0;
}

