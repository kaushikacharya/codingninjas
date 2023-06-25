/*  Problem: Top View Of Binary Tree
    URL: https://www.codingninjas.com/studio/problems/top-view-of-the-tree_799401
    Date: June 24, 2023
    Approach: Do BFS traversal. Store horizontal signed distance of the nodes from the root along with the nodes while inserting into queue.
                For any vetical axis, the node at the top most level belongs to the top view of the tree.
                In BFS traversal the top most node of a vertical axis is accessed before any other node of that vertical axis.
    
    Time Complexity: O(n) (Average case)
                        - Every node is accessed twice.
                        - O(1) average case for every find in unordered_map.
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

template <typename T>
class TreeNode {
    public:
        T val;
        TreeNode<T>* left;
        TreeNode<T>* right;

        TreeNode (T val)
        {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> top_view_vec;

    if (root == nullptr) {
        return top_view_vec;
    }
    
    // Breadth-first traverse the binary tree. Store top view position along with node.
    // Notation: Consider the top view positions as a number line with root being at origin.
    queue<pair<TreeNode<int>*,int>> Q;
    Q.push(make_pair(root, 0));

    unordered_map<int, int> pos_val_map;

    while (!Q.empty())
    {
        pair<TreeNode<int>*, int> pair_elem = Q.front();
        TreeNode<int>* node = pair_elem.first;
        int pos_top_view = pair_elem.second;
        Q.pop();

        // As we are traversing in BFS, the first node at any position represents the node at the top view.
        if (pos_val_map.find(pos_top_view) == pos_val_map.end())
        {
            pos_val_map[pos_top_view] = node->val;
        }

        if (node->left)
        {
            Q.push(make_pair(node->left, pos_top_view-1));
        }
        if (node->right)
        {
            Q.push(make_pair(node->right, pos_top_view+1));
        }
    }
    
    // Output expected in the left to right order
    int min_pos = 0;
    int max_pos = 0;

    for (unordered_map<int, int>::iterator it=pos_val_map.begin(); it != pos_val_map.end(); ++it)
    {
        int pos = (*it).first;
        min_pos = min(min_pos, pos);
        max_pos = max(max_pos, pos);
    }

    for (int pos = min_pos; pos != (max_pos + 1); ++pos)
    {
        unordered_map<int, int>::iterator it = pos_val_map.find(pos);

        if (it != pos_val_map.end())
        {
            top_view_vec.push_back((*it).second);
        }
    }

    return top_view_vec;
}

template <typename T>
TreeNode<T>* create_binary_tree(vector<T> vec, T null_value) {
    typename vector<T>::iterator it = vec.begin();

    if (*it == null_value) {
        return nullptr;
    }

    queue<TreeNode<T>*> Q;
    TreeNode<T>* root = new TreeNode(*it);
    Q.push(root);

    while (!Q.empty())
    {
        TreeNode<T>* node = Q.front();
        Q.pop();

        /* Check whether there are at least two more elements in the vector to represent left and right child 
            of the current node even if these children are null.
        */
        assert(((vec.end()-it) > 2) && "Insufficient elements in the input vector");

        // left child
        ++it;
        if (*it != null_value)
        {
            TreeNode<T>* left_node = new TreeNode<T>(*it);
            node->left = left_node;
            Q.push(left_node);
        }

        // right child
        ++it;
        if (*it != null_value)
        {
            TreeNode<T>* right_node = new TreeNode<T>(*it);
            node->right = right_node;
            Q.push(right_node);
        }
    }

    return root;   
}

lest::test tests[] = {
    CASE("Test Case #1") {
        vector<int> vec = {1,2,3,4,5,6,7,8,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {8,4,2,1,3,7};
        EXPECT(top_view_vec == expected_output);
    },
    CASE("Test Case #2") {
        vector<int> vec = {1,2,3,4,-1,5,6,-1,7,-1,-1,-1,-1,-1,-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {4,2,1,3,6};
        EXPECT(top_view_vec == expected_output);
    },
    CASE("Test Case #3") {
        // Only root node
        vector<int> vec = {5,-1,-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {5};
        EXPECT(top_view_vec == expected_output);
    },
    CASE("Test Case #4") {
        // Empty tree
        vector<int> vec = {-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {};
        EXPECT(top_view_vec == expected_output);
    },
    CASE("Test Case #5") {
        // Righmost descendant of left child of root part of top view
        vector<int> vec = {1,2,3,-1,4,-1,-1,-1,5,-1,6,-1,-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {2,1,3,6};
        EXPECT(top_view_vec == expected_output);
    },
    CASE("Test Case #6") {
        // Leftmost desendant of right child of root part of top view
        vector<int> vec = {1,2,3,-1,-1,4,-1,5,-1,6,-1,-1,-1};
        TreeNode<int>* root = create_binary_tree(vec, -1);
        vector<int> top_view_vec = getTopView(root);
        vector<int> expected_output = {6,2,1,3};
        EXPECT(top_view_vec == expected_output);
    }
};

int main(int argc, char** argv) {
    lest::run(tests, argc, argv);
}
