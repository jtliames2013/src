68. Text Justification 
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
Hide Company Tags LinkedIn Airbnb
Hide Tags String


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
     vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	 vector<string> res;
    	 int size=words.size();
    	 if (size==0) return res;

    	 string line;
    	 bool lineStarted=false;
    	 int lineStartIdx;
    	 int lineLen;
    	 for (int i=0; i<size; i++) {
    		 if (!lineStarted) {
    			 lineStarted=true;
    			 lineStartIdx=i;
    			 lineLen=words[i].size();
    		 } else {
    			 if (lineLen+words[i].size()+(i-lineStartIdx)>maxWidth) {
    				 // fit lineStartIdx to i-1 into line
    				 line.clear();
    				 int numSpaces=0;
    				 if (i-1>lineStartIdx) {
    					 numSpaces=(maxWidth-lineLen)/(i-1-lineStartIdx);
    				 }
    				 int modSpace=0;
    				 if (i-1>lineStartIdx) {
    					 modSpace = (maxWidth-lineLen)%(i-1-lineStartIdx);
    				 }
    				 if (lineStartIdx==i-1) {
    					 line.append(words[lineStartIdx]);
    					 if (line.size()<maxWidth) {
    						string remain(maxWidth-line.size(), ' ');
    						line.append(remain);
    					 }
    				 } else {
						 for (int j=lineStartIdx; j<i; j++) {
							 line.append(words[j]);
							 if (j<i-1) {
								 int num=(j-lineStartIdx<modSpace) ? numSpaces+1 : numSpaces;
								 string remain(num, ' ');
								 line.append(remain);
							 }
						 }
    				 }

    				 res.push_back(line);

    				 lineStartIdx=i;
    				 lineLen=words[i].size();
    			 } else {
    				 lineLen+=words[i].size();
    			 }
    		 }
    	 }

    	 if (lineStarted) {
    		 line.clear();
    		 for (int i=lineStartIdx; i<words.size(); i++) {
    			 line.append(words[i]);
    			 if (i<words.size()-1) line.append(" ");
    		 }

    		 if (line.size()<maxWidth) {
    			 string remain(maxWidth-line.size(), ' ');
    			 line.append(remain);
    		 }

    		 res.push_back(line);
    	 }

    	 return res;
     }
 };

2.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int size=words.size();
        int i=0;
        
        while (i<size) {
            int j;
            int len=0;
            for (j=i; j<size; j++) {
                if (len+words[j].size()+j-i>maxWidth) break;
                else len+=words[j].size();
            }
            
            string line;
            int totalSpace=maxWidth-len;
            int numWords=j-i;
            int div=numWords==1?totalSpace:totalSpace/(numWords-1);
            int mod=numWords==1?0:totalSpace%(numWords-1);
            for (int k=i; k<j; k++) {
                line+=words[k];
                if (totalSpace>0) {
                    int space;
                    if (j==words.size()) {
                        // last line
                        space=k==j-1?totalSpace:1;
                    } else {
                        space=div;
                        if (k-i<mod) space+=1;
                    }
                    
                    line.append(space, ' ');
                    totalSpace-=space;
                }
            }
            
            res.push_back(line);
            i=j;
        }
        
        return res;
    }
};

int main()
{
	return 0;
}

