#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shell_sort(int *vet, int size)
{
    int i , j , value;
    int gap = 1;
    while(gap < size)
    {
        gap = 3*gap+1;
    }
    while (gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}



int main(){

    int vetElement1[10000],vetElement2[10000];

    for(int i=0;i<10000;i++)
            vetElement1[i] = (rand() % 10000)+1;



    clock_t Ticks[2];
    Ticks[0] = clock();

    shell_sort(vetElement1,10000);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Médio caso: %g ms.\n", Tempo);

    for(int i = 0;i<10000;i++)
        vetElement2[9999-i] = vetElement1[i];



    clock_t Ticks1[2];
    Ticks1[0] = clock();

    shell_sort(vetElement1,10000);

    Ticks1[1] = clock();
    Tempo = (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Melhor caso: %g ms.\n", Tempo);


    clock_t Ticks2[2];
    Ticks2[0] = clock();

    shell_sort(vetElement2,10000);

    Ticks2[1] = clock();
    Tempo = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Pior caso: %g ms.\n", Tempo);


    return 0;
}

