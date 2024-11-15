/* This program tokenizes a string and stores them in an array
    Then Sorts the array of tokens using Bubble sort */

#include<stdio.h>
#include<string.h>

#define max_words 10
#define max_chars 20

int main() {
    char string[100];
    printf("Enter a string: ");
    fgets(string,sizeof(string),stdin);
    printf("String: %s",string);

    char word[max_words][max_chars];
    char *token = strtok(string, " ");
    char temp[100];

    /* Tokenizing the words and storing in an array */
    int  count= 0;
    while (token != NULL){
        printf("%s\n",token);
        strncpy(word[count], token, max_chars - 1);
        word[count][max_chars - 1] = '\0';
        count++;

        token = strtok(NULL, " ");
    }
    
    printf("The 1st letters of the words are: ");
    for(int i = 0; i < count; i++ ) {
        printf("%c\t",word[i][0]);
    }
    printf("\n");

    /* Sorting the words using Bubble sort */
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count-i-1; j++) {
            if(strcmp(word[j], word[j + 1]) > 0){
                strncpy(temp,word[j],99);
                strncpy(word[j],word[j+1],max_chars);
                strncpy(word[j+1],temp,max_chars);
            }
        }
    }

    printf("After Bubble sort the words are: \n");
    for(int i = 0; i < count; i++ ) {
        printf("%s\n",word[i]);
    }
    return 0;

}