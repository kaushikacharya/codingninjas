/*  Problem: Kth Smallest Element
    URL: https://www.codingninjas.com/codestudio/problems/kth-smallest-element_893056
    Date: 06th June 2023
    Approach: Use max heap with at most k elements.
                 Iterate over the input array and ensure that at any point of time the heap
                  contains the smallest k elements of the traversed input array.

    Complexity:
        Time: O(n log k)
        Space: O(k)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

int kthSmallest(vector<int> input, int k)
{
    priority_queue<int> pq;

    for (vector<int>::iterator it=input.begin(); it != input.end(); ++it)
    {
        if (pq.size() < k)
        {
            // Push the 1st k elements of the input array into the max heap without any constraints.
            pq.push(*it);
        }
        else
        {
            // As we need the kth smallest element, we can keep only k elememts in the heap.
            int top_element = pq.top();

            if (*it < top_element)
            {
                // As we have found an element smaller than the current max element of the heap, 
                // we will remove the max element from the heap and insert the current element of the input array.
                pq.pop();
                pq.push(*it);
            }
        }
    }

    int output = pq.top();

    return output;
}

lest::test tests[] = {
    CASE("Test Case #1"){
        vector<int> vec = {1,2,3,4,5,6};
        int k = 3;
        EXPECT(kthSmallest(vec,k) == 3);
    },
    CASE("Test Case #2"){
        vector<int> vec = {1,3,8,6,2};
        int k = 4;
        EXPECT(kthSmallest(vec,k) == 6);
    },
    CASE("Test Case #3"){
        vector<int> vec = {5};
        int k = 1;
        EXPECT(kthSmallest(vec,k) == 5);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
