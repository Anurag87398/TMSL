#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];


  int i = (low - 1);


  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {


      i++;


      swap(&array[i], &array[j]);
    }
  }


  swap(&array[i + 1], &array[high]);


  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);


    quickSort(array, low, pi - 1);


    quickSort(array, pi + 1, high);
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {

    int arr_size, arr[100];
    printf("Enter no. of elements: ");
    scanf("%d", &arr_size);
    printf("Enter the elements: \n");
    for(int i=0; i<arr_size; i++)
        scanf("%d", &arr[i]);


  printf("Array given by user: \n");
  printArray(arr, arr_size);

  quickSort(arr, 0, arr_size - 1);

  printf("Sorted array: \n");
  printArray(arr, arr_size);
}
