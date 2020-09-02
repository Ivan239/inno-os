#include <stdio.h>

void bubble_sort(int arr[], int len) {
    int i, j;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    // Test of correctness
    const int len = 5;
    int arr[] = {5, 4, 3, 2, 1};

    bubble_sort(arr, len);

    printf("Initial array: 5 4 3 2 1\nArray after bubble sort: ");
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
