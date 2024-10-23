/* This code implements Merge sort algorithm */
#include<stdio.h>

void main() {
    printf("Enter size of array: ");
    int size = scanf("%d",&size);
    int aray[size];

//loop to construct array
    for(int i = 0; i < size; i++) {
        printf("Enter number to array: ");
        scanf("%d",&aray[i]);
    }

//loop to print the unsorted array
    printf("--------- Unsorted ----------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",aray[i]);
    }
    printf("\n--------- Unsorted ----------\n\n");

//loop to print the sorted array
    printf("--------- Sorted ----------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",aray[i]);
    }
    printf("\n--------- Sorted ----------\n\n");

    printf("Coming soon!!");
}