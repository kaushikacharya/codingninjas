/*  Problem: Convert A Given Binary Tree To Doubly Linked List
    URL: https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106
    Date: 08th June 2023

    Approach:
        Iterative:
            In-place inorder traversal. As predecessor node gets identified,
            left and right pointers of consecutive nodes are updated.

    TIme complexity: O(n) where n = number of nodes in the tree.
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

template <typename T>
class BinaryTreeNode 
{
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* headNode = nullptr;
    BinaryTreeNode<int>* tailNode = nullptr;

    // Stack of pair (a. node  b. boolean flag to check whether node has been visited or not)
    stack<pair<BinaryTreeNode<int>*, bool>> stk;

    if (root == nullptr)
    {
        return headNode;
    }

    stk.push(make_pair(root, false));

    while (!stk.empty())
    {
        pair<BinaryTreeNode<int>*, bool> p = stk.top();
        stk.pop();

        if (p.second)
        {
            if (headNode == nullptr)
            {
                headNode = p.first;
            }

            // Assign double edge between the current node and the tail of doubly linked list and then
            // assign the current node as the tail node.
            if (tailNode)
            {
                tailNode->right = p.first;
                p.first->left = tailNode;
            }

            tailNode = p.first;
            continue;
        }

        // First push right node (if exists) into the stack
        if (p.first->right)
        {
            stk.push(make_pair(p.first->right, false));
        }
        // Now push the current node with visited flag as true
        stk.push(make_pair(p.first, true));
        // Push the left node (if exists) into the stack
        if (p.first->left)
        {
            stk.push(make_pair(p.first->left, false));
        }
    }

    return headNode;
}

// Re-create a tree from the level order traversal output
template <typename T>
BinaryTreeNode<T>* create_binary_tree(vector<T> vec, T null_value)
{
    // Case: Empty tree
    if (vec.empty())
    {
        return nullptr;
    }

    vector<queue<BinaryTreeNode<T>*> > vec_queue = {queue<BinaryTreeNode<T>*>(), queue<BinaryTreeNode<T>*>()};
    unsigned int i = 0;
    unsigned int j = 1;
    unsigned int k = 0;

    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(vec[0]);
    vec_queue[0].push(root);

    while (!vec_queue[0].empty() || !vec_queue[1].empty())
    {
        // vec_queue[i] elements represent the parent level
        // vec_queue[j]: Represent the child level which needs to be populated and linked from the parent level.
        assert(vec_queue[j].empty() && "Queue representing child level should be empty in the beginning of all iterations.");

        while (!vec_queue[i].empty())
        {
            BinaryTreeNode<T>* parentNode = vec_queue[i].front();
            vec_queue[i].pop();

            // Create two child nodes for the current parent node (Ignore if the data value is null_value)
            // Left child node
            ++k;
            if (vec[k] != null_value)
            {
                BinaryTreeNode<T>* childNodeLeft = new BinaryTreeNode<T>(vec[k]);
                parentNode->left = childNodeLeft;
                vec_queue[j].push(childNodeLeft);
            }

            // Right child node
            ++k;
            if (vec[k] != null_value)
            {
                BinaryTreeNode<T>* childNodeRight = new BinaryTreeNode<T>(vec[k]);
                parentNode->right = childNodeRight;
                vec_queue[j].push(childNodeRight);
            }
        }

        // Now swap i and j so that vec_queue[i] again represents the queue of parent nodes for the next level of the binary tree.
        i = (i + 1) % 2;
        j = (j + 1) % 2;
        
    }
    
    return root;
}

template <typename T>
vector<T> create_vector_from_double_linked_list(BinaryTreeNode<T>* head)
{
    vector<T> vec;

    if (head == nullptr)
    {
        return vec;
    }

    BinaryTreeNode<T>* node = head;

    while (node)
    {
        vec.push_back(node->data);
        node = node->right;
    }
    
    return vec;
}

lest::test tests[] = {
    CASE("Test Case #1"){
        vector<int> vec = {3, 1, 5, -1, 2, -1, -1, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        BinaryTreeNode<int>* head = BTtoDLL(root);
        vector<int> vec_dll = create_vector_from_double_linked_list(head);
        vector<int> vec_expected_output = {1, 2, 3, 5};
        EXPECT(vec_dll == vec_expected_output);
    },
    CASE("Test Case #2"){
        vector<int> vec = {9, 6, 10, 4, 7, -1, 11, -1, -1, -1, -1, -1, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        BinaryTreeNode<int>* head = BTtoDLL(root);
        vector<int> vec_dll = create_vector_from_double_linked_list(head);
        vector<int> vec_expected_output = {4, 6, 7, 9, 10, 11};
        EXPECT(vec_dll == vec_expected_output);
    },
    CASE("Test Case #3"){
        vector<int> vec = {};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        BinaryTreeNode<int>* head = BTtoDLL(root);
        vector<int> vec_dll = create_vector_from_double_linked_list(head);
        vector<int> vec_expected_output = {};
        EXPECT(vec_dll == vec_expected_output);
    },
    CASE("Test Case #4"){
        vector<int> vec = {1, 2, -1, 3, -1};
        BinaryTreeNode<int>* root = create_binary_tree(vec, -1);
        BinaryTreeNode<int>* head = BTtoDLL(root);
        vector<int> vec_dll = create_vector_from_double_linked_list(head);
        vector<int> vec_expected_output = {3, 2, 1};
        EXPECT(vec_dll == vec_expected_output);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
