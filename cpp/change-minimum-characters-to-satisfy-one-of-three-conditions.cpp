1737. Change Minimum Characters to Satisfy One of Three Conditions
Medium

74

136

Add to List

Share
You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.
Return the minimum number of operations needed to achieve your goal.

 

Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).
Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".
 

Constraints:

1 <= a.length, b.length <= 105
a and b consist only of lowercase letters.

class Solution {
public:
    int minCharacters(string a, string b) {
        int m=a.size(), n=b.size(), res=m+n;
        vector<int> cnt1(26), cnt2(26);
        for (auto& c:a) cnt1[c-'a']++;
        for (auto& c:b) cnt2[c-'a']++;
        
        for (int i=0; i<26; ++i) {
            res=min(res, m+n-cnt1[i]-cnt2[i]);
            if (i>0) {
                cnt1[i]+=cnt1[i-1];
                cnt2[i]+=cnt2[i-1];                
            }
            if (i<25) {
                // all chars in a is less than or equal to the current char 
                // all chars in b is greater than the current char
                res=min(res, m-cnt1[i]+cnt2[i]);
                res=min(res, n-cnt2[i]+cnt1[i]);
            }
        }
        return res;
    }
};

