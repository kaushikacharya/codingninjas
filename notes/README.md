# Notes

## Problems

- [Top View Of Binary Tree](#id-799401--top-view-of-binary-tree)
- [Merge Two Sorted Linked Lists](#id-800332--merge-two-sorted-linked-lists)
- [Diagonal Traversal](#id-893029--diagonal-traversal)
- [Kth Smallest Element](#id-893056--kth-smallest-element)
- [Convert A Given Binary Tree To Doubly Linked List](#id-893106--convert-a-given-binary-tree-to-doubly-linked-list)

### ID: 799401 :: Top View Of Binary Tree

- Approach: 
  - BFS traversal with pair of nodes and their horizontal distance from the root as elements of queue.
  - Storage of top view node for each horizontal distance:
    - Usage of **map** vs **unordered_map**:
      - ```map``` would store the keys (horizontal distance) in sorted order. One can iterate the map and populate the top view vector. But this can take $O(n\,logn)$ time for inserting the elements.
      - ```unordered_map``` on average would take $O(n)$ for inserting the elements of the top view.
        - Extraction of top tree node values in sorted order:
          - Iterate the keys and identify the range of the keys.
          - Iterate over the range of the keys. Find the top view node value corresponding to the keys and populate the top view vector.

### ID: 800332 :: Merge Two Sorted Linked Lists

- [Educative](https://www.educative.io/merge-two-sorted-linked-lists) solution:
  - Learning:
    - Appropriate variable name:
      - In [my solution](../src/merge_two_sorted_linked_lists.cpp), ```curNodeMergedList``` should be replaced by something like ```tailNodeMergedList```.
- [User KNOCKCAT's solution in Leetcode](https://leetcode.com/problems/merge-two-sorted-lists/solutions/1826666/c-easy-to-understand-2-approaches-recursive-iterative/):
  - Recursion approach also shared along with the iterative one.

### ID: 893029 :: Diagonal Traversal

- Approach: Preorder traversal with right child before left child.
- [Scaler Topics](https://www.scaler.com/topics/diagonal-traversal-of-binary-tree/) explains the solution.
- **TODO** Recursive approach

### ID: 893056 :: Kth Smallest Element

- Approach: Use max heap of size at most $k$.

### ID: 893106 :: Convert A Given Binary Tree To Doubly Linked List

- Approach: In-place inorder traversal using stack.
- [GeeksForGeeks](https://www.geeksforgeeks.org/convert-binary-tree-to-doubly-linked-list-by-keeping-track-of-visited-node/)
