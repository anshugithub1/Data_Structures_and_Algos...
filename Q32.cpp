/*
Leetcode-->134. Gas Station
Problem Statement:
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.


Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 10^5
0 <= gas[i], cost[i] <= 10^4

*/

//Solution 

// ----------------------------------------------->>Approach-1: Brute-Force TLE at Test case 34/39 <<------------------------------------
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         int i = 0;
//         int ans = -1;
//         int a = 0;
//         for(i = 0 ; i<n ; i++){
//             int sum = gas[i]-cost[i];  
//             for(a = (i+1)%n ; a!=i; a = (a+1)%n){
//                 if(sum<0){
//                     break;
//                 }else{
//                     sum+=gas[a] - cost[a];
//                 }
//             }
//             if(a==i && sum>=0){
//                 ans = a;
//                 return ans;
//             }
//         }
//     return ans;
//     }
// };


// ------------------------------------------------------------->>Approach-2: Greedy Approach <<------------------------------------

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int n = gas.size();

        // if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)){
        //     return -1;
        // }

        for(int i = 0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i]; 
        }

        if(totalGas<totalCost){
            return -1;
        }
   
        int currGas = 0;
        int ans=0;
        for(int i = 0; i<n; i++){
            currGas += gas[i]-cost[i];
            if(currGas<0){
                currGas = 0; 
                ans=i+1;
            }
        }
        return ans;
    }
};

