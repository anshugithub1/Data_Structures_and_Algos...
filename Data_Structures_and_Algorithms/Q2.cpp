/*
Leetcode ---> 386. Lexicographical Numbers

Problem statement:

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

Test cases:

Example 1:
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:
Input: n = 2
Output: [1,2]


Constraints:

1 <= n <= 5 * 104


*/

// Solution

// Approach 1---> recursive DFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> ans;
    void solve(int i, int n){
        // base conditon - where recursion gets over
        if(i>n){
            return;
        }

        int cur = i; // 1 
        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            string tmp = to_string(cur) + to_string(i); // 1 0 
            solve(stoi(tmp),n);

            // int tmp = cur*10 +  i;
            // solve(tmp,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        for(int i=1;i<=9;i++){
            solve(i,n);
        }

        return ans;
    }
};


// Approach 2 ---> iteration based
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};
