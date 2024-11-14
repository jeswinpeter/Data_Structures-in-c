#include<stdio.h>
#include<stdlib.h>

struct node{
    float coeff;
    int expo;
    struct node *link;
};

struct node* insert(struct node *head, float co, int ex){
    struct node *temp;
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;
    if(head == NULL || ex > head->expo){
        newP->link = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp->link != NULL && temp->link->expo > ex){
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

struct node* create(struct node *head){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    float coeff;
    int expo;
    for(int i=0; i<n; i++){
        printf("Enter the exponent of x: ");
        scanf("%d",&expo);
        printf("Enter the coefficient of x^%d: ",expo);
        scanf("%f",&coeff);
        head = insert(head,coeff,expo);
    }
    return head;
}

struct node* polyAdd(struct node *head1, struct node *head2){
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->expo == ptr2->expo){
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr2->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo){
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    return head3;
}

void print(struct node *head){
    struct node *temp = head;
    if (head == NULL){
        printf("No Polynomial\n");
    }
    else{
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coeff, temp->expo);
            temp = temp->link;
            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

int main(){
    printf("Enter the first polynomial:\n");
    struct node *head1 = NULL;
    head1 = create(head1);
    printf("Polynomial 1: ");
    print(head1);
    printf("Enter the second polynomial:\n");
    struct node *head2 = NULL;
    head2 = create(head2);
    printf("Polynomial 2: ");
    print(head2);
    struct node* head3 = polyAdd(head1, head2);
    printf("Resultant polynomial: ");
    print(head3);
    return 0;
}