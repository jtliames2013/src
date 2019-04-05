1002. Find Common Characters
Easy

151

19

Favorite

Share
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int n=A[0].size();
        vector<int> cnt(26);
        for (int i=0; i<n; ++i) cnt[A[0][i]-'a']++;
        
        for (int j=1; j<A.size(); ++j) {
            vector<int> c(26);
            for (int i=0; i<n; ++i) c[A[j][i]-'a']++;
            for (int i=0; i<26; ++i) cnt[i]=min(cnt[i], c[i]);
        }
        
        for (int i=0; i<26; ++i) {
            for (int j=0; j<cnt[i]; ++j) res.push_back(string(1, i+'a'));
        }
        return res;
    }
};
