# Coding Ninjas

## About

- This repository contains my solution to the [condingninjas](https://www.codingninjas.com/codestudio/home) problems.

## Unit Test Framework

- [lest](https://github.com/martinmoene/lest)
  - Unit tests are written using lest test framework which is written in a [single-file header only](./include/lest.hpp).

## Space Complexity Definition

- Convention followed in this repository:
  - Only the auxiliary space used by the algorithm is considered for space complexity.
  - Space consumed by the input arguments are ignored.

## Problems

| # | Problem | Solution | Unit Tests | Time Complexity | Space Complexity* |
|---|---------|----------|------------|-----------------|-----------|
|800332|[Merge Two Sorted Linked Lists](./notes/README.md#id-800332--merge-two-sorted-linked-lists)|[C++](./src/merge_two_sorted_linked_lists.cpp)|Y|$O(m+n)$|$O(1)$|
|893029|[Diagonal Traversal](./notes/README.md#id-893029--diagonal-traversal)|[C++](./src/diagonal_traversal.cpp)|Y|$O(n)$|$O(n)$ (worst case)|
|893056|[Kth Smallest Element](./notes/README.md#id-893056--kth-smallest-element)|[C++](./src/kth_smallest_element.cpp)|Y|$O(n\;log k)$|$O(k)$|
|893106|[Convert A Given Binary Tree To Doubly Linked List](./notes/README.md#id-893106--convert-a-given-binary-tree-to-doubly-linked-list)|[C++](./src/convert_binary_tree_to_doubly_linked_list.cpp)|Y|$O(n)$||
