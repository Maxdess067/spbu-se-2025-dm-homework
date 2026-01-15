#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) {
        return 1;
    }
    
    char elements[MAX_N];

    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &elements[i]) != 1) {
            return 1;
        }
    }
    
    int index[MAX_N];
    
    for (int i = 0; i < k; i++) {
        index[i] = i;
    }
    
    int next = 1;
    
    while (next) {
        for (int i = 0; i < k; i++) {
            printf("%c", elements[index[i]]);
            if (i < k - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        next = 0;
        for (int i = k - 1; i >= 0; i--) {
            int max_position = n - k + i;
            
            if (index[i] < max_position) {
                index[i]++;
                for (int j = i + 1; j < k; j++) {
                    index[j] = index[j - 1] + 1;
                }
                
                next = 1;
                break;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
