#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node * create() {
    struct node * temp = malloc(sizeof(struct node)) ;
    return temp;
}

struct node * head = NULL;
struct node * top = NULL;
struct node * temp;
struct node * ptr;

struct node * push(struct node * head, int value) {
    temp = create();
    if(head == NULL) {
        head = temp;
        head -> data = value;
        head -> link = NULL;
        top = head;
    }
    else {
        temp -> data = value;
        temp -> link = head;
        head = temp;
        top = head;
    }
    return head;
}

struct node * pop(struct node * head) {
    if(head == NULL) {
        printf("Stack is EMPTY !!\n");
    }
    else {
        temp = head;
        printf("%d is popped\n",head -> data);
        head = head -> link;
        top  = head;
        free(temp);
        return head;
    }
    
}

void display(struct node * head) {
    if(head == NULL) {
        printf("!! The Stack is Empty !!\n");
    }
    else {
        ptr = head;
        printf("----- STACK -----\n");
        while (ptr != NULL) {       
            printf("%d\t",ptr -> data);
            ptr = ptr -> link;
        }
        printf("\n-----------------\n");
    }
}

int main() {
    int choice;
    int value;

    printf("----- MENU -----\n");
    printf("1 -> push()\n");
    printf("2 -> pop()\n");
    printf("3 -> Display()\n");
    printf("4 -> Exit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter value to push : ");
                scanf("%d",&value);
                head = push(head,value);
                break;

            case 2:
                head = pop(head);
                break;

            case 3: 
                display(head);
                break;

            case 4:
                printf("Exiting....");
                return 0;
            
            default:
                printf("Enter a valid choice !!");
                break;
        }
    }
}