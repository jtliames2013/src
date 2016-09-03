首先计算字符串s中每一个字符出现的次数，得到字典counter

遍历字符串s，记当前字符为c，将counter[c] - 1

如果c已经在栈stack中，继续遍历

将字符c与栈顶元素top进行比较，若top > c并且counter[top] > 0则弹栈，重复此过程

将c入栈

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	map<char, int> getCount(string s) {
		map<char, int> res;

		for (int i=0; i<s.size(); i++) {
			if (res.find(s[i])!=res.end()) {
				res[s[i]]++;
			} else {
				res[s[i]]=1;
			}
		}

		return res;
	}

    string removeDuplicateLetters(string s) {
    	string res;
    	map<char, int> cnt;
    	vector<char> stk;
    	unordered_set<char> set;

    	cnt = getCount(s);
    	for (int i=0; i<s.size(); i++) {
    		cnt[s[i]]--;
    		if (set.find(s[i])==set.end()) {
    			while (!stk.empty() && stk.back()>s[i] && cnt[stk.back()]>0) {
    				set.erase(stk.back());
    				stk.pop_back();
    			}
    			stk.push_back(s[i]);
    			set.insert(s[i]);
    		}
    	}

    	for (int i=0; i<stk.size(); i++) {
    		res.push_back(stk[i]);
    	}
    	return res;
    }
};

int main()
{
	return 0;
}

