/*
Leetcode-->1829. Maximum XOR for Each Query

Problem statement:
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.


Test cases:

Example 1:

Input: nums = [0,1,1,3], maximumBit = 2
Output: [0,3,2,3]

Explanation: The queries are answered as follows:
1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4th query: nums = [0], k = 3 since 0 XOR 3 = 3.


Example 2:

Input: nums = [2,3,4,7], maximumBit = 3
Output: [5,2,6,5]

Explanation: The queries are answered as follows:
1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4th query: nums = [2], k = 5 since 2 XOR 5 = 7.

Example 3:

Input: nums = [0,1,2,2,5,7], maximumBit = 3
Output: [4,3,6,4,6,7]


Constraints:

nums.length == n
1 <= n <= 10^5
1 <= maximumBit <= 20
0 <= nums[i] < 2^maximumBit
nums​​​ is sorted in ascending order.


*/


// Solution
#include<bits/stdc++.h>
using namespace std;

//------------------------------------------>>Approach-1: Bruteforce type solution
// ............Run time - error........

//------------------------------------------>>Approach-2: solution by xor properties 
// O(n) -TIME COMPLEXITY
// O(1) - SPACE COMPLEXITY but O(n) if we consider the complexity of the answer vector
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

    vector<int> ans;
// doing xor even no. of times with the same number cancels out the number
// bit masking 2^n-1 i.e. (1<<n)-1 => mask of n digits i.e. for observing the value of n-bits only.
// if we will directly flip the bits we can get the number of 32 bit or 64 bit as per the bit size of number to reduce it back to bit size of our desired no. we will be using the bit masking;
        int n = nums.size();
        int xorv = 0; // not initialising xorv with zero was giving wrong ans for some test cases
    for(int i =0; i<n; i++){
            xorv^=nums[i];
        }

    int mask = ((1<<maximumBit)-1);

    for(int i =0; i<n ; i++){
        int k = ~xorv & mask;
        ans.push_back(k);
        xorv = xorv ^ nums[n-i-1];
    }
        return ans;
    }
};