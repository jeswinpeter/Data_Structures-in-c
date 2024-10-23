/* This code takes a string whith numbers and prints the frequency of a digit */
#include<stdio.h>
#include<string.h>

void main() {
    printf("Enter a string with numbers and letters: ");
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;
    int i = 0;
    char str[40];
    scanf("%s",str);
    // printf("%s",str);
    while(str[i] != '\0') {
        switch(str[i]) {
            case '0':
                count0++;
                break;
            case '1':
                count1++;
                break;
            case '2':
                count2++;
                break;
            case '3':
                count3++;
                break;
            case '4':
                count4++;
                break;
            case '5':
                count5++;
                break;
            case '6':
                count6++;
                break;
            case '7':
                count7++;
                break;
            case '8':
                count8++;
                break;
            case '9':
                count9++;
                break;
            default:
                break;
        }
        i++;
    }
    printf("%d %d %d %d %d %d %d %d %d %d",count0,count1,count2,count3,count4,count5,count6,count7,count8,count9);
}

