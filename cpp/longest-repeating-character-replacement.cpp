424. Longest Repeating Character Replacement Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 10065
Total Submissions: 24263
Difficulty: Medium
Contributor: LeetCode
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
Subscribe to see which companies asked this question.

Hide Similar Problems (H) Longest Substring with At Most K Distinct Characters

Since we are only interested in the longest valid substring, our sliding windows need not shrink, even if a window may cover an invalid substring. We either grow the window by appending one char on the right, or shift the whole window to the right by one. And we only grow the window when the count of the new char exceeds the historical max count (from a previous window that covers a valid substring).

That is, we do not need the accurate max count of the current window; we only care if the max count exceeds the historical max count; and that can only happen because of the new char.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> count(26);
        int maxCount=0, l=0, r=0;
        for (; r<n; r++) {
            count[s[r]-'A']++;
            // maxCount is not nessarily the maximum count in the sliding window
            maxCount=max(maxCount, count[s[r]-'A']);
            while (r-l+1-maxCount>k) {
                count[s[l]-'A']--;
                l++;
            }
        }
        
        return n-l;
    }
};

