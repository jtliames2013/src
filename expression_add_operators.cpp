#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
	 bool hasleadingzero(string s) {
		 if (s.size()>1 && s[0]=='0') return true;
	 }

	 void addOp(string& num, int target, vector<string>& res, string& prefix, int index, int multi, bool hasmulti, bool hasminus) {
		 if (index==num.size()) {
			 return;
		 }

		 if (!hasleadingzero(num.substr(index, num.size()-index))) {
			 unsigned long t=strtoul(num.substr(index, num.size()-index).c_str(), NULL, 0);
			 if ((hasmulti==false && hasminus==false && t==target) ||
                 (hasmulti==false && hasminus==true && t==-target) ||
				 (hasmulti==true && hasminus==false && t*multi==target) ||
                 (hasmulti==true && hasminus==true && t*multi==-target)) {
				 string tmp=prefix;
				 tmp.append(num.substr(index, num.size()-index));
				 res.push_back(tmp);
				 return;
			 }
		 }

		 for (int i=index; i<num.size(); i++) {
			 if (hasleadingzero(num.substr(index, i-index+1))) continue;
			 unsigned long n=strtoul(num.substr(index, i-index+1).c_str(), NULL, 0);
			 if (hasminus) n=-n;
			 int pos=prefix.size();
			 prefix.append(num.substr(index, i-index+1));

			 prefix.push_back('+');
			 addOp(num, target-n*multi, res, prefix, i+1, 1, false, false);
			 prefix.erase(prefix.end()-1);

			 prefix.push_back('-');
			 addOp(num, target-n*multi, res, prefix, i+1, 1, false, true);
			 prefix.erase(prefix.end()-1);


			 prefix.push_back('*');
			 addOp(num, target, res, prefix, i+1, n*multi, true, false);
			 prefix.erase(prefix.end()-1);

			 prefix.erase(pos, i-index+1);
		 }
	 }

     vector<string> addOperators(string num, int target) {
    	 vector<string> res;
    	 string prefix("");

    	 addOp(num, target, res, prefix, 0, 1, false, false);

		 std::sort(res.begin(), res.end(), [](string a, string b) { return a.compare(b) < 0; });
    	 return res;
     }
 };

int main()
{
	return 0;
}

