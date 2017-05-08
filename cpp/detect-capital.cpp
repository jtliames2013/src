520. Detect Capital Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 20970
Total Submissions: 39911
Difficulty: Easy
Contributors:
love_Fawn
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

Subscribe to see which companies asked this question.

Hide Tags String

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for (int i=0; i<word.size(); i++) {
            if (isupper(word[i])) count++;
        }
        
        return count==0 || count==word.size() || (count==1 && isupper(word[0]));
    }
};

