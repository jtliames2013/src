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

  class Node {
  public:
	  Node* getChildForLetter(char letter);
	  vector<pair<char, Node*>> getAllChildren();
	  bool isTerminal();
  };

class Trie{
	  Trie() {
		  root=new Node();
	  }

	  void search(vector<string>& res, Node* node, string& pattern, string& output, int start) {
		  if (start==pattern.size() && node->isTerminal()) {
			  res.push_back(output);
			  return;
		  }

		  if (pattern[start]=='*') {
			  for (auto child:node->getAllChildren()) {
				  // match * to more letters
				  int len=output.size();
				  output.push_back(child.first);
				  search(res, child.second, pattern, output, start);
				  output.erase(output.begin()+len);
				  // match * to one letter
				  output.push_back(child.first);
				  search(res, child.second, pattern, output, start+1);
				  output.erase(output.begin()+len);
				  // skip *
				  search(res, child.second, pattern, output, start+1);
			  }
		  } else {
			  Node *child=node->getChildForLetter(pattern[start]);
			  if (child!=NULL) {
				  int len=output.size();
				  output.push_back(pattern[start]);
				  search(res, child, pattern, output, start+1);
				  output.erase(output.begin()+len);
			  }
		  }
	  }

	  vector<string> search(string pattern) {
		  vector<string> res;
		  string output;
		  search(res, root, pattern, output, 0);
		  return res;
	  }

private:
	  Node *root;
  };

