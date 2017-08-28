第二道题是 给个Tree 不一定是平衡的， 要求 把所有路径排序后  按字符串那样的比较大小方法 找出最小的路径  时间要求线性的。 比如  
          5
       /     \
    10      3
   /   \   /
1    7  8. 
路径有  5 10 1 ； 5 10 7 ； 5 3 8. 
排序后  1 5 10 ； 5 7 10 ； 3 5 8
所以按字符串类型排序 为  1 5 10 < 3 5 8 < 5 7 10；

class Solution {
public:
	vector<int> smallestPath(TreeNode* root) {
		vector<int> res;
		multiset<int> st=smallest(root);
		for (auto i:st) res.push_back(i);
		return res;
	}

	multiset<int> smallest(TreeNode* root) {
		multiset<int> res;
		if (root==NULL) return res;
		multiset<int> l=smallest(root->left);
		l.insert(root->val);
		multiset<int> r=smallest(root->right);
		r.insert(root->val);
		if (compare(l, r)<0) return l;
		else return r;
	}

	int compare(multiset<int>& l, multiset<int>& r) {
		auto iterl=l.begin(), iterr=r.begin();
		while (iterl!=l.end() && iterr!=r.end()) {
			if (*iterl<*iterr) return -1;
			else if (*iterl>*iterr) return 1;
			else {
				iterl++;
				iterr++;
			}
		}
		if (iterl==l.end() && iterr==r.end()) return 0;
		else if (iterl==l.end()) return -1;
		else return 1;
	}
};

