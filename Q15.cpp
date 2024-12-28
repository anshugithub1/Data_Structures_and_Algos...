/*
Leetcode-->876. Middle of the Linked List
Problem statement:
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Test cases:

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/


// Solution

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// ------------------------------------------->> Approach 1 : Using the approach of slow and fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow  = head ; 
        ListNode* fast  = head ;
// slow moving one step and fast moving 2 steps --> slow and fast pointer
        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast  = fast -> next -> next;
        }
        return slow;
    }
};