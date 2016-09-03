127. Word Ladder 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
Hide Company Tags Amazon LinkedIn Snapchat Facebook Yelp

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

2.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int len=0;
        int size=beginWord.size();
        if (size==0 || beginWord==endWord) return 0;
        int steps=1;
        int currLevel, nextLevel=0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        currLevel=1;
        
        while (!q.empty()) {
            string front=q.front();
            q.pop();
            currLevel--;
            
            for (int i=0; i<size; i++) {
                for (char c='a'; c<='z'; c++) {
                    string str=front;
                    if (str[i]!=c) {
                        str[i]=c;
                        // length is number of steps plus the start
                        if (str==endWord) return steps+1;
                        if (wordList.find(str)!=wordList.end() && visited.find(str)==visited.end()) {
                            q.push(str);
                            visited.insert(str);
                            nextLevel++;                
                        }
                    }
                }
            }
            
            if (currLevel==0) {
                currLevel=nextLevel;
                nextLevel=0;
                steps++;
            }
        }
        
        return 0;
    }
};

int main()
{
	return 0;
}

