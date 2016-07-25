161. One Edit Distance  
Given two strings S and T, determine if they are both one edit distance apart.

Hide Company Tags Snapchat Uber Facebook Twitter
Hide Tags String
Hide Similar Problems (H) Edit Distance

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size()<t.size()) swap(s, t);
        int m=s.size();
        int n=t.size();
        int delta=m-n;
        
        if (delta>=2) return false;
        else if (delta==1) {
            for (int i=0; i<n; i++) {
                if (s[i]!=t[i]) {
                    return s.substr(i+1)==t.substr(i);
                }
            }
            return true;
        } else {
            int count=0;
            for (int i=0; i<m; i++) {
                if (s[i]!=t[i]) count++;
            }
            return count==1;
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
