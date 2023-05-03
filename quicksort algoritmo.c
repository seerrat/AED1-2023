#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 20001 + 1; // Gera um número aleatório entre 1 e 20000
    }

    clock_t t = clock();
    quickSort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos", time_taken);

    return 0;
}

