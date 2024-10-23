/* sum of digits of a number */
#include<stdio.h>

void main() {
    int n;
    int sum = 0;
    printf("Enter any number: ");
    scanf("%d",&n);

    printf("last digit = %d\n",n%10);
    // n = n/10;
    // printf("New n = %d\n",n);

    while (n != 0)
    {
        sum += n%10;
        n = n/10;
    }
    printf("sum = %d\n",sum);
}
