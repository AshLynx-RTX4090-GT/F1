//#include <stdio.h>

//int main() {
    //>

int main() {
    int arr[] = {12, 45, 2, 67, 34, 89, 5};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];  // Initialize with first element
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}