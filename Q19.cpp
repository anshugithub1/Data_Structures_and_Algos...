/*
Leetcode-->167. Two Sum II - Input Array Is Sorted
Problem statement:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
A leaf is a node with no children.
 
Test cases:

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.


*/


// Solution

#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------> Approach 1: Using two pointers , start and end pointer. 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int  i  = 0 ;
        int  j =  numbers.size() - 1;
        vector<int>ans;
// i be the first pointer and j be the last pointer.
// utilising the power of sorted array ... if the sum > target then move the end j -pointer backward ... if the sum < target then move the i-pointer forward.
        while(i<j){
            if((numbers[i]+numbers[j])<target){
                i++;
            }else if((numbers[i]+numbers[j])>target){
                j--;
            }else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }

        }

        return ans;
    }
};



// ----------------------------------------> Approach 2: Brute - Force type --- gave TLE at 23/24. 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2 , 0);
        int n = numbers.size();

        for(int i = 0; i< n ; i++){
            int val = target - numbers[i];
            ans[0] = i+1;
            for(int j = i+1 ; j < n ; j++){
                if (val == numbers[j]){
                    ans[1] = j+1;
                    return ans;
                }
                if(val < numbers[j]){
                    break;
                } 
            }
        }
        return ans;
    }
};