248. Strobogrammatic Number III
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.

Google
|
2

Facebook
|
3

class Solution {
public:
    void dfs(long low, long high, string& str, int start, int end) {
        if (start>end) {
            long n=stol(str);
            if (n>=low && n<=high) count++;
            return;
        }
        
        for (int i=0; i<l.size(); i++) {
            str[start]=l[i];
            str[end]=r[i];
            if (str.size()>1 && str[0]=='0') continue;
            if (start==end && l[i]!=r[i]) continue;
            dfs(low, high, str, start+1, end-1);
        }
    }
    
    int strobogrammaticInRange(string low, string high) {
        count=0;
        long l=stol(low), h=stol(high);        
        for (int i=low.size(); i<=high.size(); i++) {
            string str(i, 0);
            dfs(l, h, str, 0, i-1);
        }
        
        return count;
    }
private:
    string l="01689";
    string r="01986";
    int count;
};

