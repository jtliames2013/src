49. Group Anagrams  QuestionEditorial Solution  My Submissions
Total Accepted: 86398 Total Submissions: 295781 Difficulty: Medium
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

Hide Company Tags Amazon Bloomberg Uber Facebook Yelp
Hide Tags Hash Table String
Hide Similar Problems (E) Valid Anagram (E) Group Shifted Strings

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto str:strs) {
            string key=str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        
        for (auto v:mp) {
            res.push_back(v.second);
        }
        return res;
    }
};


