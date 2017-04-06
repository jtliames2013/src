23. Merge k Sorted Lists Add to List
DescriptionSubmissionsSolutions
Total Accepted: 138657
Total Submissions: 522055
Difficulty: Hard
Contributor: LeetCode
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Subscribe to see which companies asked this question.

Hide Tags Divide and Conquer Linked List Heap
Hide Similar Problems (E) Merge Two Sorted Lists (M) Ugly Number II

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
    class Compare {
    public:
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail=&dummy;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto l:lists) {
            if (l) pq.push(l);
        }
        while (!pq.empty()) {
            ListNode* t=pq.top();
            pq.pop();
            tail->next=t;
            tail=t;
            if (t->next) pq.push(t->next);
        }
        
        return dummy.next;
    }
};

