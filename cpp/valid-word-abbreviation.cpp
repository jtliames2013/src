408. Valid Word Abbreviation
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m=word.size(), n=abbr.size();
        int i=0, j=0;
        for (; i<m && j<n; ) {
            if (isalpha(abbr[j])) {
                if (abbr[j]!=word[i]) return false;
                i++;
                j++;
            } else if (isdigit(abbr[j])) {
                int k=j;
                while (k<n && isdigit(abbr[k])) k++;
                if (abbr[j]=='0') return false;
                i+=stoi(abbr.substr(j, k-j));
                j=k;
            }
        }
        
        return i==m && j==n;
    }
};

