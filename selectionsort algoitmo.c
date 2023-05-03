#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    // medindo tempo de execução do selection sort
    clock_t t;
    t = clock();
    selectionSort(arr, n);
    t = clock() - t;

    printf("O algoritmo de Selection Sort ordenou o array em %.5f segundos.\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}
