524. Longest Word in Dictionary through Deleting Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 6382
Total Submissions: 15492
Difficulty: Medium
Contributors:
love_Fawn
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
Subscribe to see which companies asked this question.

Hide Tags Two Pointers Sort

1.
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res="";
        for (auto w:d) {
            int i=0;
            for (auto c:s) {
                if (c==w[i]) i++;
            }
            
            if (i==w.size()) {
                if (w.size()>res.size() || (w.size()==res.size() && w<res)) {
                    res=w;
                }
            }
        }
        
        return res;
    }
};

2. Sort
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string& a, string& b) { return a.size()>b.size() || (a.size()==b.size() && a<b); });
        for (auto w:d) {
            int i=0;
            for (auto c:s) {
                if (c==w[i]) i++;
            }
            if (i==w.size()) return w;
        }
        return "";   
    }
};

