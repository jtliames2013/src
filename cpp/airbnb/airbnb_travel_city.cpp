john’s travel city: a1 a2 c2 h8 j9
tom’s travel city: b1 a1 c3 z5
kate travel city: a2 a1 h8 x8

给你一个人john, 以及他的一堆朋友，让你计算出来和他travel的city相似度大于75%的所有朋友，并且根据这个相似度对朋友排序

k-edit distance

struct TrieNode {
	bool isList;
	map<string, TrieNode*> children;
	TrieNode():isList(false) {}
};

class Trie {
public:
	Trie() {
		root= new TrieNode();
	}

	void insert(vector<string> travellist) {
		TrieNode *n=root;
		int i;
		for (i=0; i<travellist.size(); i++) {
			auto iter=n->children.find(travellist[i]);
			if (iter==n->children.end()) break;
			n=iter->second;
		}

		for (; i<travellist.size(); i++) {
			TrieNode *curr=new TrieNode();
			n->children[travellist[i]]=curr;
			n=curr;
		}

		n->isList=true;
	}

	TrieNode *root;
};

struct Score{
	vector<string> travel;
	int dist;
	Score(vector<string> t, int d):travel(t),dist(d) {}
};

class Solution {
public:
	void getScore(vector<Score>& res, TrieNode* node, vector<string>& person, vector<int> dp, vector<string>& travel) {
		int n=person.size();
		vector<int> newdp(n+1, 0);

		for (auto child:node->children) {
			travel.push_back(child.first);
			newdp[0]=travel.size();
			for (int i=1; i<=n; i++) {
				int delta=(child.first==person[i-1])?0:1;
				newdp[i]=min(min(dp[i], newdp[i-1])+1, dp[i-1]+delta);
			}

			if (child.second->isList) {
				res.push_back(Score(travel, newdp[n]));
			}
			getScore(res, child.second, person, newdp, travel);

			travel.pop_back();
		}
	}

	  vector<Score> getSimilarity(vector<vector<string>>& friends, vector<string> person) {
		  vector<Score> res;
		  Trie prefixTree;
		  for (auto f:friends) prefixTree.insert(f);
		  int n=person.size();
		  vector<int> dp(n+1, 0);
		  for (int i=1; i<=n; i++) dp[i]=i;
		  vector<string> travel;
		  getScore(res, prefixTree.root, person, dp, travel);

		  return res;
	  }
  };

class Compare {
public:
	bool operator()(string s1, string s2) {
		return s1.compare(s2)<0;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> friends={{"b1", "a1", "c3", "z5"}, {"c2", "a1", "h8", "x8"}};
	vector<string> person={"z1", "a1", "c2", "h8", "j9"};
	Compare comp;
	for (int i=0; i<friends.size(); i++) {
		sort(friends[i].begin(), friends[i].end(), comp);
	}
	sort(person.begin(), person.end(), comp);
	vector<Score> res=s.getSimilarity(friends, person);
	for (int i=0; i<res.size(); i++) {
		cout << res[i].dist <<  " " << endl;
		for (int j=0; j<res[i].travel.size(); j++) {
			cout << res[i].travel[j] << " ";
		}
		cout << endl;
	}
  	return 0;
}


