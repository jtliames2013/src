500. Keyboard Row Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 24040
Total Submissions: 39853
Difficulty: Easy
Contributor: LeetCode
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
Subscribe to see which companies asked this question.

Hide Tags Hash Table

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char,int> mp={{'q',1}, {'w',1}, {'e',1}, {'r',1}, {'t',1}, {'y',1}, {'u',1}, {'i',1}, {'o',1}, {'p',1},
                                    {'a',2}, {'s',2}, {'d',2}, {'f',2}, {'g',2}, {'h',2}, {'j',2}, {'k',2}, {'l',2},
                                    {'z',3}, {'x',3}, {'c',3}, {'v',3}, {'b',3}, {'n',3}, {'m',3}};
        
        for (auto w:words) {
            if (!w.empty()) {
                int row=mp[tolower(w[0])];
                if (row>=1 && row<=3) {
                    int i;
                    for (i=1; i<w.size(); i++) {
                        if (mp[tolower(w[i])]!=row) break; 
                    }
                    if (i==w.size()) res.push_back(w);
                }
            }
        }
        return res;
    }
};

