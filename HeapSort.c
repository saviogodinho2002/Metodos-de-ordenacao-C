#include <time.h>
#include <stdlib.h>
#include <stdio.h>

  void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }

  void heapify(int arr[], int n, int i) {
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;


    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;


    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }

  void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      heapify(arr, i, 0);
    }
  }

  void display(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

int main(){

    int vetElement1[10000],vetElement2[10000];

    for(int i=0;i<10000;i++)
            vetElement1[i] = (rand() % 10000)+1;



    clock_t Ticks[2];
    Ticks[0] = clock();

    heapSort(vetElement1,10000);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Médio caso: %g ms.\n", Tempo);

    for(int i = 0;i<10000;i++)
        vetElement2[9999-i] = vetElement1[i];



    clock_t Ticks1[2];
    Ticks1[0] = clock();

    heapSort(vetElement1,10000);

    Ticks1[1] = clock();
    Tempo = (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Melhor caso: %g ms.\n", Tempo);


    clock_t Ticks2[2];
    Ticks2[0] = clock();

    heapSort(vetElement2,10000);

    Ticks2[1] = clock();
    Tempo = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Pior caso: %g ms.\n", Tempo);


    return 0;
}

