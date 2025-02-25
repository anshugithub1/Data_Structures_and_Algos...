/*
Leetcode-->162. Find Peak Element
Problem statement:
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Test cases:

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
Constraints:
1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
nums[i] != nums[i + 1] for all valid i.

*/


// Solution

#include<bits/stdc++.h>
using namespace std;

//------------------------------------------>>Approach-1:  Using STL method direct solution -- O(N)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1){
            return 0;
        }else {
            return max_element(nums.begin(),nums.end())-nums.begin();
            // max_element() takes linear time complexity with one less than the number of elements compared
        }
    }
};

//------------------------------------------>>Approach-1:  Writing Binary solution -- O(logN)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int  n = nums.size();
        int l  = 0;
        int r  =  n-1;
    
        while( l<r ){  
            int mid  =  l + (r-l)/2 ;
            // NOTE - if you will swap the order of the if - else if conditions you may get Runtime error.
            if(nums[mid]>nums[mid+1] ){
                r = mid;
            }
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else{
                l = mid+1; // if here you will do  l = mid  --> TLE
            }
        }
// NOTE -  here we are returning Left   
    return l;
    }
};