1451. Rearrange Words in a Sentence
Medium

78

24

Add to List

Share
Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.
Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"
 

Constraints:

text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5

class Solution {
public:
    string arrangeWords(string text) {
        string res;
        map<int, vector<string>> mp;
        int n=text.size();
        for (int i=0; i<n; ) {
            if (text[i]!=' ') {
                int j=i;
                while (j<n && text[j]!=' ') j++;
                string w=text.substr(i, j-i);
                if (i==0) w[0]=tolower(w[0]);
                mp[j-i].push_back(w);
                i=j;
            } else {
                i++;
            }
        }
        for (auto iter:mp) {
            for (auto w:iter.second) {
                if (res.empty()) w[0]=toupper(w[0]);
                else res+=" ";
                res+=w;
            }
        }
        return res;
    }
};

