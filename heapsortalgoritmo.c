#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
    heapSort(arr, n);

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
