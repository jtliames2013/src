2. given a list of words, find whether a given target word exists. Should support “.” which matches any character. Follow up: support “*” which matchs 0 or more characters.

trie的搜索, 和leetcode 有些不同。
class Node {
Node getChildForLetter(letter)
Node[] getAllChildren();
bool isTerminal();
}

搜索返回所有符合wildcard的词

比如
add(“car”)
add(“caw”)
add(“cauw”)

search(“c*w”) should return “caw” and “cauw”.

* could be at any place in the input string.

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isWord;
	TrieNode():isWord(false) {}
};

class Trie {
public:
	Trie() {
		root=new TrieNode();
	}

	void addWord(string word) {
		TrieNode* n=root;
		for (int i=0; i<word.size(); i++) {
			if (n->children.find(word[i])==n->children.end()) {
				n->children[word[i]]=new TrieNode();
			}
			n=n->children[word[i]];
		}
		n->isWord=true;
	}

	bool search(string& word, TrieNode* n, int start){
		if (start==word.size()) {
			return n->isWord;
		}

		if (word[start]=='.') {
			for (auto iter:n->children) {
				if (search(word, iter.second, start+1)) return true;
			}
			return false;
		} else if (word[start]=='*') {
			if (search(word, n, start+1)) return true;
			for (auto iter:n->children) {
				if (search(word, iter.second, start)) return true;
			}
			return false;
		} else {
			if (n->children.find(word[start])==n->children.end()) return false;
			return search(word, n->children[word[start]], start+1);
		}
	}

	bool searchWord(string word) {
		return search(word, root, 0);
	}
private:
	TrieNode* root;
};

class Solution {
public:
	bool find(vector<string> words, string target) {
		Trie trie;
		for (auto w:words) trie.addWord(w);
		return trie.searchWord(target);
	}
};

int main()
{
	Solution s;
	vector<string> words={"car", "caw", "cauw"};
	cout << s.find(words, "c*w") << endl;
	cout << s.find(words, "c.w") << endl;
	cout << s.find(words, "a.w") << endl;
	return 0;
}

