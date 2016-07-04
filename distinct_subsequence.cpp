115. Distinct Subsequences 
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.


思路：

一看要求解的个数，然后又是string匹配，而且形式上和Minimum Edit Distance那题很像，基本就是DP题跑不了了。DP题惯例的三步走：定义状态，推导递推公式，确定状态计算方向和起始状态。

1. 状态：i, j分别表示T中长度为i的prefix：T[0:i-1]，和S中长度为j的prefix：S[0:j-1]。
DP[i][j]：S[0:j-1]中存在T[0:i-1]作为distinct subsequence的个数。显然如果j<i，DP[i][j] = 0。

2. 递推公式：
(a) T[i]!=s[j]:

T = r a b
S = r c a c b c

DP[i+1][j+1] = DP[i+1][j]

(b) T[i] = s[j]: 

T = r a b b
S = r a b b b  - DP[i+1][j] = 1
S = r a b b b  - DP[i][j] = 2
S = r a b b b  /

DP[i+1][j+1] = DP[i][j] + DP[i+1][j]

公式总结：
S[j-1]!= T[i-1]：DP[i][j] = DP[i][j-1]
S[j-1]==T[i-1]：DP[i][j] = DP[i-1][j-1] + DP[i][j-1]


3. 计算方向和起始状态：
DP[i][j]
DP[i+1][j]   DP[i+1][j+1]

所以从上向下，从左到右的顺序可以计算。

根据计算顺序，需要先设置第0行、0列的值。
第0列：DP[i][0] = 0，i>0。因为T的长度大于S的长度，不可能成为S的subsequence。
第0行：DP[0][j] = 1，j>=0。这是为了保证第1行的计算正确：

T = r
S = r a r b r c

      r a  r b r  c  
  1 1 1 1 1 1 1
r 0 1 1 2 2 3 3


4. 计算优化：用滚动数组减少内存消耗。

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
     int numDistinct(string s, string t) {
    	 int slen=s.size();
    	 if (slen==0) return 0;
    	 int tlen=t.size();
    	 int upperleft;

    	 vector<int> res(slen+1, 1);
    	 for (int i=1; i<=tlen; i++) {
    		 upperleft=res[0];
    		 res[0]=0;
    		 for (int j=1; j<=slen; j++) {
    			 int temp=res[j];
    			 if (s[j-1]==t[i-1]) {
    				 res[j]=res[j-1]+upperleft;
    			 } else {
    				 res[j]=res[j-1];
    			 }
    			 upperleft=temp;
    		 }
    	 }

    	 return res[slen];
     }
 };

2.

class Solution {

public:

    int numDistinct(string s, string t) {

        int m=s.size();

        int n=t.size();

        

        vector<int> dp(n+1, 0);

        dp[0]=1;

        

        // index 0 means emtpy string

        for (int i=1; i<=m; i++) {

            int upperleft=1;

            for (int j=1; j<=n && j<=i; j++) {

                int temp=dp[j];

                if (s[i-1]==t[j-1]) {

                    dp[j]=upperleft+dp[j];

                } 

                // else dp[j]=dp[j]

                upperleft=temp;

            }

        }

        

        return dp[n];

    }

};


int main()
{
	return 0;
}

