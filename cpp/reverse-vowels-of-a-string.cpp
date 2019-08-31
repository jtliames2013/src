345. Reverse Vowels of a String Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 71228
Total Submissions: 187604
Difficulty: Easy
Contributor: LeetCode
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

Subscribe to see which companies asked this question.

Hide Tags Two Pointers String
Hide Similar Problems (E) Reverse String

class Solution {
public:
    string reverseVowels(string s) {        
        int l=0, r=s.size()-1;
        while (l<r) {
            if (!isVowel(s[l])) l++;
            else if (!isVowel(s[r])) r--;
            else {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return (c=='a' || c=='i' || c=='e' || c=='o' || c=='u' ||
                c=='A' || c=='I' || c=='E' || c=='O' || c=='U');
    }
};
