299. Bulls and Cows 
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Hide Tags Hash Table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>

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

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

  class Solution {
  public:
      string getHint(string secret, string guess) {
    	  string res;
    	  int bull=0, cow=0;
    	  int size=secret.size();
    	  map<char, int> count;
    	  for (int i=0; i<size; i++) {
    		  if (secret[i]==guess[i]) {
    			  bull++;
    		  } else {
    			  if (count.find(secret[i])==count.end()) {
    				  count[secret[i]]=1;
    			  } else {
    				  count[secret[i]]++;
    			  }
    		  }
    	  }

    	  for (int i=0; i<size; i++) {
    		  if (secret[i]!=guess[i]) {
    			  if (count.find(guess[i])!=count.end()) {
    				  cow++;
    				  count[guess[i]]--;
    				  if (count[guess[i]]==0) count.erase(guess[i]);
    			  }
    		  }
    	  }

    	  char buf[64];
    	  sprintf(buf, "%d", bull);
    	  res.append(buf);
    	  res.append("A");
    	  sprintf(buf, "%d", cow);
    	  res.append(buf);
    	  res.append("B");

    	  return res;
      }
  };

int main()
{
	return 0;
}

