#include <stdio.h>

int array[31];

void merge(int array[], int left, int mid, int right) {
    int i = left; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left; // Index for temporary array
    int temp[100]; // Temporary array to hold merged values

    // Merging the two halves into temp[]
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = array[i++];
    }

    // Copy remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = array[j++];
    }

    // Copy the merged elements back into the original array
    for (k = left; k <= right; k++) {
        array[k] = temp[k]; 
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2; // Local mid variable
        mergeSort(array, left, mid); // Sort the left half
        mergeSort(array, mid + 1, right); // Sort the right half
        merge(array, left, mid, right); // Merge the sorted halves
    }
}

int main() { 
    int size;
    printf("Enter size of Array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("\n -------- Unsorted -------- \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n -------- Unsorted -------- \n");

    mergeSort(array, 0, size - 1);

    printf(" -------- Sorted -------- \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n -------- Sorted -------- \n");

    return 0; // Return 0 to indicate successful execution
}