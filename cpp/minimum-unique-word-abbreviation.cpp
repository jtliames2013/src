411. Minimum Unique Word Abbreviation
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:
In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").

Google
|
LeetCode

The key idea of my solution is to preprocess the dictionary to transfer all the words to bit sequences (int):
Pick the words with same length as target string from the dictionary and compare the characters with target. If the characters are different, set the corresponding bit to 1, otherwise, set to 0.
Ex: "abcde", ["abxdx", "xbcdx"] => [00101, 10001]

The problem is now converted to find a bit mask that can represent the shortest abbreviation, so that for all the bit sequences in dictionary, mask & bit sequence > 0.
Ex: for [00101, 10001], the mask should be [00001]. if we mask the target string with it, we get "****e" ("4e"), which is the abbreviation we are looking for.

To find the bit mask, we need to perform DFS with some optimizations. But which bits should be checked? We can perform "or" operation for all the bit sequences in the dictionary and do DFS for the "1" bits in the result.
Ex: 00101 | 10001 = 10101, so we only need to take care of the 1st, 3rd, and 5th bit.

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        string res;
        int n=target.size();
        minMask=0;
        minLen=INT_MAX;
        candidate=0;
        for (auto& w:dictionary) {
            if (w.size()!=n) continue;
            int b=0;
            for (int i=0; i<n; ++i) {
                if (w[i]!=target[i]) b |= (1<<(n-i-1));
            }
            bits.push_back(b);
            candidate |= b;
        }
        
        dfs(0, 0, n);
        
        for (int i=0; i<n; ) {
            if (minMask & (1<<(n-i-1))) {
                res+=target[i];
                i++;
            } else {
                int j=i;
                while (j<n && (minMask & (1<<(n-j-1)))==0) j++;
                res+=to_string(j-i);
                i=j;
            }
        }
        return res;
    }
private:
    void dfs(int start, int mask, int n) {
        int len=getLen(mask, n);
        if (len>=minLen) return;
        bool match=true;
        for (auto b:bits) {
            if ((b & mask)==0) {
                match=false;
                break;
            }
        }

        if (match) {
            minLen=len;
            minMask=mask;
        } else {
            for (int i=start; i<n; ++i) {
                if ((candidate & (1<<i))) dfs(i+1, mask | (1<<i), n);
            }
        }
    }

    int getLen(int mask, int n) {
        int res=0;
        // Note in problem statement
        // Each number or letter in the abbreviation is considered length = 1.
        for (int i=0; i<n; ) {
            if ((mask & (1<<i))==0) {
                while (i<n && ((mask & (1<<i))==0)) i++;
            } else {
                i++;
            }
            res++;
        }
        return res;
    }

    vector<int> bits;
    int minMask;
    int minLen;
    int candidate;
};

