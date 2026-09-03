import time
from random import randint

import matplotlib.pyplot as plt


def genarate_random_number(n):
    array = []
    for i in range(n):
        array.append(randint(0, 1000))
    return array


def bubble_sort(array):
    n = len(array)
    for i in range(n):
        swapped = False
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                # Swap adjacent elements
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True

        # If no elements were swapped, the array is already sorted
        if not swapped:
            break
    return array


n, t = [], []
for size in range(1, 10000, 500):
    array = genarate_random_number(size)
    t1 = time.time_ns()
    sorted_array = bubble_sort(array)
    t2 = time.time_ns()
    n.append(size)
    t.append((t2 - t1) / 10**6)  # convert ns to ms


plt.scatter(n, t)
plt.xlabel("Array size")
plt.ylabel("Execution time(ms)")
plt.title("Bubble sort execution time vs size graph")
plt.show()
