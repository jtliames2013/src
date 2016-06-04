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

int main()
{
	return 0;
}

