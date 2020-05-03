1433. Check If a String Can Break Another String
Medium

24

10

Add to List

Share
Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa (in other words s2 can break s1).

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

 

Example 1:

Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
Example 2:

Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
Example 3:

Input: s1 = "leetcodee", s2 = "interview"
Output: true
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.

1.
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool diff=false, small;
        for (int i=0; i<n; ++i) {
            if (s1[i]==s2[i]) continue;
            if (!diff) {
                small=s1[i]<s2[i];
                diff=true;
            }
            if ((small && s1[i]>s2[i]) || (!small && s1[i]<s2[i])) return false;
        }
        return true;
    }
};

2.
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> c1(26), c2(26);
        for (auto c:s1) c1[c-'a']++;
        for (auto c:s2) c2[c-'a']++;
        return smaller(c1, c2) || smaller(c2, c1);
    }
private:
    bool smaller(vector<int>& c1, vector<int>& c2) {
        int res=0;
        for (int i=0; i<26; ++i) {
            res+=c1[i]-c2[i];
            if (res>0) return false;
        }
        return true;
    }
};

