#include <stdio.h>

#define MAX_N 8

int next(int *arr, int n) {

    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return 0;
    
    int j = n - 1;
    while (arr[j] <= arr[i]) j--;
    
    int buffer = arr[i];
    arr[i] = arr[j];
    arr[j] = buffer;
    
    int left = i + 1, right = n - 1;
    while (left < right) {
        buffer = arr[left];
        arr[left] = arr[right];
        arr[right] = buffer;
        left++;
        right--;
    }
    
    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    char elements[MAX_N];
    int index[MAX_N];
    
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &elements[i]) != 1) {
            return 1;
        }
        index[i] = i; 
    }
    
    do {
        for (int i = 0; i < n; i++) {
            printf("%c", elements[index[i]]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    } while (next(index, n));
    
    printf("\n");
    return 0;
}
