#include<stdio.h>
void main(){
	int size;
 	int i;
 	int j;
 	int temp;
	int a[30];
	
    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter the elements: \n");
    for (i = 0; i < size; i++) {
        scanf("%d",&a[i]);
    }
    
    printf("The unsorted array is : \n");  
    for (i = 0; i < size; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");

    /* ---- Insertion sort loop ---- */
    i = 1;
    while(i < size) {
        j = i-1;
        temp = a[i];
        while(j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
        i++;
    }

    printf("The sorted array is : \n");
    for (i = 0; i < size; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");

}