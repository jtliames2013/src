320. Generalized Abbreviation  
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Hide Company Tags Google
Hide Tags Backtracking Bit Manipulation
Hide Similar Problems (M) Subsets (E) Unique Word Abbreviation

1.
class Solution {
public:
    void dfs(vector<string>& res, string& output, string& word, int start, bool prevNum) {
        if (start==word.size()) {
            res.push_back(output);
            return;
        }
        
        output.push_back(word[start]);
        dfs(res, output, word, start+1, false);
        output.pop_back();
        
        if (!prevNum) {
            int len=output.size();
            for (int i=start; i<word.size(); i++) {
                output+=to_string(i-start+1);
                dfs(res, output, word, i+1, true);
                output.erase(len);
            }
        }
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string output;
        dfs(res, output, word, 0, false);
        
        return res;
    }
};

2.
class Solution {
public:
    void dfs(vector<string>& res, string& output, string& word, int start, int count) {
        if (start==word.size()) {
            int len=output.size();
            if (count>0) output+=to_string(count);
            res.push_back(output);
            output.erase(len);
            return;
        }
        
        // skip character
        dfs(res, output, word, start+1, count+1);
        // use character and previous count
        int len=output.size();
        if (count>0) output+=to_string(count);
        output+=word[start];
        dfs(res, output, word, start+1, 0);
        output.erase(len);
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string output;
        dfs(res, output, word, 0, 0);
        
        return res;
    }
};

