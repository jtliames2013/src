第一轮：word search, 给一个target string和一个list string dictionary，求dictionary中的单词，该单词是target string的substring。有可能target string会非常长。

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isWord;
	TrieNode():isWord(false) {}
};

class Trie {
public:
	Trie() { root=new TrieNode(); }
	void insert(string word) {
		TrieNode* n=root;
		for (int i=0; i<word.size(); i++) {
			if (n->children.find(word[i])==n->children.end()) {
				n->children[word[i]]=new TrieNode();
			}
			n=n->children[word[i]];
		}
		n->isWord=true;
	}

	void remove(string word) {
		TrieNode* n=root;
		vector<TrieNode*> toRemove;
		toRemove.push_back(n);
		for (int i=0; i<word.size(); i++) {
			if (n->children.find(word[i])==n->children.end()) return;
			n=n->children[word[i]];
			toRemove.push_back(n);
		}

		if (n->children.size()>0) n->isWord=false;
		else {
			for (int i=toRemove.size()-1; i>0; i--) {
				if (toRemove[i]->children.size()>0) break;
				toRemove[i-1]->children.erase(word[i-1]);
				delete toRemove[i];
			}
		}
	}

	TrieNode* root;
};

class Solution {
	void findSubstr(vector<string>& res, string& target, int start, TrieNode* root) {
		TrieNode* n=root;
		for (int i=start; i<target.size(); i++) {
			if (n->isWord) res.push_back(target.substr(start, i-start+1));
			if (n->children.find(target[i])==n->children.end()) return;
			n=n->children[target[i]];
		}
	}

	unordered_set<string> findSubstr(string target, vector<string> words) {
		for (auto& w:words) trie.insert(w);
		unordered_set<string> res;
		int n=target.size();
		for (int i=0; i<n; i++) {
			vector<string> v;
			findSubstr(v, target, i, trie.root);
			for (auto s:v) {
				res.insert(s);
				trie.remove(s);
			}

		}

		return res;
	}
private:
	Trie trie;
};

