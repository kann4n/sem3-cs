---
layout: layout.njk
title: Algorithms
description: A study guide to searching and sorting algorithms, covering linear search, binary search, bubble sort, selection sort, insertion sort, merge sort, and quick sort.
---

All C++ examples use standard C-style arrays (`int arr[]`) and an explicit `int size` parameter, requiring no external headers. No `main` function is included; call these functions from your own code. The search functions return the index of the target, or `-1` if it is not present; the sorting functions reorder the array in place.

## Searching Algorithms

Searching algorithms locate a particular element or value within a collection of data. Here are two common examples.

### Linear Search

Linear search, also called sequential search, checks each element in the list until it finds the target or reaches the end. It is the simplest searching algorithm and works on unsorted data, but it becomes slow for large collections.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n)</code> in the worst case, where <code>n</code> is the number of elements in the list, because every element may need to be checked. It is <code>O(1)</code> in the best case, when the target is the first element.</dd>
</dl>

**C++ implementation**

```cpp
int linearSearch(const int values[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}
```

### Binary Search

Binary search is more efficient than linear search, but it requires a sorted list. It compares the target with the middle element and discards the half that cannot contain the target, halving the search space at each step until the target is found or the remaining range is empty.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(log n)</code> in the worst and average cases, where <code>n</code> is the number of elements in the list. The algorithm divides the search space in half at each step, so the number of steps grows logarithmically. In the best case, when the target is the middle element, it is <code>O(1)</code>.</dd>
</dl>

**C++ implementation**

```cpp
int binarySearch(const int values[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (values[middle] == target) {
            return middle;
        }

        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}
```

## Sorting Algorithms

A sorting algorithm rearranges the elements of a list into a defined order, usually according to a comparison operator such as `≤` or `≥`. The comparison decides the new order of the elements.

### Bubble Sort

Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them when they are out of order. After each pass, the largest remaining element moves to its final position. With an early-exit flag that stops the algorithm when a pass makes no swaps, the best case is `O(n)` for an already sorted list.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the average and worst cases, and <code>O(n)</code> in the best case when the list is already sorted and the early-exit optimization is used.</dd>
</dl>

**C++ implementation**

```cpp
void bubbleSort(int values[], int size) {
    for (int pass = 0; pass < size - 1; ++pass) {
        bool swapped = false;

        for (int i = 0; i < size - 1 - pass; ++i) {
            if (values[i] > values[i + 1]) {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}
```

### Selection Sort

Selection sort divides the list into a sorted prefix and an unsorted suffix. On each pass, it finds the smallest (or largest) element in the unsorted part and swaps it into the first unsorted position. The sorted prefix grows by one element per pass.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in all cases (worst, average, and best), because the algorithm always scans the remaining elements to find the minimum.</dd>
</dl>

**C++ implementation**

```cpp
void selectionSort(int values[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int smallest = i;

        for (int j = i + 1; j < size; ++j) {
            if (values[j] < values[smallest]) {
                smallest = j;
            }
        }

        if (smallest != i) {
            int temp = values[i];
            values[i] = values[smallest];
            values[smallest] = temp;
        }
    }
}
```

### Insertion Sort

Insertion sort builds the sorted list one element at a time. It takes the next element and inserts it into its correct position among the already sorted elements, shifting larger elements to the right to make room. It is stable and works well for small or nearly sorted lists.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the average and worst cases, and <code>O(n)</code> in the best case when the list is already sorted.</dd>
</dl>

**C++ implementation**

```cpp
void insertionSort(int values[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key) {
            values[j + 1] = values[j];
            --j;
        }

        values[j + 1] = key;
    }
}
```

### Merge Sort

Merge sort is a divide-and-conquer algorithm. It divides the input list into two halves, sorts each half recursively, and then merges the two sorted halves into a single sorted list.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n log n)</code> in all cases.</dd>
  <dt>Space Complexity</dt>
  <dd><code>O(n)</code> additional space for the merge step.</dd>
</dl>

**C++ implementation**

```cpp
void mergeHalves(int values[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftHalf = new int[leftSize];
    int* rightHalf = new int[rightSize];

    for (int i = 0; i < leftSize; ++i) {
        leftHalf[i] = values[left + i];
    }
    for (int j = 0; j < rightSize; ++j) {
        rightHalf[j] = values[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftHalf[i] <= rightHalf[j]) {
            values[k++] = leftHalf[i++];
        } else {
            values[k++] = rightHalf[j++];
        }
    }

    while (i < leftSize) {
        values[k++] = leftHalf[i++];
    }

    while (j < rightSize) {
        values[k++] = rightHalf[j++];
    }

    delete[] leftHalf;
    delete[] rightHalf;
}

void mergeSortRange(int values[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSortRange(values, left, middle);
    mergeSortRange(values, middle + 1, right);
    mergeHalves(values, left, middle, right);
}

void mergeSort(int values[], int size) {
    if (size <= 1) {
        return;
    }

    mergeSortRange(values, 0, size - 1);
}
```

### Quick Sort

Quick sort is a divide-and-conquer algorithm that selects a pivot element and partitions the list into elements less than or equal to the pivot and elements greater than the pivot. It then recursively sorts the two partitions.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the worst case, when the partitions are highly unbalanced, and <code>O(n log n)</code> in the average and best cases.</dd>
  <dt>Space Complexity</dt>
  <dd><code>O(log n)</code> average recursion stack space.</dd>
</dl>

**C++ implementation**

```cpp
int lomutoPartition(int values[], int low, int high) {
    int pivot = values[high];
    int smaller = low - 1;

    for (int current = low; current < high; ++current) {
        if (values[current] <= pivot) {
            ++smaller;
            int temp = values[smaller];
            values[smaller] = values[current];
            values[current] = temp;
        }
    }

    int temp = values[smaller + 1];
    values[smaller + 1] = values[high];
    values[high] = temp;

    return smaller + 1;
}

void quickSortRange(int values[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = lomutoPartition(values, low, high);
    quickSortRange(values, low, pivotIndex - 1);
    quickSortRange(values, pivotIndex + 1, high);
}

void quickSort(int values[], int size) {
    if (size <= 1) {
        return;
    }

    quickSortRange(values, 0, size - 1);
}
```

Choosing a random pivot or using median-of-three reduces the chance of hitting the worst case.

Choosing the right data structure and algorithm is a trade-off between time, memory, and implementation complexity. The best choice depends on the operations a program performs most often and on the size and shape of its input.

