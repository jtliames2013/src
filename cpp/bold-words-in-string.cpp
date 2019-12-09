758. Bold Words in String
Easy

113

62

Favorite

Share
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.

Google
|
LeetCode

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        int n=S.size();
        vector<bool> bold(n);
        for (auto& w:words) {
            int m=w.size();
            for (int i=0; i<n; ++i) {
                if ((i=S.find(w, i))==string::npos) break;
                fill(bold.begin()+i, bold.begin()+i+m, true);
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (bold[i] && (i==0 || bold[i-1]==false)) res+="<b>";
            res+=S[i];
            if (bold[i] && (i==n-1 || bold[i+1]==false)) res+="</b>";            
        }
        return res;
    }
};

