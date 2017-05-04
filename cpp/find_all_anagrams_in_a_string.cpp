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
    bool isAnagram(vector<int>& count) {
        for (int i=0; i<count.size(); i++) {
            if (count[i]!=0) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m=s.size(), n=p.size();
        vector<int> count(26);
        for (auto c:p) count[c-'a']++;

        for (int i=0; i<m; i++) {
            count[s[i]-'a']--;
            if (i>=n) count[s[i-n]-'a']++;
            if (i>=n-1) {
                if (isAnagram(count)) res.push_back(i-n+1);
            }
        }
        
        return res;
    }
};

2. Sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m=s.size(), n=p.size();
        vector<int> mp(26);
        for (auto c:p) mp[c-'a']++;
        int count=0;

        for (int l=0, r=0; r<m; r++) {
            mp[s[r]-'a']--;
            if (mp[s[r]-'a']>=0) count++;
        
            if (r-l==n) {
                mp[s[l]-'a']++;
                if (mp[s[l]-'a']>0) count--;
                l++;
            }
            if (count==n) res.push_back(l);
        }
        
        return res;
    }
};

3. Sliding window with optimization
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m=s.size(), n=p.size();
        vector<int> count(128);
        for (auto c:p) count[c]++;
        vector<int> curr=count;
        
        for (int l=0, r=0; r<m;) {
            if (count[s[r]]==0) {
                curr=count;
                r++;
                l=r;
            } else {
                curr[s[r]]--;
                while (curr[s[r]]<0) {
                    curr[s[l]]++;
                    l++;
                }
                if (r-l+1==n) res.push_back(l);
                r++;
            }
        }
        return res;
    }
};

