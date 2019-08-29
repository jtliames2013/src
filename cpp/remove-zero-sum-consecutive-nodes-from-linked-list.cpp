1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium

80

12

Favorite

Share
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0), *curr=&dummy;
        dummy.next=head;
        unordered_map<int, ListNode*> mp;
        int prefix=0;
        while (curr) {
            prefix+=curr->val;
            if (mp.find(prefix)!=mp.end()) {
                ListNode* n=mp[prefix]->next;
                int p=prefix+n->val;
                while (n!=curr) {
                    mp.erase(p);
                    n=n->next;
                    p+=n->val;
                }
                
                mp[prefix]->next=curr->next;
            } else {
                mp[prefix]=curr;    
            }
            
            curr=curr->next;
        }
        
        return dummy.next;
    }
};
