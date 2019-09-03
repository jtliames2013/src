212. Word Search II 
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

Hide Company Tags Microsoft Google Airbnb
Hide Tags Backtracking Trie
Hide Similar Problems (M) Word Search

class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> children;
        string word;
        TrieNode() {
            children.resize(26);
        }
    };
    
    void dfs(vector<string>& res, vector<vector<char>>& board, TrieNode* node, int row, int col, int m, int n) {
        // if the letter is visited or the word is not in trie
        char c=board[row][col];
        if (c=='#' || node->children[c-'a']==NULL) return;
        node=node->children[c-'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word.clear();
        }
        
        board[row][col]='#';
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n) {
                dfs(res, board, node, nr, nc, m, n);
            }
        }        
        board[row][col]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m=board.size();
        if (m==0) return res;
        int n=board[0].size();
        if (n==0) return res;
        
        // build trie
        TrieNode *root=new TrieNode();
        for (auto& w:words) {
            TrieNode *n=root;
            for (int i=0; i<w.size(); i++) {
                int j=w[i]-'a';
                if (n->children[j]==NULL) n->children[j]=new TrieNode();
                n=n->children[j];
            }
            n->word=w;
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                dfs(res, board, root, i, j, m, n);
            }
        }
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

