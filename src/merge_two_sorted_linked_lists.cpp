/*  Problem: Merge Two Sorted Linked Lists
    URL: https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332
    Date: 06th June 2023

    Time Complexity: O(m+n) where m,n are the length of the two input linked lists.
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node (T data) {
            next = nullptr;
            this->data = data;
        }

        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* headNodeMergedList = nullptr;
    Node<int>* curNodeMergedList = nullptr;

    while (first && second)
    {
        // Node selection for the next node of the merged linked list.
        Node<int>* curNode = (second->data < first->data) ? second : first;

        if (curNodeMergedList)
        {
            curNodeMergedList->next = curNode;
        }
        curNodeMergedList = curNode;

        // Move the linked list node pointer forward whose node was selected for the merged linked list.
        if (curNode == first)
        {
            first = first->next;
        }
        else
        {
            second = second->next;
        }

        // Assign head of the merged list for the first time only.
        if (headNodeMergedList == nullptr)
        {
            headNodeMergedList = curNodeMergedList;
        }
    }

    // At this point, all the nodes of one of the two linked lists are already assigned to the merged linked list.
    // So assign rest of the nodes of the other linked list to the merged linked list.
    if (first)
    {
        if (curNodeMergedList)
        {
            curNodeMergedList->next = first;
        }
        else
        {
            // Case: second linked list is null
            headNodeMergedList = first;
        }
    }

    if (second)
    {
        if (curNodeMergedList)
        {
            curNodeMergedList->next = second;
        }
        else
        {
            // Case: first linked list is null
            headNodeMergedList = second;
        }
    }
    
    return headNodeMergedList;
}

template <typename T>
Node<T>* create_linked_list(vector<T> vec)
{
    if (vec.size() == 0)
    {
        return nullptr;
    }

    Node<T>* headNode = new Node<T>(vec[0]);
    Node<T>* prevNode =  headNode;

    for (typename vector<T>::iterator it=vec.begin()+1; it != vec.end(); ++it)
    {
        Node<T>* curNode = new Node<T>(*it);
        prevNode->next = curNode;
        // Assign prevNode to curNode before the next iteration
        prevNode = curNode;
    }

    return headNode;
}

template <typename T>
vector<T> create_vector(Node<T>* head)
{
    vector<T> vec;
    Node<T>* curNode = head;

    while (curNode)
    {
        vec.push_back(curNode->data);
        curNode = curNode->next;
    }
    
    return vec;
}

lest::test tests[] = {
    CASE("Test Case #1"){
        vector<int> vec1 = {1,5,8,10,11};
        vector<int> vec2 = {2,4,6,9};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {1,2,4,5,6,8,9,10,11};
        EXPECT(merged_linked_list_vec == expected_vec);
    },
    CASE("Test Case #2"){
        vector<int> vec1 = {1,5,8,10,11};
        vector<int> vec2 = {20,40,60,90};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {1,5,8,10,11,20,40,60,90};
        EXPECT(merged_linked_list_vec == expected_vec);
    },
    CASE("Test Case #3"){
        vector<int> vec1 = {20,40,60,90};
        vector<int> vec2 = {1,5,8,10,11};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {1,5,8,10,11,20,40,60,90};
        EXPECT(merged_linked_list_vec == expected_vec);
    },
    CASE("Test Case #4"){
        vector<int> vec1 = {};
        vector<int> vec2 = {1,5,8,10,11};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {1,5,8,10,11};
        EXPECT(merged_linked_list_vec == expected_vec);
    },
    CASE("Test Case #5"){
        vector<int> vec1 = {20,40,60,90};
        vector<int> vec2 = {};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {20,40,60,90};
        EXPECT(merged_linked_list_vec == expected_vec);
    },
    CASE("Test Case #6"){
        vector<int> vec1 = {};
        vector<int> vec2 = {};

        Node<int>* first = create_linked_list(vec1);
        Node<int>* second = create_linked_list(vec2);
        Node<int>* merged_linked_list = sortTwoLists(first, second);
        vector<int> merged_linked_list_vec = create_vector(merged_linked_list);
        vector<int> expected_vec = {};
        EXPECT(merged_linked_list_vec == expected_vec);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
