#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    clock_t start, end;
    double cpu_time_used;

    char input[1000000];
    int arr[20000];
    int i = 0;

    printf("Insira os numeros separados por espaco: ");
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
  
    insertionSort(arr, n);

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