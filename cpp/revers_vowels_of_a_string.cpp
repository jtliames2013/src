Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 

class Solution {
public:
    bool isVowel(char c) {
        return (c=='a' || c=='i' || c=='e' || c=='o' || c=='u' ||
                c=='A' || c=='I' || c=='E' || c=='O' || c=='U');
    }
    string reverseVowels(string s) {
        int size=s.size();
        if (size==0) return s;
        int l=0, r=size-1;
        while (l<r) {
            if (!isVowel(s[l])) {
                l++;
                continue;
            }
            if (!isVowel(s[r])) {
                r--;
                continue;
            }
            char tmp;
            tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
            l++;
            r--;
        }
        return s;
    }
};
