#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 26
#define MAX_EDGES 650

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }

    char elements[MAX_ELEMENTS];
    int index[MAX_ELEMENTS];

    for (int i =0; i < 26; i++) index[i] = -1;

    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &elements[i]) != 1) {
            return 1;
        }
        index[elements[i] - 'a'] = i;
    }

    int from[MAX_EDGES];
    int to[MAX_EDGES];
    int degree[MAX_ELEMENTS] = {0};

    for (int i = 0; i < m; i++) {
        char a, b;
        if (scanf(" %c %c", &a, &b) != 2) {
            return 1;
        }
        from[i] = index[a - 'a'];
        to[i] = index[b - 'a'];
        degree[to[i]]++;   
    }

    int result[MAX_ELEMENTS];
    int count = 0;
    int used[MAX_ELEMENTS] = {0};

    while (count < n) {
        int found = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && degree[i] == 0) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            result[count++] = found;
            used[found] = 1;

            for (int j = 0; j < m; j++) {
                if (from[j] == found) {
                    degree[to[j]]--;
                }
            }
        }  
        if (found == -1) {
            printf("Ошибка: некорректный ЧУМ\n");
            return 1;
        }
    
    }
    
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", elements[result[i]], i + 1);
    }

    return 0;

}
