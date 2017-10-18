681. Next Closest Time
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

class Solution {
public:
    void dfs(string& res, vector<int>& digits, string output, int start, int curr, int& diff) {
        if (start==4) {
            int val=stoi(output.substr(0,2))*60+stoi(output.substr(2,2));
            if (val==curr) return;
            int d=val>curr?(val-curr):(val+1440-curr);
            if (d<diff) {
                diff=d;
                res=output.substr(0,2)+":"+output.substr(2,2);
            }
            return;
        }
        
        for (int i=0; i<digits.size(); i++) {
            string str=output;
            str.push_back(digits[i]+'0');
            if (start==0 && digits[i]>2) continue;
            if (start==1 && stoi(str.substr(0,2))>23) continue;
            if (start==2 && digits[i]>5) continue;
            if (start==3 && stoi(str.substr(2,2))>59) continue;
            dfs(res, digits, str, start+1, curr, diff);
        }
    }
    
    string nextClosestTime(string time) {
        string res;
        unordered_set<int> st;
        for (int i=0; i<time.size(); i++) {
            if (time[i]!=':') st.insert(time[i]-'0');
        }
        if (st.size()==1) return time;
        
        vector<int> digits(st.begin(), st.end());
        int curr=stoi(time.substr(0,2))*60+stoi(time.substr(3,2));
        string output;
        int diff=INT_MAX;
        dfs(res, digits, output, 0, curr, diff);
        
        return res;
    }
};
