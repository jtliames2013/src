93. Restore IP Addresses  QuestionEditorial Solution  My Submissions
Total Accepted: 63242 Total Submissions: 257742 Difficulty: Medium
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {        
        vector<string> res;
        string output;
        dfs(res, output, s, 0, 0);
        return res;
    }
private:
    void dfs(vector<string>& res, string& output, string& s, int start, int part) {
        if (part==4) {
            if (start==s.size()) {
                res.push_back(output);
            }
            return;
        }
        
        for (int i=start; i<s.size() && i-start+1<=3; ++i) {
            if (s[start]=='0' && i>start) break;
            string str=s.substr(start, i-start+1);
            int num=stoi(str);
            if (num>255) continue;
            
            int len=output.size();
            if (!output.empty()) output+=".";
            output+=str;
            dfs(res, output, s, i+1, part+1);
            output.erase(len);
        }
    }
};
