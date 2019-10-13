109. Convert Sorted List to Binary Search Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 76583 Total Submissions: 244580 Difficulty: Medium
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Company Tags Zenefits
Hide Tags Depth-first Search Linked List
Hide Similar Problems (M) Convert Sorted Array to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *one=head, *two=head, *prev=NULL;
        while (two && two->next) {
            prev=one;
            one=one->next;
            two=two->next->next;
        }
        if (prev) prev->next=NULL;
        TreeNode *n=new TreeNode(one->val);
        n->left=sortedListToBST(prev==NULL?NULL:head);
        n->right=sortedListToBST(one->next);
        
        return n;
    }
};

