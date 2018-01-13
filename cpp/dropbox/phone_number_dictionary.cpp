phone number + dictionary：leetcode 上的电话本问题的扩展。区别在于多了一个 dictionary，提供了一个函数 isWord（String word）返回 word 是否在 dictionary 中， 要求是只返回在 dictionary 中的 word。问了复杂度，问了优化方式，需要用 trie，对这个数据结构也不是很熟悉，简单说了一下怎么用，面试官也没细问。

0-9每个数字可以map到几个字母上，就和电话上的numberpad类似，然后给你一个词典，给你一串数字，让你输出所有用词典里的词把整个数字map出来的方法。比如说给你数字234567，给你词典["ADG", "JMP", "JMQ"], 你要输出[["ADG", "JMP"], ["ADG", "JMQ"]]

给一个号码，1928337，求对应的有效单词，例如 dropbox。followup 1: 求有效词组，比如一个号码拆分后也可以是｛ ‘drop’， ‘box’ ｝；2: 如果这个function 被heavily call，怎么办？hash map。

初始是7位号码，输出所有可能的单词，用dfs。
然后给一个api判断一个词是否在字典里，只输出在词典里的词，加一句代码，在结果里判断一下。
然后说结果可以是几个小词拼接起来的，小词最短长度是3，dfs函数中加一个变量表示当前词开始的下标。
然后说如果我能访问词典里所有词，能再怎么做？hashmap，key是长度为3或4或7的所有number String，value是这个number string对应的所有单词。
然后说这样还不行，让我另想一个数据结构，主动给hint说，我要判断一个词在不在词典里必须长度足够才行。就是用trie了，不用实现trie，给我两个方法，containpre和containstr，用dfs再做一下。. 
然后剩几分钟了，他说可以了，我主动说还能再改进，这样的计算还有冗余的地方，假设前面的两个字符我已经判断出了在前缀树里了，下一层递归我还要在判断一次这两个字符。改进的方法就是，不用trie的方法，而是直接拿trienode作为传参。
然后就对他提问，结束。

问了一道17. Letter Combinations of a Phone Number with isWord() API， 输入7位数，输出List of valid String 这个没问题 BackTrack solve。然后follow up 是给一个7位数字，字典里的词最小长度是3, 输出3+4, 4+3, 7个字母组成的valid词。这个的做法，就是另外写了一个函数去判断任意的一个长度为7的词是不是符合条件。
然后follow up 给了一个 validPrefix API, 让优化。面试官提示在BackTrack函数里优化。没想出，BackTrack  里怎么去判断3+4 或者是 4＋3呢， 提示是大于三就可以用validPrefix， 但是还是没有写完。请教一下大家，怎么在BackTrack 里用validPrefix 来优化。

先分析了一下，把combinations写了，面试官说不错，写了两个test cases, 然后写search。一开始给的条件是电话号码长度是7，直接分情况在dictionary里search就行了。
followup: 电话长度不为7， 想了一下，用DFS秒了, 其实就是word break. 然后分析各个函数的复杂度。
followup: 优化search函数（非complexity级别）。我在函数开始添加了一个从后向前的搜索，避免了不必要的递归。面试官说不错，还有没有什么优化办法。
followup: 面试官：考虑一下号码长度很长，但不至于stack overflow的情况，比方说["AAAAAAAAAAAAAA", "BAAAAAAAAAAAAA"]。我：用Trie Tree? 解释了一下，顿时觉得自己傻了，trie的速度比dict慢多了啊。。他又没问dict太大怎么办。。。面试官：考虑一下cache。我：那用个dict把每个结果存起来。写了一下，面试官说不错。

问phone number 和 word break. 假设词典的单词最小为3，这些面经都有。我写完后他问如果这个是放在服务器上的，可以怎么优化？我一下蒙住了，就说时间复杂度可能太高了。他就问怎么优化，然后又说如果词典单词大小不一定，这时候就要用到word break

电话号码转单词与word break的结合......提出了如果有isPrefix(string)来确认string是不是valid单词的开头这样的API，如何optimize。然后又问了isPrefix()这样的方法怎么implement，说了一下Trie的implementation。

phone number combination ，phone number是7位的，要求生成字典里的词。一开始要求是只能通过isvalid(word)来判断单词是否出现在字典里。
follow up 1: 字典里的词组成的也可以，同时知道字典里的词最小长度是3。那么只有两种情况，3+4或者4+3.
follow up 2: 如果可以分成任意的词该怎么办。
follow up 3: 如果字典里的词是给定的，可以怎么优化。想法是用trie来prune一些prefix

1.
class Solution {
public:
	vector<string> letterCombinations(string digits, unordered_set<string>& dict) {
		vector<string> res;
		string word;
		dfs(res, word, digits, dict, 0);
		return res;
	}

private:
	void dfs(vector<string>& res, string& word, string& digits, unordered_set<string>& dict, int start) {
		if (start==digits.size()) {
			if (isWord(word, dict)) {
				res.push_back(word);
			}
			return;
		}

		vector<char> letters=getChar(digits[start]);
		for (auto c:letters) {
			word.push_back(c);
			dfs(res, word, digits, dict, start+1);
			word.pop_back();
		}
	}

	bool isWord(string word, unordered_set<string>& dict) {
		return dict.find(word)!=dict.end();
	}

