# Notes

## Problems

- [Merge Two Sorted Linked Lists](#id-800332--merge-two-sorted-linked-lists)
- [Diagonal Traversal](#id-893029--diagonal-traversal)
- [Kth Smallest Element](#id-893056--kth-smallest-element)
- [Convert A Given Binary Tree To Doubly Linked List](#id-893106--convert-a-given-binary-tree-to-doubly-linked-list)

### ID: 800332 :: Merge Two Sorted Linked Lists

- [Educative](https://www.educative.io/merge-two-sorted-linked-lists) solution:
  - Learning:
    - Appropriate variable name:
      - In [my solution](../src/merge_two_sorted_linked_lists.cpp), ```curNodeMergedList``` should be replaced by something like ```tailNodeMergedList```.
- [User KNOCKCAT's solution in Leetcode](https://leetcode.com/problems/merge-two-sorted-lists/solutions/1826666/c-easy-to-understand-2-approaches-recursive-iterative/):
  - Recursion approach also shared along with the iterative one.

### ID: 893029 :: Diagonal Traversal

- Approach: Preorder traversal with right child before left child.

### ID: 893056 :: Kth Smallest Element

- Approach: Use max heap of size at most $k$.

### ID: 893106 :: Convert A Given Binary Tree To Doubly Linked List

- Approach: In-place inorder traversal using stack.
- [GeeksForGeeks](https://www.geeksforgeeks.org/convert-binary-tree-to-doubly-linked-list-by-keeping-track-of-visited-node/)
