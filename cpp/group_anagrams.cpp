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

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (auto &str:strs) {
            string key=str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        
        for (auto iter:m) {
            res.push_back(iter.second);    
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


