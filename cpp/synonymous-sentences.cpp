1258. Synonymous Sentences
Medium

33

17

Favorite

Share
Given a list of pairs of equivalent words synonyms and a sentence text, Return all possible synonymous sentences sorted lexicographically.
 

Example 1:

Input:
synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
text = "I am happy today but was sad yesterday"
Output:
["I am cheerful today but was sad yesterday",
​​​​​​​"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"]
 

Constraints:

0 <= synonyms.length <= 10
synonyms[i].length == 2
synonyms[0] != synonyms[1]
All words consist of at most 10 English letters only.
text is a single space separated sentence of at most 10 words.

Cruise Automation
|
LeetCode

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> res;
        unordered_map<string, int> mp;
        vector<set<string>> connected;
        for (auto& s:synonyms) {
            if (mp.find(s[0])==mp.end() && mp.find(s[1])==mp.end()) {
                mp[s[0]]=mp[s[1]]=connected.size();
                connected.push_back({s[0], s[1]});                
            } else if (mp.find(s[0])==mp.end()) {
                connected[mp[s[1]]].insert(s[0]);
            } else if (mp.find(s[1])==mp.end()) {
                connected[mp[s[0]]].insert(s[1]);
            }
        }
        
        istringstream iss(text);
        string val;
        vector<string> words, output;
        while (iss>>val) words.push_back(val);
        
        dfs(res, mp, connected, words, output, 0);
        return res;
    }
private:
    void dfs(vector<string>& res, unordered_map<string, int>& mp, vector<set<string>>& connected, vector<string>& words, vector<string>& output, int start) {
        if (start==words.size()) {
            res.push_back(convert(output));
            return;
        }
        
        if (mp.find(words[start])==mp.end()) {
            output.push_back(words[start]);
            dfs(res, mp, connected, words, output, start+1);
            output.pop_back();
        } else {
            for (auto& w:connected[mp[words[start]]]) {
                output.push_back(w);
                dfs(res, mp, connected, words, output, start+1);
                output.pop_back();
            }
        }
    }
  
    string convert(vector<string>& v) {
        string res;
        for (int i=0; i<v.size(); ++i) {
            if (i>0) res+=" ";
            res+=v[i];
        }
        return res;
    }
};

