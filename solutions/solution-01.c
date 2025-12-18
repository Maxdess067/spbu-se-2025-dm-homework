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

    int relat[MAX_ELEMENTS][MAX_ELEMENTS] = {0};

    for (int i = 0; i < m; i++) {
        char a, b;
        if (scanf(" %c %c", &a, &b) != 2) {
            return 1;
            
        }
        relat[index[a - 'a']][index[b - 'a']] = 1;
    }

    int ref = 1;
    int sym = 1;
    int trans = 1;
    int anti = 1;

    for (int i = 0; i < n; i++) {
        if (relat[i][i] == 0) {
            ref = 0;
            break;
        }
    }

    for (int i = 0; i < n && sym; i++) {
        for (int j = 0; j < n; j++) {
            if (relat[i][j] != relat[j][i]) {
                sym = 0;
                break;
            }
        }
    }

    for (int i = 0; i < n && trans; i++) {
        for (int j = 0; j < n && trans; j++) {
            if (relat[i][j]) {
                for (int k = 0; k < n && trans; k++) {
                    if (relat[j][k] && !relat[i][k]) {
                        trans = 0;
                        break;
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < n && anti; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && relat[i][j] && relat[j][i]) {
                anti = 0;
                break;
            }
        }
    }
    
    printf("%c%c%c%c\n",
            ref ? 'R' : '*',
            sym ? 'S' : '*',
            trans ? 'T' : '*',
            anti ? 'A' : '*' );

    return 0; 

}