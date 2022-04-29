#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}




int main(){

    int vetElement1[10000],vetElement2[10000];

    for(int i=0;i<10000;i++)
            vetElement1[i] = (rand() % 10000)+1;



    clock_t Ticks[2];
    Ticks[0] = clock();

    quick_sort(vetElement1,0,10000-1);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Médio caso: %g ms.\n", Tempo);

    for(int i = 0;i<10000;i++)
        vetElement2[9999-i] = vetElement1[i];



    clock_t Ticks1[2];
    Ticks1[0] = clock();

    quick_sort(vetElement1,0,10000-1);

    Ticks1[1] = clock();
    Tempo = (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Melhor caso: %g ms.\n", Tempo);


    clock_t Ticks2[2];
    Ticks2[0] = clock();

    quick_sort(vetElement2,0,10000-1);

    Ticks2[1] = clock();
    Tempo = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Pior caso: %g ms.\n", Tempo);


    return 0;
}

