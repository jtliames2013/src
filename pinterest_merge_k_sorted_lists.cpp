23. Merge k Sorted Lists 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution {
public:
	class Compare {
	public:
		bool operator()(ListNode *n1, ListNode *n2) {
			return n1->val>n2->val;
		}
	};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<ListNode*, vector<ListNode*>,  Compare> pq;
    	ListNode *head=NULL,*tail=NULL;
    	for (int i=0; i<lists.size(); i++) {
    		if (lists[i]!=NULL) pq.push(lists[i]);
    	}

    	while (!pq.empty()) {
    		ListNode* t=pq.top();
    		if (head==NULL) {
    			head=tail=t;
    		} else {
    			tail->next=t;
    			tail=t;
    		}

    		if (t->next!=NULL) {
    			pq.push(t->next);
    		}
    		pq.pop();
    	}

    	return head;
    }
};

class PriorityQueue {
public:
	void heapify(int i) {
		int l=2*i;
		int r=2*i+1;
		int largest;
		if (l<=data.size() && data[l-1]>data[i-1]) {
			largest=l;
		} else {
			largest=i;
		}
		if (r<=data.size() && data[r-1]>data[largest-1]) {
			largest=r;
		}

		if (largest!=i) {
			swap(data[i-1], data[largest-1]);
			heapify(largest);
		}
	}

	void push(int val) {
		data.push_back(val);
		int i=data.size();
		while (i>1 && data[i/2-1]<val) {
			data[i-1]=data[i/2-1];
			i=i/2;
		}
		data[i-1]=val;
	}

	int pop() {
		if (!data.empty()) {
			int res=data[0];
			swap(data[0], data[data.size()-1]);
			data.pop_back();
			heapify(1);
			return res;
		} else {
			return -1;
		}
	}

	void print() {
		for (int i=0; i<data.size(); i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
private:
	vector<int> data;
};

int main() {
	PriorityQueue pq;
	for (int i=1; i<=10; i++) {
		pq.push(i);
		pq.print();
	}
	pq.pop();
	pq.print();
	pq.pop();
	pq.print();

	return 0;
}