	vector<char> getChar(char digit) {
		switch (digit) {
		case '2': return {'a', 'b', 'c'};
		case '3': return {'d', 'e', 'f'};
		case '4': return {'g', 'h', 'i'};
		case '5': return {'j', 'k', 'l'};
		case '6': return {'m', 'n', 'o'};
		case '7': return {'p', 'q', 'r', 's'};
		case '8': return {'t', 'u', 'v'};
		case '9': return {'w', 'x', 'y', 'z'};
		default: return {};
		}
	}
};

void print(vector<string> res) {
	for (auto s:res) cout << s << " ";
	cout << endl;
}

int main() {
	Solution s;
	unordered_set<string> dict={"adg", "jmpt", "jnqu", "adgj", "mpt", "mpa", "adgjmpt", "drop", "box", "dropbox"};
	string digits1="2345678";
	auto res1=s.letterCombinations(digits1, dict);
	print(res1);

	string digits2="3767269";
	auto res2=s.letterCombinations(digits2, dict);
	print(res2);

	return 0;
}

2.
class Solution {
public:
	vector<vector<string>> letterCombinations(string digits, unordered_set<string>& dict) {
		vector<vector<string>> res;
		vector<string> output;
		dfs(res, output, "", digits, dict, 0, 0);
		return res;
	}

private:
	void dfs(vector<vector<string>>& res, vector<string>& output, string word, string& digits, unordered_set<string>& dict, int start, int wordStart) {
		if (start==digits.size()) {
			if (wordStart==start) res.push_back(output);
			return;
		}

		int len=start-wordStart+1;
		if (len>4) return;

		vector<char> letters=getChar(digits[start]);
		for (auto c:letters) {
			word.push_back(c);
			if ((len==3 || len==4) && isWord(word, dict)) {
				output.push_back(word);
				dfs(res, output, "", digits, dict, start+1, start+1);
				output.pop_back();
			}

			dfs(res, output, word, digits, dict, start+1, wordStart);

			word.pop_back();
		}
	}

	bool isWord(string word, unordered_set<string>& dict) {
		return dict.find(word)!=dict.end();
	}

	vector<char> getChar(char digit) {
		switch (digit) {
		case '2': return {'a', 'b', 'c'};
		case '3': return {'d', 'e', 'f'};
		case '4': return {'g', 'h', 'i'};
		case '5': return {'j', 'k', 'l'};
		case '6': return {'m', 'n', 'o'};
		case '7': return {'p', 'q', 'r', 's'};
		case '8': return {'t', 'u', 'v'};
		case '9': return {'w', 'x', 'y', 'z'};
		default: return {};
		}
	}
};

void print(vector<vector<string>> res) {
	for (auto v:res) {
		for (auto s:v) cout << s << " ";
		cout << endl;
	}
}

int main() {
	Solution s;
	unordered_set<string> dict={"adg", "jmpt", "jnqu", "adgj", "mpt", "mpa", "adgjmpt", "drop", "box", "dropbox"};
	string digits1="2345678";
	auto res1=s.letterCombinations(digits1, dict);
	print(res1);

	string digits2="3767269";
	auto res2=s.letterCombinations(digits2, dict);
	print(res2);

	return 0;
}

3.
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

	void add(string word) {
		TrieNode *n=root;
		for (int i=0; i<word.size(); i++) {
			if (n->children.find(word[i])==n->children.end()) {
				n->children[word[i]]=new TrieNode();
			}
			n=n->children[word[i]];
		}
		n->isWord=true;
	}

	TrieNode* root;
};

class Solution {
public:
	Solution (unordered_set<string>& dict) {
		for (auto w:dict) trie.add(w);
	}

	vector<vector<string>> letterCombinations(string digits) {
		vector<vector<string>> res;
		vector<string> output;

		dfs(res, output, "", digits, trie.root, 0);
		return res;
	}

private:
	Trie trie;

	void dfs(vector<vector<string>>& res, vector<string>& output, string word, string& digits, TrieNode* node, int start) {
		if (start==digits.size()) {
			if (node==trie.root) res.push_back(output);
			return;
		}

		vector<char> letters=getChar(digits[start]);
		for (auto c:letters) {
			if (!isPrefix(c, node)) continue;
			word.push_back(c);
			if (isWord(node->children[c])) {
				output.push_back(word);
				dfs(res, output, "", digits, trie.root, start+1);
				output.pop_back();
			}

			dfs(res, output, word, digits, node->children[c], start+1);

			word.pop_back();
		}
	}

	bool isPrefix(char c, TrieNode *node) {
		return node->children.find(c)!=node->children.end();
	}

	bool isWord(TrieNode *node) {
		return node->isWord;
	}

	vector<char> getChar(char digit) {
		switch (digit) {
		case '2': return {'a', 'b', 'c'};
		case '3': return {'d', 'e', 'f'};
		case '4': return {'g', 'h', 'i'};
		case '5': return {'j', 'k', 'l'};
		case '6': return {'m', 'n', 'o'};
		case '7': return {'p', 'q', 'r', 's'};
		case '8': return {'t', 'u', 'v'};
		case '9': return {'w', 'x', 'y', 'z'};
		default: return {};
		}
	}
};

void print(vector<vector<string>> res) {
	for (auto v:res) {
		for (auto s:v) cout << s << " ";
		cout << endl;
	}
}

int main() {
	unordered_set<string> dict={"adg", "jmpt", "jnqu", "adgj", "mpt", "mpa", "adgjmpt", "drop", "box", "dropbox"};
	Solution s(dict);
	string digits1="2345678";
	auto res1=s.letterCombinations(digits1);
	print(res1);

	string digits2="3767269";
	auto res2=s.letterCombinations(digits2);
	print(res2);

	return 0;
}

