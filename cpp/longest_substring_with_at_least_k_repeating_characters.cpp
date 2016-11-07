395. Longest Substring with At Least K Repeating Characters QuestionEditorial Solution  My Submissions
Total Accepted: 5982 Total Submissions: 17340 Difficulty: Medium Contributors: Admin
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

class Solution {
public:
    void getLongest(string& s, int left, int right, int k, int& longest) {
        int table[26]={0};
        for (int i=left; i<=right; i++) table[s[i]-'a']++;
        
        int start=left;
        for (int i=left; i<=right; i++) {
            if (table[s[i]-'a']<k) {
				// find each split point
                if (start!=i) {
                    getLongest(s, start, i-1, k, longest);
                }
                start=i+1;
            }
        }
        
        if (start==left) {
            longest=max(longest, right-left+1);
        } else if (start<=right) {
            getLongest(s, start, right, k, longest);
        }
    }
    int longestSubstring(string s, int k) {
        int longest=0;
        if (s.empty()) return 0;
        
        getLongest(s, 0, s.size()-1, k, longest);
        return longest;
    }
};

