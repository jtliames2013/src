17. Letter Combinations of a Phone Number 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Hide Company Tags Amazon Dropbox Google Uber Facebook
Hide Tags Backtracking String
Show Similar Problems

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
	char getChar(char digit) {
		switch (digit) {
		case '2': return 'a';
		case '3': return 'd';
		case '4': return 'g';
		case '5': return 'j';
		case '6': return 'm';
		case '7': return 'p';
		case '8': return 't';
		case '9': return 'w';
		default: return '\0';
		}
	}

	bool isTop(char c) {
		if (c=='c' || c=='f' || c=='i' ||
			c=='l' || c=='o' || c=='s' ||
			c=='v' || c=='z') {
			return true;
		}

		return false;
	}

	char resetChar(char c) {
		if (c=='a' || c=='b' || c=='c') return 'a';
		else if (c=='d' || c=='e' || c=='f') return 'd';
		else if (c=='g' || c=='h' || c=='i') return 'g';
		else if (c=='j' || c=='k' || c=='l') return 'j';
		else if (c=='m' || c=='n' || c=='o') return 'm';
		else if (c=='p' || c=='q' || c=='r' || c=='s') return 'p';
		else if (c=='t' || c=='u' || c=='v') return 't';
		else if (c=='w' || c=='x' || c=='y' || c=='z') return 'w';
		else return '\0';
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	if (digits.empty()) return res;

    	string start;
    	for (int i=0; i<digits.size(); i++) {
    		if (digits[i]>='2' && digits[i]<='9') {
    			start.push_back(getChar(digits[i]));
    		}
    	}

    	if (!start.empty()) {
    		int i=0;

    		while (1) {
    			res.push_back(start);
    			if (isTop(start[i])) {
    				i++;
    				while (i<start.size() && isTop(start[i])) {
    					i++;
    				}
    				if(i==start.size()) break;
    				for (int j=0; j<i; j++) {
    					start[j]=resetChar(start[j]);
    				}
    				start[i]++;
    				i=0;
    			} else {
    				start[i]++;
    			}
    		}
    	}

    	return res;
    }
};

2. Use only two helper functions.

class Solution {
public:
    char getbase(char digit) {
        switch(digit) {
            case '2': return 'a';
            case '3': return 'd';
            case '4': return 'g';
            case '5': return 'j';
            case '6': return 'm';
            case '7': return 'p';
            case '8': return 't';
            case '9': return 'w';
            default: return '\0';
        }
    }
    
    bool istop(char c) {
        if (c=='c' || c=='f' || c=='i' || c=='l' ||
            c=='o' || c=='s' || c=='v' || c=='z') {
                return true;
            } else {
                return false;
            }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string output;
        std::remove(digits.begin(), digits.end(), '0');
        std::remove(digits.begin(), digits.end(), '1');
        int size=digits.size();
        int i;
        for (i=0; i<size; i++) {
            output.push_back(getbase(digits[i]));
        }
        
        i=0;
        while (1) {
            if (i==output.size()) break;
            res.push_back(output);
            
            if (!istop(output[i])) output[i]++;
            else {
                while (i<output.size()) {
                    if (!istop(output[i])) break;
                    i++;
                }
                
                if (i<output.size()) {
                    output[i]++;
                    for (int j=0; j<i; j++) {
                        output[j]=getbase(digits[j]);
                    }
                    i=0;
                }
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


