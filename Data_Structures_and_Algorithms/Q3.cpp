/*
Leetcode--> 202. Happy Number

Problem statement:

Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.


Test cases:

Example 1:
Input: n = 19
Output: true

Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

Constraints:

1 <= n <= 2^31 - 1


*/

// Solution

//------------------------------------------>>Approach-1: recursive solution
// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_set<int> visit;
        
//         while (visit.find(n) == visit.end()) {
//             visit.insert(n);
//             n = getNextNumber(n);
//             if (n == 1) {
//                 return true;
//             }
//         }
        
//         return false;
//     }

// private:
//     int getNextNumber(int n) {
//         int output = 0;
        
//         while (n > 0) {
//             int digit = n % 10;
//             output += digit * digit;
//             n = n / 10;
//         }
        
//         return output;
//     }
// };

//------------------------------------------>>Approach-2: slow and fast pointer

// class Solution {
// public:
//     bool isHappy(int n) {
//         int slow = getNextNumber(n);
//         int fast = getNextNumber(getNextNumber(n));

//         while (slow != fast) {
//             if (fast == 1) return true;
//             slow = getNextNumber(slow);
//             fast = getNextNumber(getNextNumber(fast));
//         }

//         return slow == 1;
//     }

// private:
//     int getNextNumber(int n) {
//         int output = 0;
        
//         while (n > 0) {
//             int digit = n % 10;
//             output += digit * digit;
//             n = n / 10;
//         }
        
//         return output;
//     }
// };

//------------------------------------------>>Approach-3: Mathematical intution solution

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        if(n == 0) return false;
        if(n == 9 || n == 3 || n == 2 || n == 4) return false;
        else{
            int sm = 0;
            while(n){
                int d = n%10;
                sm+=(d*d);
                n/=10;
            }
            return isHappy(sm);
        }
    }
};