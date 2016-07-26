91. Decode Ways  
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Hide Company Tags Microsoft Uber Facebook
Hide Tags Dynamic Programming String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <limits.h>

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
    int numDecodings(string s) {
    	int len = s.size();
    	if (len == 0) return 0;

    	vector<int> count(len);

    	for (int i=len-1; i>=0; i--)
    	{
    		if (i < len-1)
    		{
    			count[i] = count[i+1];

    			if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6' && s[i+1] >= '0' ))
    			{
    				if (i < len-2)
    				{
    					count[i] += count[i+2];
    				}
    				else
    				{
    					count[i] += 1;
    				}
    			}
    			else if (s[i] == '0')
    			{
    				count[i] = 0;
    			}
    		}
    		else
    		{
    			if (s[i] == '0') count[i] = 0;
    			else count[i] = 1;
    		}
    	}

    	return count[0];
    }
};

2. calculate from end
class Solution {
public:
    int numDecodings(string s) {
        int size=s.size();
        if (size==0) return 0;
        vector<int> res(size+1, 1);

        if (s[size-1]=='0') res[size-1]=0;
        for (int i=size-2; i>=0; i--) {
            if ((s[i]=='1') || 
                (s[i]=='2' && s[i+1]<='6')) {
                res[i]=res[i+1]+res[i+2];
            } else if (s[i]=='0') {
                res[i]=0;
            } else {
                res[i]=res[i+1];
            }
        }

        return res[0];
    }
};

3. calculate from begining
class Solution {
public:
    int numDecodings(string s) {
        int size=s.size();
        if (size==0) return 0;
        vector<int> dp(size+1, 0);
        dp[0]=1;
        dp[1]=1;
        if (s[0]=='0') dp[1]=0;
        for (int i=2; i<=size; i++) {
            if (s[i-1]>'0') dp[i]=+dp[i-1];
            if (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')) {
                dp[i]+=dp[i-2];
            }
        }
        
        return dp[size];
  }
};

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<int> dp(n,0);
        if (s[0]!='0') dp[0]=1;
        for (int i=1; i<n; i++) {
            if (s[i]!='0') dp[i]=dp[i-1];
            if (s[i-1]=='1' || (s[i-1]=='2'&&s[i]<='6')) {
                if (i<2) dp[i]+=1;
                else dp[i]+=dp[i-2];
            }
        }
        
        return dp[n-1];
  }
};

int main()
{
	return 0;
}

