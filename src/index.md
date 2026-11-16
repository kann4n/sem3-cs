---
layout: layout.njk
title: Data Structures and Algorithms
description: A study guide to data structures and algorithms, covering arrays, linked lists, stacks, queues, trees, graphs, searching, and sorting.
---

## Introduction

**Data structures and algorithms** are foundational concepts in computer science. Together they determine how efficiently a program can store, retrieve, and process data.

A **data structure** is a way of organizing data so that operations such as insertion, deletion, searching, and updating can be performed efficiently. The right choice depends on the problem and on the operations that matter most.

An **algorithm** is a finite, step-by-step procedure for solving a problem. Each step is well defined and unambiguous, so following the steps always produces the intended result.

---

## Data Structures

### Arrays

An array is the most basic linear data structure. A classic array stores a fixed-size sequence of elements of the same type in contiguous memory. Because the elements are contiguous, any element can be accessed in constant time using its index. Each element has a corresponding index number, usually starting at zero.

### Linked Lists

Like an array, a linked list is a linear data structure, but its elements are not stored in contiguous memory. Each node contains a value and a pointer to the next node. As a result, there is no direct indexing: reaching an element requires following the links from the start. Unlike a fixed-size array, a linked list can grow or shrink at runtime.

#### Types

- Single Linked List
- Circular Linked List
- Doubly Linked List

### Stacks

A stack is a linear data structure that follows <abbr title="Last In, First Out"><strong>LIFO</strong></abbr> order: the most recently added element is removed first. The core operations are push (add to the top) and pop (remove from the top).

A stack is an abstract data type: it defines the operations and their order, not a specific memory layout. It can be implemented with an array or a linked list, and the choice affects performance and memory use.

### Queues

A queue is a linear data structure that follows <abbr title="First In, First Out"><strong>FIFO</strong></abbr> order: the earliest element added is removed first. The core operations are enqueue (add to the back) and dequeue (remove from the front).

Like a stack, a queue is an abstract data type. It can be implemented with an array or a linked list; the choice depends on the operations and performance required.

### Trees

With the linear data structures covered, it is time to move on to non-linear data structures. The first non-linear structure to learn is the tree.

A tree resembles a tree in nature, but upside down. It has a **root** at the top and **leaves** at the bottom. The root is the first node; leaves are nodes with no children. A defining property of a tree is that there is exactly one path between any two nodes.

#### Types

**By the maximum number of children a node can have:**

- Binary Tree
- Ternary Tree
- N-ary Tree

**By the configuration (shape) of the nodes:**

- Complete Binary Tree
- Perfect Binary Tree

In a **complete binary tree**, every level is full except possibly the last, which is filled from left to right. In a **perfect binary tree**, every internal node has two children and all leaves are at the same depth.

Binary search trees (BSTs) are a separate, ordering-based classification rather than a shape: for every node, all keys in the left subtree are smaller than the node's key, and all keys in the right subtree are larger. Ternary search trees are a string-oriented structure related to tries.

### Graphs

Another important non-linear data structure is the graph. Like a tree, a graph consists of nodes and edges, but it has no particular root or leaf, and it can be traversed in many different orders.

Formally, a graph is a non-linear data structure consisting of a finite set of vertices (or nodes) and a set of edges that connect pairs of nodes. Each edge represents a relationship between two nodes. Graphs model many real-world problems, from road networks to social connections.

#### Common classifications

- **Directed or undirected:** edges may have a direction or not.
- **Weighted or unweighted:** edges may carry a cost or weight.
- **Cyclic or acyclic:** a graph may contain cycles or not.
- **Connected or disconnected:** every pair of nodes may be reachable, or the graph may have separate components.

### Advanced Data Structures

- **Heaps:** complete binary trees that keep the smallest or largest element at the root; commonly used to implement priority queues.
- **Hash tables:** key-value stores that use a hash function to achieve average `O(1)` lookup, insertion, and deletion.
- **Tries:** prefix trees used to store and search strings, such as in dictionaries and autocomplete.

---

## Algorithms

### Searching Algorithms

Searching algorithms locate a particular element or value within a collection of data. Here are two common examples.

#### Linear Search

Linear search, also called sequential search, checks each element in the list until it finds the target or reaches the end. It is the simplest searching algorithm and works on unsorted data, but it becomes slow for large collections.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n)</code> in the worst case, where <code>n</code> is the number of elements in the list, because every element may need to be checked. It is <code>O(1)</code> in the best case, when the target is the first element.</dd>
</dl>

#### Binary Search

Binary search is more efficient than linear search, but it requires a sorted list. It compares the target with the middle element and discards the half that cannot contain the target, halving the search space at each step until the target is found or the remaining range is empty.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(log n)</code> in the worst and average cases, where <code>n</code> is the number of elements in the list. The algorithm divides the search space in half at each step, so the number of steps grows logarithmically. In the best case, when the target is the middle element, it is <code>O(1)</code>.</dd>
</dl>

### Sorting Algorithms

A sorting algorithm rearranges the elements of a list into a defined order, usually according to a comparison operator such as `≤` or `≥`. The comparison decides the new order of the elements.

#### Bubble Sort

Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them when they are out of order. After each pass, the largest remaining element moves to its final position. With an early-exit flag that stops the algorithm when a pass makes no swaps, the best case is `O(n)` for an already sorted list.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the average and worst cases, and <code>O(n)</code> in the best case when the list is already sorted and the early-exit optimization is used.</dd>
</dl>

#### Selection Sort

Selection sort divides the list into a sorted prefix and an unsorted suffix. On each pass, it finds the smallest (or largest) element in the unsorted part and swaps it into the first unsorted position. The sorted prefix grows by one element per pass.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in all cases (worst, average, and best), because the algorithm always scans the remaining elements to find the minimum.</dd>
</dl>

#### Insertion Sort

Insertion sort builds the sorted list one element at a time. It takes the next element and inserts it into its correct position among the already sorted elements, shifting larger elements to the right to make room. It is stable and works well for small or nearly sorted lists.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the average and worst cases, and <code>O(n)</code> in the best case when the list is already sorted.</dd>
</dl>

#### Merge Sort

Merge sort is a divide-and-conquer algorithm. It divides the input list into two halves, sorts each half recursively, and then merges the two sorted halves into a single sorted list.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n log n)</code> in all cases.</dd>
  <dt>Space Complexity</dt>
  <dd><code>O(n)</code> additional space for the merge step.</dd>
</dl>

#### Quick Sort

Quick sort is a divide-and-conquer algorithm that selects a pivot element and partitions the list into elements less than or equal to the pivot and elements greater than the pivot. It then recursively sorts the two partitions.

<dl>
  <dt>Time Complexity</dt>
  <dd><code>O(n<sup>2</sup>)</code> in the worst case, when the partitions are highly unbalanced, and <code>O(n log n)</code> in the average and best cases.</dd>
  <dt>Space Complexity</dt>
  <dd><code>O(log n)</code> average recursion stack space.</dd>
</dl>

Choosing a random pivot or using median-of-three reduces the chance of hitting the worst case.

Choosing the right data structure and algorithm is a trade-off between time, memory, and implementation complexity. The best choice depends on the operations a program performs most often and on the size and shape of its input.
