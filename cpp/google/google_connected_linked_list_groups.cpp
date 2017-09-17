有一个无限长的double linked list，和一个pointer array，每个pointer指向list中的一个node，求有多少个不相连的node group。

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v), next(NULL) {}
};

class Solution {
public:
	ListNode* find(vector<ListNode*>& parent, ListNode *n) {
		while (parent[n]!=n) n=parent[n];
		return n;
	}

	int numberOfConnectedGroups(vector<ListNode*> nodes) {
		int n=nodes.size();
		vector<ListNode*> parent(n);
		unordered_map<ListNode*, unordered_set<ListNode*>> mp;
		for (int i=0; i<n; i++) {
			mp[nodes[i]];
			parent[i]=nodes[i];
		}
		for (int i=0; i<n; i++) {
			if (mp.find(nodes[i]->next)!=mp.end()) {
				mp[nodes[i]].insert(nodes[i]->next);
				mp[nodes[i]->next].insert(nodes[i]);
			}
		}

		int res=n;
		for (int i=0; i<n; i++) {
			for (auto neighbor:mp[nodes[i]]) {
				ListNode* p1=find(parent, nodes[i]);
				ListNode* p2=find(parent, neighbor);
				if (p1!=p2) {
					parent[p2]=p1;
					res--;
				}
			}
		}

		return res;
	}
};

