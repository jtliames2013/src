917. Reverse Only Letters
Easy

161

20

Favorite

Share
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l=0, r=S.size()-1;
        while (l<r) {
            if (!isalpha(S[l])) l++;
            else if (!isalpha(S[r])) r--;
            else swap(S[l++], S[r--]);
        }
        
        return S;
    }
};

