#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENTS 26

int main() {

    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }

    char elements[MAX_ELEMENTS];
    int index[MAX_ELEMENTS] = {0};

    for (int i = 0; i < n; i++) { 
        if (scanf(" %c", &elements[i]) != 1) {
            return 1;
        }
        index[elements[i] - 'a'] = i;
    }

    int hasse[MAX_ELEMENTS][MAX_ELEMENTS] = {0};

    for (int i = 0; i < m; i++) {
        char a, b;
        if (scanf(" %c %c", &a, &b) != 2) {
            return 1;
        }

        hasse[index[a - 'a']][index[b - 'a']] = 1;
    }

    int less[MAX_ELEMENTS][MAX_ELEMENTS] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            less[i][j] = hasse[i][j];
        }

    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (less[i][k] && less[k][j]) {
                    less[i][j] = 1;
                }
            }
        }

    }

    int min[MAX_ELEMENTS] = {0};
    int max[MAX_ELEMENTS] = {0};
    
    for (int i = 0; i < n; i++) {
        min[i] = 1;
        max[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (less[j][i]) {
                min[i] = 0;
            }
            if (less[i][j]) {
                max[i] = 0;
            }
        }
    }
    int first_min = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (elements[j] == 'a' + i && min[j]) {
                if (!first_min)
                printf(" ");
                printf("%c", elements[j]);
                first_min = 0;
                break;

            }
        }
    }
    printf("\n");

    int first_max = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (elements[j] == 'a' + i && max[j]) {
                if (!first_max)
                printf(" ");
                printf("%c", elements[j]);
                first_max = 0;
                break;
            }
        }
    }
    printf("\n");

    int min_count = 0;
    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (min[i]) {
            min_count++;
            min_index = i;
        }
    }

    if (min_count == 1) {
        int min_element = 1;
        for (int i = 0; i < n; i++){
            if (i != min_index && !less[min_index][i]) {
                min_element = 0;
                break;
            }
        }
        if (min_element) {
            printf("%c\n", elements[min_index]);   
        } else {
             printf("-\n");
        }
    } else {
    printf("-\n");
    }

    int max_count = 0;
    int max_index = -1;
    for (int i = 0; i < n; i++){
        if (max[i]) {
            max_count++;
            max_index = i;
        }
    } 

    if (max_count == 1) {
        int max_element =1;
        for (int i = 0; i < n; i++) {
            if (i != max_index && !less[i][max_index]) {
                max_element = 0;
                break;
            }
        }
        if (max_element) {
            printf ("%c\n", elements[max_index]);
        } else {
            printf ("-\n");
        }
    } else {
        printf ("-\n");
    }

    return 0;
}