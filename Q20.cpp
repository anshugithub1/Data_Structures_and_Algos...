/*
Leetcode-->222. Count Complete Tree Nodes
Problem statement:
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
 
Test cases:

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.


*/


// Solution

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// -------------------------------------------------------------> complexity less than O(n*n) --- close to O(square of log(n))

class Solution {
private:
    int findLeft(TreeNode* node){
        int count = 0;
        while(node){
            count+=1;
            node = node->left;
        }
    return count;
    }
    int findRight(TreeNode* node){
        int count = 0;
        while(node){
            count+=1;
            node = node->right;
        }
    return count;
    }

public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int l = findLeft(root);
        int r  = findRight(root);

        if(l==r){
            return (1<<l)-1;
        }else{
         int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
        }
        
    }
};