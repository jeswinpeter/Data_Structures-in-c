#include<stdio.h>

void main(){
    int small;
    int i,j;
    int size;
    int temp;
	int a[30];
	

    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d",&a[i]);
    }

    printf("The unsorted array is : \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",a[i]); 
    }
    printf("\n");\

    while (i < size){
        small = i;
        j = i + 1;
        while (j < size){
            if(a[j] < a[small]) {
                small = j;
            }
            j++;
        }
        if(i != small) {
            temp = a[small];
            a[small] = a[i];
            a[i] = temp;
        }
        i++;
    }
    

    printf("The sorted array is : \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}