#include <stdio.h>

int main() {
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {5, 0, 0, 6},
        {0, 0, 0, 0}
    };

    int sparse[10][3];
    int k = 1;    

    int rows = 4;
    int cols = 4;

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0;   

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                sparse[0][2]++;
            }
        }
    }

    printf("Sparse Matrix (Row Col Value)\n");
    for(int i = 0; i <= sparse[0][2]; i++) {
        printf("%d   %d   %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}
