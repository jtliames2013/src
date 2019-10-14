1189. Maximum Number of Balloons
Easy

72

15

Favorite

Share
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.

class Solution {
public:
    int maxNumberOfBalloons(string text) {        
        vector<int> count(26);
        for (auto c:text) count[c-'a']++;
        return min({count['a'-'a'], count['b'-'a'], count['l'-'a']/2, count['n'-'a'], count['o'-'a']/2});
    }
};
