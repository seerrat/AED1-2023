#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
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
