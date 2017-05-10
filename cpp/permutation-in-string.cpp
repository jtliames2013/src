567. Permutation in String Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 3297
Total Submissions: 9038
Difficulty: Medium
Contributors:
fallcreek
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
Subscribe to see which companies asked this question.

Hide Tags Two Pointers
Hide Similar Problems (H) Minimum Window Substring (E) Find All Anagrams in a String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<int> count(128);
        for (auto c:s1) count[c]++;
        vector<int> curr=count;
        
        for (int l=0, r=0; r<n; ) {
            if (count[s2[r]]==0) {
                r++;
                l=r;
                curr=count;
            } else {
                curr[s2[r]]--;
                while (curr[s2[r]]<0) {
                    curr[s2[l]]++;
                    l++;
                }
                if (r-l+1==m) return true;
                r++;
            }
        }
        
        return false;
    }
};

