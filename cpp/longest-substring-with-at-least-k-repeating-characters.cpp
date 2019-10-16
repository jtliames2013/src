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

1. in the first pass I record counts of every character in a hashmap
2. in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts.
3. keep doing this recursively and the maximum of the left/right part is the answer.

class Solution {
public:
    int longestSubstring(string& s, int start, int end, int k) {
        if (s.empty()||k>end-start+1) return 0;
        
        vector<int> mp(256);
        for (int i=start; i<=end; i++) mp[s[i]]++;
        
        int i=start;
        for (; i<=end; i++) {
            if (mp[s[i]]<k) break;
        }
        if (i>end) return end-start+1;
        int l=longestSubstring(s, start, i-1, k);
        int r=longestSubstring(s, i+1, end, k);
        
        return max(l, r);
    }
    
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.size()-1, k);
    }
};

