#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
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

    // medindo tempo de execução do merge sort
    clock_t t;
    t = clock();
    mergeSort(arr, 0, n-1);
    t = clock() - t;

    printf("O algoritmo de Merge Sort ordenou o array em %.5f segundos.\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}
