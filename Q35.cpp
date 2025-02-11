/*
Leetcode-->1726. Tuple with Same Product
Problem Statement: 
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 
Example 1:
Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

Example 2:
Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 10^4
All elements in nums are distinct.


*/

// Solution

// ----------------------------------------------->> Approach-1: using the pair-wise products <<------------------ 
class Solution {
private:
    int nc2(int n){
        return n*(n-1)/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        unordered_map<int,int>productFreq;
        for(int i = 0; i+1<n; i++){
            for(int j = i+1; j<n;j++){
                productFreq[nums[i]*nums[j]]++;
            }
        }

        for(auto val:productFreq){
            if(val.second>=2){
                ans += 8*nc2(val.second);
            }
        }

        return ans;
        
    }
};

// ------------------------------------------------>> Same Approach with concised code <<-------------------------
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0, N = nums.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                ans += (++m[nums[i] * nums[j]] - 1) * 8;
            }
        }
        return ans;
    }
};