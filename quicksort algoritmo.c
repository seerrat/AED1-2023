#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    char input[1000000];
    int arr[20000];
    int i = 0;

    printf("Insira os números separados por espaço: ");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " ");
    while (token != NULL) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    int n = i;
     // Início do cronômetro
    start = clock();
    quickSort(arr, 0, n - 1);
    // Fim do cronômetro
    end = clock();

    // Cálculo do tempo de execução em segundos
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("Tempo de execução: %f segundos\n", cpu_time_used);


    return 0;
}
