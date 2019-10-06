382. Linked List Random Node  QuestionEditorial Solution  My Submissions
Total Accepted: 7180 Total Submissions: 15785 Difficulty: Medium
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
Subscribe to see which companies asked this question

Hide Tags Reservoir Sampling

https://en.wikipedia.org/wiki/Reservoir_sampling
Keep the first item in memory.
When the i-th item arrives (for i>1):
with probability 1/i, keep the new item (discard the old one)
with probability 1-1/i, keep the old item (ignore the new one)
So:

when there is only one item, it is kept with probability 1;
when there are 2 items, each of them is kept with probability 1/2;
when there are 3 items, the third item is kept with probability 1/3, and each of the previous 2 items are also kept with probability (1/2)(1-1/3) = (1/2)(2/3) = 1/3;
by induction, it is easy to prove that when there are n items, each item is kept with probability 1/n.

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count=0, res=0;
        ListNode *curr=head;
        while (curr) {
            count++;
            if (rand()%count==0) res=curr->val;
            curr=curr->next;
        }
        return res;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

