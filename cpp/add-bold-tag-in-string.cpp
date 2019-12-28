616. Add Bold Tag in String
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].

Facebook
|
2

Google
|
5

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int,int>> intervals;
        for (auto& w:dict) {
            int n=w.size();
            for (int i=0; i<s.size(); i++) {
                if ((i=s.find(w, i))==string::npos) break;
                intervals.push_back({i,i+n});                
            }
        }        
        if (intervals.empty()) return s;
        
        // merge intervals
        sort(intervals.begin(), intervals.end(), [](pair<int,int>&a, pair<int,int>&b) { return a.first<b.first; } );
        vector<pair<int,int>> merge;
        merge.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].first>merge.back().second) {
                merge.push_back(intervals[i]);
            } else {
                merge.back().second=max(merge.back().second, intervals[i].second);
            }
        }
        
        // add tag
        string res;
        int end=0;
        for (auto& i:merge) {            
            res+=s.substr(end, i.first-end);
            res+="<b>";
            res+=s.substr(i.first, i.second-i.first);
            res+="</b>";
            end=i.second;
        }
        res+=s.substr(end);
        
        return res;
    }
};

