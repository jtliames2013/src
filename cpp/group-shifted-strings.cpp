249. Group Shifted Strings
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Facebook
|
3

class Solution {
public:
    string convert(string& str) {
        if (str.empty()) return str;
        string res=str;
        int dist=res[0]-'a';
        for (int i=0; i<res.size(); i++) {
            res[i]-=dist;
            if (res[i]<'a') res[i]+=26;
        }
        
        return res;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto& str:strings) {
            string key=convert(str);
            mp[key].push_back(str);
        }
        
        for (auto iter:mp) {
            res.push_back(iter.second);
        }
        
        return res;
    }
};

