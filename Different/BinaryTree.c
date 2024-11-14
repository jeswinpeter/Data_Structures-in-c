#include<stdio.h>

void build(int a[],int i,int item){
    char ch;
    int value;
    a[i] = item;
    printf("Do you have a left child for %d? (y/n): ",item);
    scanf(" %c",&ch);
    if(ch == 'y'|| ch == 'Y'){
        printf("\nEnter the value of left child: ");
        scanf("%d",&value);
        build(a,(2*i)+1,value);
    }
    printf("\nDo you have a right child for %d? (y/n): ",item);
    scanf(" %c",&ch);
    if(ch == 'y' || ch == 'Y'){
        printf("\nEnter the value of right child: ");
        scanf(" %d",&value);
        build(a,(2*i)+2,value);
    }
}

int main(){
    int i,n;
    int item,a[100];
    printf("\nEnter the total number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i] = -1;
    }
    printf("\nEnter the root node: ");
    scanf("%d",&item);
    build(a,0,item);
    printf("\nBINARY TREE:\n");
    for(i=0;i<n;i++){
        if(a[i] == -1){
            printf("-\t");
        }
        else{
            printf("%d\t",a[i]);
        }
    }
    printf("\n");
    return 0;
}