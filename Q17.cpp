/*
Leetcode-->513. Find Bottom Left Tree Value
Problem statement:
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 
Test cases:

Example 1:

Input: root = [2,1,3]
Output: 1

Example 2:

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 
Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1


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
 // --------------------------------------------->> simple BFS traversal with a little tweak
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    
    int ans;
    q.push(root);

    while(!q.empty()){
        TreeNode* firstval = q.front();
        
        q.pop();

        ans = firstval->val;
// instead of pushing the left child to queue first , here we are pushing the right child first then left child after it.
        if(firstval->right) {
            q.push(firstval->right );
            }

        if(firstval->left) {
            q.push(firstval->left) ;
            }
        }
    return ans;
    }
};

// ------------------------------------------>> level by level traversal of binary tree... a different approach


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        TreeNode* LeftmostNodeAtAnyLevel;
        while(!que.empty()){
            int n = que.size(); // at the moment all the elements at a particular level are in the queue .

            LeftmostNodeAtAnyLevel = que.front();

// poping out all the elements of particular level and pushing their childrens into the queue --> in one go..
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }

        }
    return LeftmostNodeAtAnyLevel->val;
    }
};