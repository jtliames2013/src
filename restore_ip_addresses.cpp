93. Restore IP Addresses  QuestionEditorial Solution  My Submissions
Total Accepted: 63242 Total Submissions: 257742 Difficulty: Medium
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
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
	bool isValidIpPart(string &s, int start, int n)
	{
		if (n <= 0 || n > 3 || start+n>s.size()) return false;
		if (n >= 2 && s[start]=='0') return false;

		return atoi(s.substr(start, n).c_str()) <= 255;
	}

	vector<string> restore(string &s, int npart, int start, int n)
	{
		vector<string> res;
		if (npart==1)
		{
			if (isValidIpPart(s, start, n))
			{
				res.push_back(s.substr(start,n));
			}
			return res;
		}

		if (isValidIpPart(s, start, 1))
		{
			vector<string> v = restore(s, npart-1, start+1, n-1);
			if (v.size() > 0)
			{
				for (unsigned int i=0; i<v.size(); i++)
				{
					string tmp=s.substr(start,1);
					tmp += ".";
					tmp += v[i];
					res.push_back(tmp);
				}
			}
		}

		if (isValidIpPart(s, start, 2))
		{
			vector<string> v = restore(s, npart-1, start+2, n-2);
			if (v.size() > 0)
			{
				for (unsigned int i=0; i<v.size(); i++)
				{
					string tmp=s.substr(start,2);
					tmp += ".";
					tmp += v[i];
					res.push_back(tmp);
				}
			}
		}

		if (isValidIpPart(s, start, 3))
		{
			vector<string> v = restore(s, npart-1, start+3, n-3);
			if (v.size() > 0)
			{
				for (unsigned int i=0; i<v.size(); i++)
				{
					string tmp=s.substr(start,3);
					tmp += ".";
					tmp += v[i];
					res.push_back(tmp);
				}
			}
		}
		return res;
	}

    vector<string> restoreIpAddresses(string s) {
    	return restore(s, 4, 0, s.size());
    }
};

2. Don't return vector of string

class Solution {
public:
    void getIp(vector<string>& res, string& ip, string& s, int index, int numAddr) {
        if (numAddr==4) {
            if (index==s.size()) {
                res.push_back(ip);
                return;
            } else {
                return;
            }
        }
        
        for (int i=index; i<=index+2 && i<s.size(); i++) {
            string str=s.substr(index, i-index+1);
            int num=atoi(str.c_str());
            if (num>=0 && num<=255 && (i==index || s[index]!='0')){
                int len=ip.size();
                if (len>0) {
                    ip.push_back('.');
                }
                ip+=str;
                getIp(res, ip, s, i+1, numAddr+1);
                ip.erase(len, ip.size()-len);
            }
        }
    }    

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        getIp(res, ip, s, 0, 0);        

        return res;
    }
};

int main()
{
	return 0;
}

