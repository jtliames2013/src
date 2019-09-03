127. Word Ladder Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 116984
Total Submissions: 606931
Difficulty: Medium
Contributor: LeetCode
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

Hide Company Tags Amazon LinkedIn Snapchat Facebook Yelp

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        if (n==0 || beginWord==endWord) return 0;
        unordered_set<string> dict;
        for (auto w:wordList) dict.insert(w);
        int steps=1;
        queue<string> q;
        int currNum=1, nextNum=0;
        q.push(beginWord);
        
        while (!q.empty()) {
            string f=q.front();
            q.pop();
            currNum--;
            
            for (int i=0; i<n; i++) {
                for (char c='a'; c<='z'; c++) {
                    string str=f;
                    if (c!=str[i]) {
                        str[i]=c;
                        if (dict.find(str)!=dict.end()) {
                            // length is number of steps plus the start
                            if (str==endWord) return steps+1;
                            q.push(str);
                            dict.erase(str);
                            nextNum++;
                        }
                    }
                }
            }
            
            if (currNum==0) {
                currNum=nextNum;
                nextNum=0;
                steps++;
            }
        }
        
        return 0;
    }
};

2. Use queue size
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        if (n==0 || beginWord==endWord) return 0;
        unordered_set<string> dict;
        for (auto w:wordList) dict.insert(w);
        int steps=1;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            int num=q.size();
            for (int k=0; k<num; k++) {
                string f=q.front();
                q.pop();
                
                for (int i=0; i<n; i++) {
                    for (char c='a'; c<='z'; c++) {
                        string str=f;
                        if (c!=str[i]) {
                            str[i]=c;
                            if (dict.find(str)!=dict.end()) {
                                // length is number of steps plus the start
                                if (str==endWord) return steps+1;
                                q.push(str);
                                dict.erase(str);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return 0;
    }
};

