/*
Leetcode-->102. Binary Tree Level Order Traversal
Problem statement:
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Test cases:

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

 
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

// --------------------------------- Approach 1 : BFS (level BY level)  ---------------------------------------

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>ans;

            if(!root){
                return ans;
            }
            queue<TreeNode*>q;
            q.push(root);

            while(!q.empty()){
                int n  =  q.size();
                vector<int>v;
                while(n){
                    TreeNode* node = q.front();
                    v.push_back(node->val);
                    q.pop();

                    /*
                    if(node && node->left){
                        q.push(node->left);
                    }
                    if(node && node->right){
                        q.push(node->right);
                    }
                    */

// NOTE : calculating every time whether my node is null or not was compromising my time complexity... without failing to any test case.

                    if(node && node->left){
                        q.push(node->left);
                    }
                    if(node && node->right){
                        q.push(node->right);
                    }
                    n--;

                }
                ans.push_back(v);
            }
    return ans;
    }
};





