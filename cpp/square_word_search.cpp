感觉square的面经不多，lz就贡献一个今早的面经。
给一个2D matrix，每个cell是一个letter，和一个contain words的dictionary。求matrix里所有dictionary里单词的location。
比如
g o d h
e  f c i
d a g g
t g g g

dic是 hi god cat
要能返回这几个单词的location 可以垂直 水平 也可以斜线
数据结构自己写

struct Position {
	int row;
	int col;
	Position(int r, int c):row(r),col(c) {}
};

struct TrieNode {
	bool isWord;
	map<char, TrieNode*> children;
	TrieNode(): isWord(false) {}
};

class Trie {
public:
	Trie() {
		root=new TrieNode();
	}

	void insert(string word) {
		TrieNode *n=root;
		int i;
		for (i=0; i<word.size(); i++) {
			auto iter=n->children.find(word[i]);
			if (iter==n->children.end()) break;
			n=iter->second;
		}

		for (; i<word.size(); i++) {
			TrieNode *curr=new TrieNode();
			n->children[word[i]]=curr;
			n=curr;
		}
		n->isWord=true;
	}

	void deleteWord(string word) {
		vector<TrieNode*> remove;
		remove.push_back(root);
		TrieNode *n=root;
		for (int i=0; i<word.size(); i++) {
			auto iter=n->children.find(word[i]);
			if (iter==n->children.end()) return;
			n=iter->second;
			remove.push_back(n);
		}

		if (n->children.size()!=0) {
			n->isWord=false;
		} else {
			for (int i=remove.size()-1; i>0; i--) {
				if (remove[i]->children.size()!=0) break;
				remove[i-1]->children.erase(word[i-1]);
				delete remove[i];
			}
		}
	}

	TrieNode *root;
};

class Solution {
public:
	void findWords(
			vector<vector<Position> >& res,
			Trie& prefixTree,
			TrieNode* node,
			vector<vector<char>>& board,
			vector<vector<bool> >& visited,
			vector<Position>& path,
			string& word,
			int row,
			int col,
			int m,
			int n) {
		auto iter=node->children.find(board[row][col]);
		if (iter==node->children.end()) return;

		path.push_back(Position(row,col));
		word.push_back(board[row][col]);
		visited[row][col]=true;
		if (iter->second->isWord) {
			res.push_back(path);
			// delete word here is problematic since when return to upper level, the node is deleted
			// either has a way to check node is deleted or delete when recusion is done.
		}

		int delta[8][2]={{-1,-1}, {-1,0}, {-1, 1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
		for (int k=0; k<8; k++) {
			int nr=row+delta[k][0];
			int nc=col+delta[k][1];
			if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
				findWords(res, prefixTree, iter->second, board, visited, path, word, nr, nc, m, n);
			}
		}

		visited[row][col]=false;
		word.erase(word.size()-1);
		path.pop_back();
	}
	vector<vector<Position> > findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<vector<Position> > res;
		int m=board.size();
		if (m==0) return res;
		int n=board[0].size();
		if (n==0) return res;
		Trie prefixTree;
		for (auto w:words) prefixTree.insert(w);
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		vector<Position> path;
		string word;

		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				findWords(res, prefixTree, prefixTree.root, board, visited, path, word, i, j, m, n);
				if (res.size()==words.size()) break;
			}
		}

		return res;
	}
};

int main() {
	vector<vector<char> > board = {{'g', 'o', 'd', 'h'},
								   {'e', 'f', 'c', 'i'},
								   {'d', 'a', 'g', 'g'},
								   {'t', 'g', 'g', 'g'}};
	vector<string> dict={"hi", "cat", "god"};
	Solution s;
	vector<vector<Position> > res=s.findWords(board, dict);
	return 0;
}

