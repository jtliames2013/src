784. Letter Case Permutation
DescriptionHintsSubmissionsDiscussSolution
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.

class Solution {
public:
    vector<char> getChars(char c) {
        if (isalpha(c)) {
            return {tolower(c), toupper(c)};
        } else {
            return { c };
        }
    }
    
    void dfs(vector<string>& res, string& output, string& S, int start) {
        if (start==S.size()) {
            res.push_back(output);
            return;
        }

        vector<char> v=getChars(S[start]);
        for (auto c:v) {
            output.push_back(c);
            dfs(res, output, S, start+1);
            output.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string output;
        dfs(res, output, S, 0);
        
        return res;
    }
};
