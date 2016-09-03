387. First Unique Character in a String  QuestionEditorial Solution  My Submissions
Total Accepted: 10650 Total Submissions: 24737 Difficulty: Easy
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        for (auto l:s) {
            count[l]++;
        }
        
        for (int i=0; i<s.size(); i++) {
            if (count[s[i]]==1) return i;
        }
        return -1;
    }
};
