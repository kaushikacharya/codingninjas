/*  Problem: Diagonal Traversal
    URL: https://www.codingninjas.com/studio/problems/diagonal-traversal_893029
    Date: June 23, 2023
    Approach: Traverse the node and the descendents in the diagonal (slope=-1) before traversing the left child.
    Time Complexity: O(n)
    Space Complexity: O(n) (worst case)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

        BinaryTreeNode (T data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~BinaryTreeNode () {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
        }
};

vector<int> diagonalPath(BinaryTreeNode<int>* root) {
    vector<int> vec;

    if (root == nullptr) {
        return vec;
    }

    queue<BinaryTreeNode<int>*> Q;
    Q.push(root);

    while (!Q.empty()) {
        BinaryTreeNode<int>* node = Q.front();
        Q.pop();

        // Now process the current node and its right desencendants
        while (node)
        {
            vec.push_back(node->data);

            // If left child exists, push into queue so that it gets processed as part of the next diagonal level nodes.
            if (node->left)
            {
                Q.push(node->left);
            }
            node = node->right;
        }
    }

    return vec;
}

template <typename T>
BinaryTreeNode<T>* create_binary_tree(vector<T> vec, T null_value) {
    typename vector<T>::iterator it = vec.begin();

    if (*it == null_value) {
        return nullptr;
    }

    queue<BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T>* root = new BinaryTreeNode(*it);
    Q.push(root);

    while (!Q.empty())
    {
        BinaryTreeNode<T>* node = Q.front();
        Q.pop();

        // Check whether there are at least two more elements to represent left and right child of the current node
        // even if these children are null.
        assert(((vec.end()-it) > 2) && "Insufficient elements in the input vector");

        // left child
        ++it;
        if (*it != null_value)
        {
            BinaryTreeNode<T>* left_node = new BinaryTreeNode<T>(*it);
            node->left = left_node;
            Q.push(left_node);
        }

        // right child
        ++it;
        if (*it != null_value)
        {
            BinaryTreeNode<T>* right_node = new BinaryTreeNode<T>(*it);
            node->right = right_node;
            Q.push(right_node);
        }
    }

    return root;   
}

lest::test tests[] = {
    CASE("Test Case #1"){
        vector<int> vec = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> diagonal_path = diagonalPath(root);
        vector<int> expected_vec = {1, 3, 7, 2, 5, 6, 4};
        EXPECT(diagonal_path == expected_vec);
    },
    CASE("Test Case #2"){
        vector<int> vec = {1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> diagonal_path = diagonalPath(root);
        vector<int> expected_vec = {1, 3, 5, 2, 4};
        EXPECT(diagonal_path == expected_vec);
    },
    CASE("Test Case #3"){
        // Case: Null tree
        vector<int> vec = {-1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> diagonal_path = diagonalPath(root);
        vector<int> expected_vec = {};
        EXPECT(diagonal_path == expected_vec);
    },
    CASE("Test Case #4"){
        // Case: Tree with a single node
        vector<int> vec = {3, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> diagonal_path = diagonalPath(root);
        vector<int> expected_vec = {3};
        EXPECT(diagonal_path == expected_vec);
    },
    CASE("Test Case #5"){
        // Case: Adding a node to the tree of case #1
        vector<int> vec = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> diagonal_path = diagonalPath(root);
        vector<int> expected_vec = {1, 3, 7, 2, 5, 6, 8, 4};
        EXPECT(diagonal_path == expected_vec);
    }
};

int main(int argc, char** argv) {
    lest::run(tests, argc, argv);
}
