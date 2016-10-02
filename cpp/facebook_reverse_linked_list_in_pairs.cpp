struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseInPairs(ListNode* head) {
		ListNode *prev=NULL, *curr=head, *next=NULL, *nextnext=NULL;
		ListNode *newHead=head;
		while (curr!=NULL) {
			next=curr->next;
			nextnext=next!=NULL?next->next:NULL;
			if (next!=NULL) {
				if (prev!=NULL) {
					prev->next=next;
				} else {
					newHead=next;
				}
				next->next=curr;
				curr->next=nextnext;
			}
			prev=curr;
			curr=nextnext;
		}

		return newHead;
	}
};

void print(ListNode *head) {
	while (head!=NULL) {
		cout << head->val << " ";
		head=head->next;
	}
	cout << endl;
}

int main()
{
	Solution s;
	ListNode *prev=NULL, *head=NULL;
	for (int i=0; i<9; i++) {
		ListNode* n=new ListNode(i);
		if (i==0) head=n;
		if (prev!=NULL) prev->next=n;
		prev=n;
	}

	ListNode* newHead=s.reverseInPairs(head);
	print(newHead);

	return 0;
}

