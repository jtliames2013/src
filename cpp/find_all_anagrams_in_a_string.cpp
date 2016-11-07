438. Find All Anagrams in a String   QuestionEditorial Solution  My Submissions
Total Accepted: 4300 Total Submissions: 12874 Difficulty: Easy Contributors: Stomach_ache
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
Subscribe to see which companies asked this question

Hide Tags Hash Table
Hide Similar Problems (E) Valid Anagram

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char,int> count;
        int total=0;
        for (auto c:p) {
            count[c]++;
            total++;
        }
        int m=s.size(), n=p.size();

        map<char,int> cnt=count;
        int t=0;
        for (int l=0, r=0; r<m;) {
            if (count.find(s[r])==count.end()) {
                cnt=count;
                t=0;
                r++;
                l=r;
            } else {
                if (cnt[s[r]]>0) t++;
                cnt[s[r]]--;
                if (r-l+1>n) {
                    cnt[s[l]]++;
                    if (cnt[s[l]]>0) t--;
                    l++;
                }
                if (t==total) {
                    res.push_back(l);
                }
                r++;
            }
        }
        return res;
    }
};


