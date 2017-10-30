Question:
Given a list of word and a target word, output all the words for each the edit distance with the target no greater than k.

e.g. [abc, abd, abcd, adc], target "ac", k = 1,

output = [abc, adc]

Naive Solution:
A naive solution would be, for each word in the list, calculate the edit distance with the target word. If it is equal or less than k, output to the result list. 

If we assume that the average length of the words is m, and the total number of words in the list is n, the total time complexity is O(n * m^2). 

A better solution with a trie:
The problem with the previous solution is if the given list of the words is like ab, abc, abcd, each time we need to repeatedly calculate the edit distance with the target word. If we can combine the prefix of all words together, we can save lots of time. 

1. Naive
class Solution {
public:
	  int getEditDistance(string word1, string word2) {
		  int m=word1.size();
		  int n=word2.size();
		  vector<vector<int> > dp(m+1, vector<int>(n+1,0));
		  for (int i=1; i<=m; i++) dp[i][0]=i;
		  for (int j=1; j<=n; j++) dp[0][j]=j;

		  for (int i=1; i<=m; i++) {
			  for (int j=1; j<=n; j++) {
				  int delta=(word1[i-1]==word2[j-1])?0:1;
				  dp[i][j]=min(min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1]+delta);
			  }
		  }

		  return dp[m][n];
	  }
	  vector<string> getKEditDistance(vector<string>& words, string target, int k) {
		  vector<string> res;
		  for (int i=0; i<words.size(); i++) {
			  int dist=getEditDistance(words[i], target);
			  if (dist<=k) res.push_back(words[i]);
		  }

		  return res;
	  }
  };

int main()
{
	Solution s;
	vector<string> words={"abc", "abd", "abcd", "adc"};
	string target="ac";
	vector<string> res=s.getKEditDistance(words, target, 1);
  	return 0;
}


2. Use Trie
http://www.fgdsb.com/2015/01/24/get-similar-words/
http://stevehanov.ca/blog/index.php?id=114
class TrieNode {
public:
	  map<char, TrieNode*> children;
	  bool isWord;
	  TrieNode() : isWord(false) {}
  };

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		int i=0;
		TrieNode *node=root;
		for (; i<word.size(); i++) {
			auto iter=node->children.find(word[i]);
			if (iter==node->children.end()) break;
			node=iter->second;
		}

		TrieNode *curr;
		for (; i<word.size(); i++) {
			curr=new TrieNode();
			node->children[word[i]]=curr;
			node=curr;
		}
		curr->isWord=true;
	}

	TrieNode* root;
};

class Solution {
public:
	  void getDistance(vector<string>& res, TrieNode* node, string& target, vector<int> dp, int k, string word) {
		  int n=target.size();
		  vector<int> newdp(n+1, 0);

		  for (auto child:node->children) {
			  word.push_back(child.first);
			  newdp[0]=word.size();
			  for (int i=1; i<=n; i++) {
				  int delta=(child.first==target[i-1])?0:1;
				  newdp[i]=min(min(dp[i], newdp[i-1])+1, dp[i-1]+delta);
			  }
			  if (child.second->isWord && newdp[n]<=k) {
				  res.push_back(word);
			  }

			  getDistance(res, child.second, target, newdp, k, word);
			  word.erase(word.end()-1);
		  }
	  }

	  vector<string> getKEditDistance(vector<string>& words, string target, int k) {
		  vector<string> res;
		  Trie prefix;
		  for (auto w:words) prefix.insert(w);
		  int n=target.size();
		  vector<int> dp(n+1, 0);
		  string word;
		  for (int i=1; i<=n; i++) dp[i]=i;

		  getDistance(res, prefix.root, target, dp, k, word);

		  return res;
	  }
  };

int main()
{
	Solution s;
	vector<string> words={"abc", "abd", "abcd", "adc"};
	string target="ac";
	vector<string> res=s.getKEditDistance(words, target, 1);
  	return 0;
}


