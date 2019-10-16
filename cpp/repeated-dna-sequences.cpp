187. Repeated DNA Sequences Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 71144
Total Submissions: 232844
Difficulty: Medium
Contributor: LeetCode
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
Subscribe to see which companies asked this question.

Hide Tags Hash Table Bit Manipulation

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<char,int> dict={{'A',0}, {'C',1}, {'G',2}, {'T',3}};
        unordered_map<int,int> mp;
        int num=0;
        for (int i=0; i<s.size(); i++) {
            num = ((num<<2) | dict[s[i]]) & 0xfffff;
            if (i>=9) {
                if (mp[num]==1) res.push_back(s.substr(i-9,10));
                mp[num]++;
            }
        }

        return res;
    }
};

