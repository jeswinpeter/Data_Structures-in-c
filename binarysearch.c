/*This code sorts an array of numbers input by the user (using bubble sort) 
and searches for a number input by the user in the array(using binary search)*/
#include<stdio.h>
int main() {
   int n;      //Size of the array
   int A[20];  //Array used to take values
   int i;      //Variable incremented in for loop 
   int j;      //Variable incremented in for loop
   int temp;   //Temporary variable used to swap 2 array elements in buble sort loop (line -> 21 to 33)
printf("Enter the size of Array: ");
scanf("%d",&n);

//loop to construct array
   for(i=0;i<n;i++) {
      printf("Enter number %d : ",i+1);
      scanf("%d",&A[i]);
   }
printf("\n");

//Bubble sort loops
   for(i=0;i<n-1;i++){
      for(j=0;j<n-i-1;j++){

        if(A[j]>A[j+1]) {
            //Code to swap 2 adjacent elements of an array (line -> 28 to 30 ) 
            temp = A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
        }

      }
   }

 printf("The sorted array is: \n");
//loop to print the sorted array
   for (i = 0; i < n; i++)
    {
      printf("%d\t",A[i]);
    }
    printf("\n");

//begining of binary search
    int left = 0;       //used to indicate left most element of the part of the arraay that is being searched
    int right = n-1;    //used to indicate right most element of the part of the arraay that is being searched
    int mid;            //number used to indicate middle of the part of arraay that is being searched 
    int x;              //x is the number to be searched
    int flag = 0;       //variabe used to indicate search element is found in the array

 printf("Enter number to be searched\n");
 scanf("%d",&x);

   if(x < A[left] || x > A[right] ){
   printf("%d is not found in the array ",x);
   return 0;
   }

   /* Binary sort loop */
   while(left <= right){
      mid = (left + right)/2;
      if(A[mid] == x) {
         flag = 2;    //Indicates that search element is found
         break;
      }
      else if (x < A[mid]) {
         right = mid - 1;
      }
      else if (x > A[mid]) {
         left = mid + 1;
      }  
   }  

      /* ----- Result ----- */
        if(flag == 2){
            printf("%d is found in the array at position %d",x,mid+1);
         }
        if(flag == 0){
          printf("%d is not found in the array ",x);
         }

      return 0;
}
