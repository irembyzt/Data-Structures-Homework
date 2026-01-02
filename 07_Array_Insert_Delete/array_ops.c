#include <stdio.h>

#define MAX 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
void insert(int arr[], int *size, int index, int value) {
    for (int i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
}
 
void delete(int arr[], int *size, int index) {
    for (int i = index; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int size = 4;

    printf("Ilk dizi: ");
    printArray(arr, size);

    insert(arr, &size, 2, 25);
    printf("Eklemeden sonra: ");
    printArray(arr, size);

    delete(arr, &size, 3);
    printf("Silmeden sonra: ");
    printArray(arr, size);

    return 0;
}
