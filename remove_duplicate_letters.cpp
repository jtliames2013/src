Given "cbacdcbc"
Return "acdb"

贪心算法（Greedy Algorithm）

时间复杂度 O(k * n)，其中k为字符串中唯一字符的个数，n为字符串的长度

枚举字符串前缀，直到遇到首个唯一字符为止，从前缀中挑选出最小的字符作为首字符。
Find the first single minimum char. The char before it can be removed because there are duplicate after it.

Remove all chars before it and 然后从剩余字符串中移除所有与首字母相同的字母

重复此过程，直到选出所有唯一字符为止。



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
		int len=strlen(s.c_str());
		for (int i=0; i<len; i++) {
			if (res.find(s[i])!=res.end()) {
				res[s[i]]++;
			} else {
				res[s[i]]=1;
			}
		}

		return res;
	}

	void removeChar(char c, int index, string& s) {
		int last=0;
		int len=strlen(s.c_str());
		int i;
		for (i=0; index+i<len; i++) {
			s[i]=s[index+i];
		}
		s[i]='\0';
		len=strlen(s.c_str());
		for (i=0; i<len; i++) {
			if (s[i]!=c) {
				s[last]=s[i];
				last++;
			}
		}
		s[last]='\0';
	}

    string removeDuplicateLetters(string s) {
    	string res;
    	map<char, int> cnt;

    	int len=strlen(s.c_str());
    	while (len>0) {
    		cnt = getCount(s);

    		char minc=s[0];
    		int index=0;

    		for (int i=0; i<len; i++) {
    			if (minc > s[i]) {
    				minc=s[i];
    				index=i;
    			}
    			cnt[s[i]]--;

    			if (cnt[s[i]]==0) break;
    		}

    		removeChar(minc, index+1, s);
    		res.push_back(minc);
    		len=strlen(s.c_str());
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

