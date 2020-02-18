1087. Brace Expansion
Medium

150

16

Favorite

Share
A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

 

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: "abcd"
Output: ["abcd"]
 

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.

Google
|
6

1. Bottom-up dfs
class Solution {
public:
    vector<string> expand(string S) {
        return dfs(S, 0);
    }
private:
    vector<string> dfs(string& S, int start) {
        if (start==S.size()) return  { "" };
        set<string> st;
        int end;
        vector<string> strs;
        if (S[start]=='{') {
            end=++start;
            while (end<S.size() && S[end]!='}') end++;
            strs=dfs(S, end+1);
        } else {
            end=start+1;
            strs=dfs(S, end);
        }         
        for (int i=start; i<end; i+=2) { // skip ","
            for(auto& str:strs) {
                st.insert(S[i]+str);
            }
        }
        
        return vector<string>(st.begin(), st.end());
    }
};

2. Top-down dfs
class Solution {
public:
    vector<string> expand(string S) {
        vector<string> res;
        string output;
        int n=S.size();
        vector<set<char>> letters;
        for (int i=0; i<n; ) {
            if (S[i]=='{') {
                i++; //'{'
                letters.push_back({});
                while (i<n-1) {
                    letters.back().insert(S[i]);
                    i++;
                    if (S[i]=='}') break;
                    else i++;
                }
                i++; // '}'
            } else {
                letters.push_back({S[i]});
                i++;
            }
        }
        dfs(res, output, letters, 0);
        return res;
    }
private:
    void dfs(vector<string>& res, string& output, vector<set<char>>& letters, int start) {
        if (start==letters.size()) {
            res.push_back(output);
            return;
        }

        for (auto c:letters[start]) {
            output.push_back(c);
            dfs(res, output, letters, start+1);
            output.pop_back();
        }
    }
};

