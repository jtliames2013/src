161. One Edit Distance  
Given two strings S and T, determine if they are both one edit distance apart.

Hide Company Tags Snapchat Uber Facebook Twitter
Hide Tags String
Hide Similar Problems (H) Edit Distance

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size(), n=t.size();
        int delta=abs(m-n), len=min(m,n);
        if (delta>1) return false;
        else if (delta==1) {
            for (int i=0; i<len; i++) {
                if (s[i]!=t[i]) {
                    return m<n?(s.substr(i)==t.substr(i+1)):(s.substr(i+1)==t.substr(i));
                }
            }
            return true;
        } else {
            int count=0;
            for (int i=0; i<m; i++) {
                if (s[i]!=t[i]) count++;
                if (count>1) return false;
            }
            return count==1;
        }
    }
};

