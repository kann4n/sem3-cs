#include <iostream>
#include <vector>
using namespace std;

/* helper funtions */

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* sorting algorithms */

/* Bubble Sort */
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

/* Insertion Sort */
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

/* Merge Sort */

void merge(int *arr, int l, int mid, int r) {
  std::vector<int> left(arr + l, arr + mid + 1);
  std::vector<int> right(arr + mid + 1, arr + r + 1);

  int i = 0, j = 0, k = l;

  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j])
      arr[k++] = left[i++];
    else
      arr[k++] = right[j++];
  }

  while (i < left.size())
    arr[k++] = left[i++];

  while (j < right.size())
    arr[k++] = right[j++];
}

void merge_sort(int *arr, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }
}

/* Partion Algorithms */

/* Lomuto Partion Algorithm */
int lomuto_partion(int *arr, int l, int r) {
  int i, j, pivot;
  pivot = arr[r];
  i = l - 1;

  for (j = l; j < r; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[j]);
  return i + 1;
}

/* Hoares Partion Algorithm */
int hoares_partion(int *arr, int l, int r) {
  int i, j, pivot;
  i = l - 1;
  j = r + 1;
  pivot = arr[l];
  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      return j;

    // swap if arr[i] and arr[j]
    swap(&arr[i], &arr[j]);
  }
}

/* Quicksort */
void quicksort(int *arr, int l, int r, char partion_algo) {
  // print_array(arr + l, r - l + 1);
  // cout << l << " " << r << endl << endl;
  if (l < r) {
    if (partion_algo == 'l') {
      int p = lomuto_partion(arr, l, r);
      // can skip p cause it already sorted
      quicksort(arr, l, p - 1, partion_algo);
      quicksort(arr, p + 1, r, partion_algo);
    }
    if (partion_algo == 'h') {
      int p = hoares_partion(arr, l, r);
      quicksort(arr, l, p, partion_algo);
      quicksort(arr, p + 1, r, partion_algo);
    }
  }
}

int main() {
  int arr[] = {3, 2, 4, 8, 1, 6, 7, 5};
  // int arr[] = {3, 2, 4, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Before\n";
  print_array(arr, n);
  // cout << lomuto_partion(arr, 0, n - 1);
  // cout << hoares_partion(arr, 0, n - 1);
  // merge_sort(arr, 0, n - 1);
  quicksort(arr, 0, n - 1, 'h');
  cout << "After\n";
  print_array(arr, n);

  return 0;
}
