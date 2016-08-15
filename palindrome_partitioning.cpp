131. Palindrome Partitioning  QuestionEditorial Solution  My Submissions
Total Accepted: 71833 Total Submissions: 249685 Difficulty: Medium
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
Hide Company Tags Bloomberg
Hide Tags Backtracking
Hide Similar Problems (H) Palindrome Partitioning II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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

class Solution {
public:
	bool isPalindrome(string &s, int start, int end)
	{
		while (start < end)
		{
			if (s.c_str()[start] == s.c_str()[end])
			{
				start++;
				end--;
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	vector<vector<string>> partition(string s) {
		int len = s.size();
		vector<vector<vector<string>>> res(len);

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (isPalindrome(s, j, i))
				{
					vector<string> v;
					if (j > 0)
					{
						for (unsigned int k = 0; k < res[j-1].size(); k++)
						{
							v.clear();
							v = res[j-1][k];
							v.push_back(s.substr(j, i-j+1));

							res[i].push_back(v);
						}
					}
					else
					{
						v.clear();
						v.push_back(s.substr(j, i-j+1));

						res[i].push_back(v);
					}
				}
			}
		}

		return res[len-1];
    }
};

2.

 class Solution {
 public:
	 bool isPalindrome(string& s, int start, int end) {
		 while (start<end) {
			 if (s[start]!=s[end]) return false;
			 start++;
			 end--;
		 }

		 return true;
	 }

	 void findPartition(string& s, vector<vector<string> >& res, vector<string>& part, int start) {
		 if (start==s.size()) {
			 res.push_back(part);
			 return;
		 }

		 for (int i=start; i<s.size(); i++) {
			 if (isPalindrome(s, start, i)) {
				 part.push_back(s.substr(start, i-start+1));
				 findPartition(s, res, part, i+1);
				 part.pop_back();
			 }
		 }
	 }

     vector<vector<string>> partition(string s) {
    	 vector<vector<string> > res;
    	 vector<string> part;

    	 findPartition(s, res, part, 0);

    	 return res;
     }
 };

3. Cache isPalindrome results

class Solution {
public:
    void buildIsPalin(string& s, vector<vector<bool>>& isPalin) {
        for (int i=0; i<s.size(); i++) {
            for (int j=i; j>=0; j--) {
                if (i==j) isPalin[j][i]=true;
                else if (j==i-1 && s[i]==s[j]) isPalin[j][i]=true;
                else if (j<i-1 && isPalin[j+1][i-1]==true && s[i]==s[j]) isPalin[j][i]=true;
            }
        }
    }
    
    void getPartition(vector<vector<string>>& res, vector<string>& part, vector<vector<bool>>& isPalin, string& s, int start) {
            if (start>=s.size()) {
                res.push_back(part);
                return;
            }
            
            for (int i=start; i<s.size(); i++) {
                if (isPalin[start][i]==true) {
                    part.push_back(s.substr(start, i-start+1));
                    getPartition(res, part, isPalin, s, i+1);
                    part.pop_back();
                }
            }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        int size=s.size();
        if (size==0) return res;
        vector<vector<bool>> isPalin(size, vector<bool>(size, false));
        buildIsPalin(s, isPalin);
        
        getPartition(res, part, isPalin, s, 0);    
        
        return res;
    }
};

int main()
{
	return 0;
}

