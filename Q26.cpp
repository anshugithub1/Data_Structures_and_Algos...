/*
Leetcode-->77. Combinations
Problem Statement:
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:
1 <= n <= 20
1 <= k <= n
 
*/


// Solution

#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------->> Approach : 1 --> Backtracking ------------------------------>> 
class Solution {
    vector<vector<int>> ans;
private:
    void combination(int i , int& n, vector<int>& temp , int k){
        if(temp.size() >= k){
            ans.push_back(temp);
            return;
        }

        for(int a = i ; a<=n ; a++){
            temp.push_back(a);
            combination(a+1 ,n, temp , k);
            temp.pop_back();
        }
        
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        combination( 1, n, temp , k );
        return ans;
        
    }
};