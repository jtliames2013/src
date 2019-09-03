318. Maximum Product of Word Lengths 
 Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:

Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words. 

use bit to represent each letter. use a & b compare.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        if (n==0) return 0;
        int len=0;
        vector<int> nums(n);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<words[i].size(); j++) {
                nums[i]|= (1<<words[i][j]-'a');
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if ((nums[i] & nums[j])==0) len=max(len, (int)(words[i].size()*words[j].size()));
            }
        }
        return len;
    }
};

