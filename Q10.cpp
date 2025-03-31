/*
Leetcode-->215. Kth Largest Element in an Array

Problem statement:
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?


Test cases:

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5



Example 2:


Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


 

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4


*/


// Solution
#include<bits/stdc++.h>
using namespace std;

//------------------------------------------>>Approach-1: Bruteforce type solution
// sorting also it is mentioned to avoid it.
// ............Run time - error........

//------------------------------------------>>Approach-2: priority Queue (a)
class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        int ans;
        priority_queue<int>maxHeap;
        for(int i = 0; i<n ; i++){
            maxHeap.emplace(nums[i]);
        }
        for(int i = 0 ; i<k-1 ; i++){
            maxHeap.pop();
        }
        return maxHeap.top();



    }
};

//------------------------------------------>>Approach-3: priority Queue - optimised (b)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};
