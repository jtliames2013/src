implement skiplist
ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf

struct SkipNode {
	int val;
	vector<SkipNode*> next;
	SkipNode(int v, int level): val(v), next(level, nullptr) { }
};

class SkipList {
public:
	SkipList(): probability(0.5), maxLevel(16) {
		head=new SkipNode(INT_MIN, maxLevel);
		tail=new SkipNode(INT_MAX, maxLevel);

		fill(head->next.begin(), head->next.end(), tail);
	}

	~SkipList() {
		auto n=head;
		while (n->next[0]) {
			auto prev=n;
			n=n->next[0];
			delete prev;
		}
		delete n;
	}

	int randomLevel() {
		int l=1;
		while ((rand()%100)<100*probability && l<maxLevel) l++;
		return l;
	}

	int nodeLevel(SkipNode* v) {
		return v->next.size();
	}

	void print() {
		SkipNode *n=head->next[0];
		while (n!=tail) {
			cout << "(" << n->val << "," << nodeLevel(n) << ")" ;
			n=n->next[0];
			cout << " ";
		}
		cout << endl;
	}

	SkipNode* lower_bound(int value) {
		auto n=head;
		for (int i=nodeLevel(head)-1; i>=0; i--) {
			while (n->next[i]->val<value) n=n->next[i];
		}
		return n->next[0];
	}

	vector<SkipNode*> predecessors(int value) {
		vector<SkipNode*> res(nodeLevel(head), nullptr);
		auto n=head;
		for (int i=nodeLevel(head)-1; i>=0; i--) {
			while (n->next[i]->val<value) n=n->next[i];
			res[i]=n;
		}

		return res;
	}

	bool find(int value) {
		SkipNode *n=lower_bound(value);
		if (n->val==value) return true;
		else return false;
	}

	void insert(int value) {
		auto pred=predecessors(value);
		if (pred[0]->next[0]->val==value) return;

		int newLevel=randomLevel();
		SkipNode *n=new SkipNode(value, newLevel);
		for (int i=0; i<newLevel; i++) {
			n->next[i]=pred[i]->next[i];
			pred[i]->next[i]=n;
		}
	}

	void erase(int value) {
		auto pred=predecessors(value);
		auto n=pred[0]->next[0];
		if (n->val!=value) return;

		for (size_t i=0; i<nodeLevel(n); i++) {
			pred[i]->next[i]=n->next[i];
		}
		delete n;
	}
private:
	float probability;
	int maxLevel;
	SkipNode *head;
	SkipNode *tail;
};

int main() {
	SkipList s;
	for (int i=0; i<20; i+=2) s.insert(i);

	s.print();

	if (s.find(6)) cout << "found!" << endl;
	else cout << "NOT found!" << endl;

	s.insert(7);
	s.print();

	s.erase(10);
	s.print();

	return 0;
}

