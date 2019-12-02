466. Count The Repetitions Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2741
Total Submissions: 10246
Difficulty: Hard
Contributors:
HappyPlay
Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.

Example:

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming

It's easy to come up with a brute force solution and to find that there will be a repetitive pattern when matching S2 through S1. The only problem is how to use the repetitive pattern to save computation.

Fact:
If s2 repeats in S1 R times, then S2 must repeats in S1 R / n2 times.
Conclusion:
We can simply count the repetition of s2 and then divide the count by n2.

How to denote repetition:
We need to scan s1 n1 times. Denote each scanning of s1 as a s1 segment.
After each scanning of i-th s1 segment, we will have

The accumulative count of s2 repeated in this s1 segment.
A nextIndex that s2[nextIndex] is the first letter you'll be looking for in the next s1 segment.
Suppose s1="abc", s2="bac", nextIndex will be 1; s1="abca", s2="bac", nextIndex will be 2
It is the nextIndex that is the denotation of the repetitive pattern.

Example:

Input:
s1="abacb", n1=6
s2="bcaa", n2=1

Return:
3
                    0  1   2 3 0      1    2 3 0      1    2 3 0  
S1 --------------> abacb | abacb | abacb | abacb | abacb | abacb 
repeatCount ----->    0  |   1   |   1   |   2   |   2   |   3
Increment of 
repeatCount     ->    0  |   1   |   0   |   1   |   0   |   1
nextIndex ------->    2  |   1   |   2   |   1   |   2   |   1
The nextIndex has s2.size() possible values, ranging from 0 to s2.size() - 1. Due to PigeonHole principle, you must find two same nextIndex after scanning s2.size() + 1 s1 segments.

Once you meet a nextIndex you've met before, you'll know that the following nextIndexs and increments of repeatCount will repeat a pattern.

So let's separate the s1 segments into 3 parts:

the prefix part before repetitive pattern
the repetitive part
the suffix part after repetitive pattern (incomplete repetitive pattern remnant)
All you have to do is add up the repeat counts of the 3 parts.


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(s2.size()+1), nextIndex(s2.size()+1);
        int cnt=0, i=0, j=0, k;
        for (k=1; k<=n1; k++) {
            for (i=0; i<s1.size(); i++) {
                if (s1[i]==s2[j]) {
                    j++;
                    if (j==s2.size()) {
                        j=0;
                        cnt++;
                    }
                }
            }
            repeatCount[k]=cnt;
            nextIndex[k]=j;
            for (int start=0; start<k; start++) {
                if (nextIndex[start]==j) {
                    // found the repetition
                    int prefixCount=repeatCount[start];
                    int patternCount=(repeatCount[k]-repeatCount[start])*((n1-start)/(k-start));
                    int suffixCount=repeatCount[start+(n1-start)%(k-start)]-repeatCount[start];
                    return (prefixCount+patternCount+suffixCount)/n2;
                }
            }   
        }
        return repeatCount[n1]/n2;
    }
};

