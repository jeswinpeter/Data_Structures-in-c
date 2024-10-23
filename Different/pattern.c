/*
    this code prints a specific patter using numbers
    if you enter 2 the output will be: 2 2 2 
                                       2 1 2
                                       2 2 2

*/

#include<stdio.h>

void main() {
    printf("Enter num less than 10: ");

    int n;
    scanf("%d", &n);
    int min=0;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            int a = i;
            if(i>n) a = 2*n - i;
            int b = j;
            if(b>n) b = 2*n - j;
            if(a<b) min = a;
            else min = b;
            printf("%d ",n+1-min);
        }
        printf("\n");
    }
}