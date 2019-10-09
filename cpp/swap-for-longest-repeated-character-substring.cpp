1156. Swap For Longest Repeated Character Substring
Medium

108

7

Favorite

Share
Given a string text, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.

 

Example 1:

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.
Example 2:

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.
Example 3:

Input: text = "aaabbaaa"
Output: 4
Example 4:

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.
Example 5:

Input: text = "abcdef"
Output: 1
 

Constraints:

1 <= text.length <= 20000
text consist of lowercase English characters only.

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<int>> index(26);
        int n=text.size(), res=0;
        for (int i=0; i<n; ++i) index[text[i]-'a'].push_back(i);
        for (int i=0; i<26; ++i) {
            int curr=1, prev=0, len=0;
            for (int j=1; j<index[i].size(); ++j) {
                if (index[i][j]==index[i][j-1]+1) curr++;
                else if (index[i][j]==index[i][j-1]+2) {
                    prev=curr;
                    curr=1;
                } else {
                    prev=0;
                    curr=1;
                }
                len=max(len, prev+curr);
            }
            // if not all letters are used, we can swap for one more
            // otherwise we can't swap for one more
            res=max(res, len+(index[i].size()>len?1:0));
        }
        return res;
    }
};
