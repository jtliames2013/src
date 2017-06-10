126. Word Ladder II
DescriptionHintsSubmissionsSolutions
Total Accepted: 65728
Total Submissions: 472550
Difficulty: Hard
Contributor: LeetCode
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

Subscribe to see which companies asked this question.

Hide Tags Array Backtracking Breadth-first Search String

http://blog.csdn.net/linhuanmars/article/details/23071455

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto& w:wordList) dict.insert(w);
        vector<vector<string>> res;
        queue<vector<string>> q;
        unordered_set<string> visited;
        q.push({beginWord});
        int level=1;
        int minlevel=INT_MAX;
        
        while (!q.empty()) {
            vector<string> path=q.front();
            q.pop();
            if (path.size()>level) {
                for (auto w:visited) dict.erase(w);
                visited.clear();
                if (path.size()>minlevel) break;
                else level=path.size();
            }
            
            string last=path.back();
            for (int i=0; i<last.size(); i++) {
                string next=last;
                for (char c='a'; c<='z'; c++) {
                    next[i]=c;
                    if (dict.find(next)!=dict.end()) {
                        vector<string> newpath=path;
                        newpath.push_back(next);
                        visited.insert(next);
                        if (next==endWord) {
                            minlevel=level;
                            res.push_back(newpath);
                        } else {
                            q.push(newpath);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

