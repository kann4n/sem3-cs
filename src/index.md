---
layout: layout.njk
title: Data Structures and Algorithms
description: A study guide to data structures, covering arrays, linked lists, stacks, queues, trees, graphs, and advanced structures.
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

Continue to [Algorithms]({{ '/algorithms/' | url }}) to learn about searching and sorting.
