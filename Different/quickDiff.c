/* This program performs quick sort on an array of numbers 
    useing a single function */
#include<stdio.h>

int aray[10];
int upper;
int lower = 0;
int size;
int pivot;
int i = 0;

void quickSort(int aray[],int lower, int upper) {
    if(lower < upper) {
        int temp;
        pivot = aray[lower];
        int start = lower;
        int end = upper;
        while(start < end) {
            while (aray[start] <= pivot && start <= upper){
                start++;  
            }
            while (aray[end] > pivot && end >= lower){
                end--;
            }
            if(start < end){
                temp = aray[start];
                aray[start] = aray[end];
                aray[end] = temp;
            }   
        }
        temp = aray[lower];
        aray[lower] = aray[end];
        aray[end] = temp;
    
        quickSort(aray,lower,end -1);
        quickSort(aray,end + 1,upper);
    }
}

void main() {
     printf("Enter size of array: ");
    scanf("%d",&size);
    upper = size - 1;
    
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

    quickSort(aray, lower, upper);

    //loop to print the sorted array
    printf("\n--------- Sorted ----------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",aray[i]);
    }
    printf("\n--------- Sorted ----------\n\n");
}