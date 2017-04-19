93. Restore IP Addresses  QuestionEditorial Solution  My Submissions
Total Accepted: 63242 Total Submissions: 257742 Difficulty: Medium
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    void dfs(vector<string>& res, string& s, string& ip, int start, int numAddr) {
        if (numAddr==4) {
            if (start==s.size()) {
                res.push_back(ip);
            }
            return;
        }    
        
        for (int i=start; i<s.size() && i<=start+2; i++) {
            int num=0;
            for (int j=start; j<=i; j++) {
                num*=10;
                num+=s[j]-'0';
            }
            if (num<=255 && (i==start||s[start]!='0')) {
                int len=ip.size();
                if (ip!="") ip+=".";
                ip+=s.substr(start, i-start+1);
                dfs(res, s, ip, i+1, numAddr+1);
                ip.erase(len);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(res, s, ip, 0, 0);
        
        return res;
    }
};

