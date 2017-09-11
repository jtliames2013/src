Remove duplicates from an unsorted linked list

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *l1=head;
		while (l1) {
			ListNode *l2=l1;
			while (l2->next) {
				if (l1->val==l2->next->val) {
					ListNode *tmp=l2->next;
					l2->next=l2->next->next;
					delete tmp;
				} else {
					l2=l2->next;
				}
			}
			l1=l1->next;
		}
		return head;
	}
};

