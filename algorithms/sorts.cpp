#include <iostream>
using namespace std;

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        swapped++;
      }
    }
    if (!swapped)
      return;
  }
}

void insertion_sort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void merge(int *arr, int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int L[n1], R[n2]; // temporary copy of original array
  // copy data
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

  int i, j, k;
  i = j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void merge_sort(int *arr, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, 0, n - 1);

  print_array(arr, n);
  return 0;
}
