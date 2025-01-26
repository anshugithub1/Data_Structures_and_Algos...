/*
Leetcode-->373. Find K Pairs with Smallest Sums
Problem Statement : 
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 10^4
k <= nums1.length * nums2.length

*/


// Solution

#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------->> Appraoch 1 : Min heap --> BFS in tree kinda!! algorithm --> till the priority queue is not empty --------  

class Solution {
public:
    typedef pair<int,pair<int,int>> P ;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> myPairs ; 
        priority_queue<P, vector<P>, greater<P>>pq;
        set<pair<int,int>>st;
        pq.push({nums1[0]+nums2[0],{0,0}});

        while(k-- && !pq.empty()){

            auto temp = pq.top();
            pq.pop();

            int i  = temp.second.first;
            int j = temp.second.second;

            myPairs.push_back({nums1[i],nums2[j]});

            if(i+1<nums1.size() && st.find({i+1,j}) == st.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }

            if(j+1<nums2.size() && st.find({i,j+1}) == st.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }

        }
    return myPairs;
    }
};