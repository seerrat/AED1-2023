#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n, i;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    int arr[n];

    // gerando valores aleatórios diferentes entre si
    srand(time(NULL));
    for(i = 0; i < n; i++){
        arr[i] = rand() % 20000 + 1;
        for(int j = 0; j < i; j++){
            if(arr[i] == arr[j]){
                i--;
                break;
            }
        }
    }

    // medindo tempo de execução do insertion sort
    clock_t t;
    t = clock();
    insertionSort(arr, n);
    t = clock() - t;

    printf("O algoritmo de Insertion Sort ordenou o array em %.5f segundos.\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}
