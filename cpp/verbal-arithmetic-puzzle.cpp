1307. Verbal Arithmetic Puzzle
Hard

80

33

Add to List

Share
Given an equation, represented by words on left side and the result on right side.

You need to check if the equation is solvable under the following rules:

Each character is decoded as one digit (0 - 9).
Every pair of different characters they must map to different digits.
Each words[i] and result are decoded as one number without leading zeros.
Sum of numbers on left side (words) will equal to the number on right side (result). 
Return True if the equation is solvable otherwise return False.

 

Example 1:

Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
Example 2:

Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
Example 3:

Input: words = ["THIS","IS","TOO"], result = "FUNNY"
Output: true
Example 4:

Input: words = ["LEET","CODE"], result = "POINT"
Output: false
 

Constraints:

2 <= words.length <= 5
1 <= words[i].length, results.length <= 7
words[i], result contains only upper case English letters.
Number of different characters used on the expression is at most 10.

Atlassian
|
LeetCode

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        int n=result.size();
        for (auto& w:words) {
            if (w.size()>n) return false;
        }
        for (auto& w:words) reverse(w.begin(), w.end());
        reverse(result.begin(), result.end());
        return dfs(words, result, 0, 0, 0, n);
    }
private:
    int dfs(vector<string>& words, string& result, int wordIdx, int sum, int start, int n) { 
        if (start==n) {
            return sum==0;
        }
        
        if (wordIdx==words.size()) {
            if (c2i.find(result[start])==c2i.end() && i2c.find(sum%10)==i2c.end()) {
                c2i[result[start]]=sum%10;
                i2c[sum%10]=result[start];                
                bool b=dfs(words, result, 0, sum/10, start+1, n);
                c2i.erase(result[start]);
                i2c.erase(sum%10);
                return b;
            } else if (c2i.find(result[start])!=c2i.end() && c2i[result[start]]==sum%10) {
                return dfs(words, result, 0, sum/10, start+1, n);
            } else {
                return false;
            }
        }
        
        if (start>=words[wordIdx].size()) return dfs(words, result, wordIdx+1, sum, start, n);
        
        if (c2i.find(words[wordIdx][start])!=c2i.end()) {
            if (start==words[wordIdx].size()-1 && words[wordIdx].size()>1 && c2i[words[wordIdx][start]]==0) {
                // no leading zeros
                return false;
            } else {
                return dfs(words, result, wordIdx+1, sum+c2i[words[wordIdx][start]], start, n);
            }                
        }
        
        for (int i=0; i<10; ++i) {
            // no leading zeros
            if (start==words[wordIdx].size()-1 && words[wordIdx].size()>1 && i==0) continue;
            if (i2c.find(i)!=i2c.end()) continue;
            c2i[words[wordIdx][start]]=i;
            i2c[i]=words[wordIdx][start];
            bool b=dfs(words, result, wordIdx+1, sum+i, start, n);
            c2i.erase(words[wordIdx][start]);
            i2c.erase(i);
            if (b) return true;
        }
        return false;
    }
    
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
};

