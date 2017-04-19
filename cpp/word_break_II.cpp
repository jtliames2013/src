140. Word Break II 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

Hide Company Tags Dropbox Google Uber Snapchat Twitter
Hide Tags Dynamic Programming Backtracking

class Solution {
public:
    string convert(vector<string>& output) {
        string res;
        for (int i=0; i<output.size(); i++) {
            if (i>0) res+=" ";
            res+=output[i];
        }
        return res;
    }
    
    bool wordBreak(vector<string>& res, string& s, unordered_set<string>& dict, vector<bool>& canBreak, vector<string>& output, int start) {
        if (start==s.size()) {
            res.push_back(convert(output));
            return true;
        }
        
        bool b=false;
        for (int i=start; i<s.size(); i++) {
            if (canBreak[i+1]) {
                string str=s.substr(start, i-start+1);
                output.push_back(str);
                if (dict.find(str)!=dict.end()) {
                    if (wordBreak(res, s, dict, canBreak, output, i+1)) {
                        b=true;
                    } else {
                        canBreak[i+1]=false;
                    }
                }
                output.pop_back();
            }        
        }
        return b;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        int n=s.size();
        if (n==0) return res;
        unordered_set<string> dict;
        for (auto w:wordDict) dict.insert(w);
        vector<string> output;
        vector<bool> canBreak(n+1, true);
        
        wordBreak(res, s, dict, canBreak, output, 0);
        
        return res;
    }
};

2. Memoization
class Solution {
public:
    vector<string> wordBreak(string& s, unordered_set<string>& dict, unordered_map<string, vector<string>>& mp, int start) {
        vector<string> res;
        if (start==s.size()) {
            res.push_back("");
            return res;
        }
        
        for (int i=start; i<s.size(); i++) {
            string str=s.substr(start, i-start+1);
            if (dict.find(str)!=dict.end()) {
                vector<string> subres;
                if (mp.find(s.substr(i+1))!=mp.end()) {
                    subres=mp[s.substr(i+1)];
                } else {
                    subres=wordBreak(s, dict, mp, i+1);
                }        
                for (auto words:subres) {
                    if (words=="") res.push_back(str);
                    else res.push_back(str+" "+words);
                }
            }
        }
        mp[s.substr(start)]=res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        int n=s.size();
        if (n==0) return res;
        unordered_set<string> dict;
        for (auto w:wordDict) dict.insert(w);
        unordered_map<string, vector<string>> mp;
        
        return wordBreak(s, dict, mp, 0);
    }
};

