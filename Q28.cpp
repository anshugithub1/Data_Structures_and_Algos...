/*
Leetcode-->198. House Robber
Problem Statement: 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

*/


// Solution

#include<bits/stdc++.h>
using namespace std;
//-------------------------------->> Approach:1 top-down (memoisation) <<------------------
class Solution {
private:
    int memoise[101];
    int solve(vector<int>& nums, int i , int n){
        if(i>=n){
            return 0;
        }
        if(memoise[i] != -1){
            return memoise[i];
        }
        int ifChoosen = nums[i] + solve(nums, i+2, n);
        int ifNotChoosen = solve(nums, i+1, n);
        memoise[i] = max(ifChoosen , ifNotChoosen);

        return memoise[i] ;
    }
public:
    int rob(vector<int>& nums) {
        int robbedMoney;
        int n = nums.size();
        memset(memoise,-1,sizeof(memoise));
        robbedMoney = solve(nums, 0, n);
        return robbedMoney;
        // return memoise[0]; 
    }
};

//-------------------------------->> Approach:2 bottom-up <<------------------

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];        
    }
};