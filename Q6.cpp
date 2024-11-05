/*
Leetcode--> 217. Contains Duplicate

Problem statement:

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


Test cases:

Example 1:

Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.


Example 2:

Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct.

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9


*/

// Solution

//------------------------------------------>>Approach-1: Bruteforce solution
#include<bits/stdc++.h>
using namespace std;

//brute force approach giving TLE O(n^2)

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] == nums[j])
//                     return true;
//             }
//         }
//         return false;
//     }
// };

//  ------------------------------------------>>Approach-2: first sort then check if two closer elements stay closer i.e if nums[i] == nums[i-1]

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

//------------------------------------------>>Approach-3: using freq map.. add elements to map and simultaneously check if it has frequenncy greater than 1 return true;

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int> seen;
//         for (int num : nums) {
//             if (seen[num] >= 1)
//                 return true;
//             seen[num]++;
//         }
//         return false;
//     }
// };

//  ------------------------------------------>>Approach-4: using set data-structure 
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> seen;
//         for (int num : nums) {
//             if (seen.count(num) > 0)
//                 return true;
//             seen.insert(num);
//         }
//         return false;
//     }
// };
//  ------------------------------------------>>Approach-5: using set data-structure in python if no. of elements in set and nums differ => there were duplicates

// class Solution:
//     def containsDuplicate(self, nums: List[int]) -> bool:
//         l = len(nums)
//         ns=set()
//         for i in nums:
//             ns.add(i)
        
//         if len(ns)!=l :
//             return True
//         else:
//             return False

// class Solution:
//     def containsDuplicate(self, nums: List[int]) -> bool:
//         if len(set(nums)) == len(nums):
//             return False
//         else:
//             return True
        
        
        
