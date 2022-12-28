#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);

int main(void) {
  int n;

  
  printf("Enter the number of integers to sort: ");
  scanf("%d", &n);

  
  int arr[n];

  
  printf("Enter the integers: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  
  pid_t child_pid = fork();

  
  if (child_pid == 0) {
    
    insertion_sort(arr, n);

    printf("Sorted array (child process): ");
    for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  } else {
    
    bubble_sort(arr, n);

    
    wait(NULL);

    printf("Sorted array (parent process): ");
    for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  return 0;
}


void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}


void insertion_sort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
