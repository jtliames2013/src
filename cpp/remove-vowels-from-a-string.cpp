1119. Remove Vowels from a String
Easy

39

59

Favorite

Share
Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
Example 2:

Input: "aeiou"
Output: ""
 

Note:

S consists of lowercase English letters only.
1 <= S.length <= 1000

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Amazon
|
LeetCode

class Solution {
public:
    string removeVowels(string S) {
        string res;
        for (auto c:S) {
            if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u') res+=c;
        }
        
        return res;
    }
};

