/*
Leetcode-->3133. Minimum Array End

Problem statement:
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].


Test cases:

Example 1:

Input: n = 3, x = 4
Output: 6

Explanation:
nums can be [4,5,6] and its last element is 6.


Example 2:


Input: n = 2, x = 7
Output: 15

Explanation:
nums can be [7,15] and its last element is 15.

 

Constraints:
1 <= n, x <= 108


*/


// Solution
#include<bits/stdc++.h>
using namespace std;

//------------------------------------------>>Approach-1: Bruteforce type solution
// ............Run time - error........

//------------------------------------------>>Approach-2: BIT-MANIPULATION  (a)
class Solution {
public:
    long long minEnd(int n, int x) {
// according to question search space is 0 to n-1 , where n-1 is unknown. optimal solution --> would be that reducing this search space and perform optimal searching in the reduced search space. 
        long long num = x;
// note that the first x would itself be the first num of the answer array, rest other numbers would be definetly greater than prev. num , doing OR operation lets reach the next num faster,(only thing we have to do is to keep the set bits of x intact in further numbers)
        for(int i = 0 ;  i<n-1; i++){
            num = (num+1)|x ; 
        }
// since we are updating the number also, the last number woud be the minimum possible value but maximum value in array (strictly increasing). 
        return num ;    
    }
};

//------------------------------------------>>Approach-3: BIT-MANIPULATION (b)
class Solution {
public:
    long long minEnd(int n, int x) {
        vector<short> shifts;
        long long cur = x;
        long long calc = n - 1;
 // Step-1:  
        for(int i = 0; i < 32; i++) //find bit positions in x which are 0
            if(!((1 << i) & x))
                shifts.push_back(i);
        for(int i = 32; i < 64; i++)
            shifts.push_back(i);

        // for(auto x: shifts) cout<<x<<' ';

// Step-2:

        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1) << shifts[i];
        }
        return cur;

    }
};

//------------------------------------------>>Approach-3: BIT-MANIPULATION (c)

#define ll long long

class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = 0, bit;
        // Reducing n by 1 to exclude x from the iteration
        --n;

        // Step 1: Initialize vectors to hold the binary representation of x and
        // n-1
        vector<int> binaryX(64, 0);  // Binary representation of x
        vector<int> binaryN(64, 0);  // Binary representation of n-1

        ll longX = x;  // Convert x to long long for 64-bit manipulation
        ll longN = n;  // Convert n-1 to long long for 64-bit manipulation

        // Step 2: Build binary representations of x and n-1
        for (int i = 0; i < 64; ++i) {
            bit = (longX >> i) & 1;  // Extract i-th bit of x
            binaryX[i] = bit;

            bit = (longN >> i) & 1;  // Extract i-th bit of n-1
            binaryN[i] = bit;
        }

        int posX = 0, posN = 0;

        // Step 3: Combine binary representation of x and n-1
        while (posX < 63) {
            // Traverse binaryX until we find a 0 bit
            while (binaryX[posX] != 0 && posX < 63) {
                ++posX;
            }
            // Copy bits from binaryN (n-1) into binaryX (x) starting from the
            // first 0
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }

        // Step 4: Rebuild the final result from the combined binary
        // representation
        for (int i = 0; i < 64; ++i) {
            if (binaryX[i] == 1) {
                // convert binary bit to decimal value
                result += pow(2, i);
            }
        }

        return result;
    }
};


