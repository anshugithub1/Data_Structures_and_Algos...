/*
Leetcode-->124. Binary Tree Maximum Path Sum
Problem statement:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Test cases:

Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.



Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.


 

Constraints:
The number of nodes in the tree is in the range [1, 3 * 10^4].
-1000 <= Node.val <= 1000

*/


// Solution

#include<bits/stdc++.h>
using namespace std;
/*
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
*/




class Solution {

private:
int maxPathSum(TreeNode* node , int& max_val){
    if(!node){
        return 0 ;
    }
    int max_path_value_at_left = maxPathSum (node->left , max_val);
    int max_path_value_at_right = maxPathSum ( node ->right , max_val);

    int max_value_of_node = max_path_value_at_left + max_path_value_at_right + node->val;

    max_val = max( max_val, max_value_of_node);

    return max( 0 , max(max_path_value_at_left + node->val , max_path_value_at_right + node->val));
}
// NOTE : Consider the edge case of a node being negative or a maximum path sum at a node is -ve --> now adding
public:
    int maxPathSum(TreeNode* root) {
        int ans  =  INT_MIN ;
        maxPathSum(root , ans);

        return ans;
    }
};