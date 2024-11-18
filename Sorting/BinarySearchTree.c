#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
}node;

node * createNode(int data) {
    node * newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

node * insert(node * root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root -> data) {
        root -> left = insert(root -> left, data);
    }
    else {
        root -> right = insert(root -> right, data);
    }

    return root;
}

void inorder(node * root) {
    if(root != NULL) {
        inorder(root -> left);
        printf("%d ",root -> data);
        inorder(root -> right);
    }
}

int main() {
    node * root = NULL;

    int choice;
    int value;

    printf("----- MENU -----\n");
    printf("1 -> insert data\n");
    printf("2 -> inorder traversal\n");
    printf("3 -> Exit\n");

    while (1)
    {   
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to add: ");
            scanf("%d",&value);
            root = insert(root,value);
            break;
        
        case 2:
            inorder(root);
            printf("\n");
            break;
        
        case 3: 
            printf("EXITING....");
            return 0;

        default:
            printf("!! Enter a valid choice !!");
            break;
        }
    }
    
}