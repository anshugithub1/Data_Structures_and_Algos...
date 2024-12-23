/*
Leetcode-->73. Set Matrix Zeroes

Problem statement:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Test cases:

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]




Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


 

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1


Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
*/


// Solution
#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b)  for(i = a ; i< b ; i++)

class Solution {
   
private: 
    void makeZero(vector<vector<int>>& matrix ,vector<pair<int,int>>& visit){
        int n  = matrix.size();
        int m =  matrix[0].size();
        auto i = 0;
        auto j = 0;
        for(auto coord : visit){
            i = coord.first;
            j = coord.second;
            int p = 0 ;
            int q = 0 ;
            f( p, 0 , m ){
                matrix[i][p]=0;
            }
            f( q, 0 , n ){
                matrix[q][j]=0;
            }
        } 
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m =  matrix[0].size();
        int i = 0 ; 
        int j = 0;
        vector<pair<int,int>> Tovisit;

        f( i , 0, n){
            f(j, 0 , m ){
                if(matrix[i][j] == 0){
                    Tovisit.push_back({i,j});
                }
            }
        }
       makeZero(matrix, Tovisit) ;
        
    }
};