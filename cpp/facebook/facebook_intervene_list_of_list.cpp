intervene list of lists ([[1,2,3], [4,5], [6,7,8,9]] => [1,4,6,2,5,7,3,8,9]) follow up: 能否in-place.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* merge(vector<ListNode*> lists) {
		ListNode dummy(0);
		ListNode* tail=&dummy;
		int n=lists.size();
		while (1) {
			int empty=0;
			for (int i=0; i<n; i++) {
				if (lists[i]==NULL) empty++;
				else {
					tail->next=lists[i];
					tail=lists[i];
					lists[i]=lists[i]->next;
				}
			}
			if (empty==n) break;
		}

		return dummy.next;
	}
};

