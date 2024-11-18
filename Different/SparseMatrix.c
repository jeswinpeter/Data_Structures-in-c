#include<stdio.h>

void main() {
    
    int rows;
    int columns;
    printf("Enter no of rows of the matrix: ");
    scanf("%d",&rows);
    printf("Enter no of columns of the matrix: ");
    scanf("%d",&columns);

    int matrix[rows][columns];
    int sparse[80][3];

    printf("Enter elements to the matrix: ");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("---- Given Matrix ----\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    int k = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = columns;
    sparse[0][2] = k - 1;

    printf("\n---- Sparse Matrix ----\n");
    printf("Rows   columns   Value\n");
    for(int i = 0; i < k; i++) {
        printf(" %d      %d       %d\n",sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}