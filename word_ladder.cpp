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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
    	int dist=0;
    	queue<string> words1;
    	queue<string> words2;

    	if (start.compare(end) == 0) return dist;

    	words1.push(start);

    	while (1)
    	{
    		if (words1.empty() && words2.empty()) break;

    		dist++;
			while (!words1.empty())
			{
				string word = words1.front();
				words1.pop();

				for (unsigned int i=0; i<word.size(); i++)
				{
					for (char c='a'; c<='z'; c++)
					{
						if (c != word[i])
						{
							string transform = word;
							transform[i] = c;
							if (dict.find(transform) != dict.end())
							{
								dict.erase(transform);
								words2.push(transform);
								if (end.compare(transform) == 0)
								{
									return dist+1;
								}
							}
						}
					}
				}
    		}

			dist++;
			while (!words2.empty())
			{
				string word = words2.front();
				words2.pop();

				for (unsigned int i=0; i<word.size(); i++)
				{
					for (char c='a'; c<='z'; c++)
					{
						if (c != word[i])
						{
							string transform = word;
							transform[i] = c;
							if (dict.find(transform) != dict.end())
							{
								dict.erase(transform);
								words1.push(transform);
								if (end.compare(transform) == 0)
								{
									return dist+1;
								}
							}
						}
					}
				}
			}
    	}

    	return 0;
    }
};

int main()
{
	return 0;
}

