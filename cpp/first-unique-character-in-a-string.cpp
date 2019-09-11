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
        vector<int> mp(256);
        for (auto c:s) mp[c]++;
        for (int i=0; i<s.size(); i++) {
            if (mp[s[i]]==1) return i;
        }
        return -1;
    }
};

2.
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        for (int i=0; i<s.size(); i++) {
            mp[s[i]].first++;
            mp[s[i]].second=i;
        }
        int res=INT_MAX;
        for (auto &m:mp) {
            if (m.second.first==1) res=min(res, m.second.second);
        }
        return res==INT_MAX?-1:res;
    }
};

