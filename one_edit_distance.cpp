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

// NOTE: scan from start and scan from end. note the case when two strings are the same

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sStart=0, tStart=0;
        int sEnd=s.size()-1, tEnd=t.size()-1;

        while (sStart < s.size() && tStart < t.size()) {
            if (s[sStart]!=t[tStart]) break;
            sStart++;
            tStart++;
        }

        while (sEnd>=0 && tEnd>=0) {
            if (s[sEnd]!=t[tEnd]) break;
            sEnd--;
            tEnd--;
        }

        if (sEnd-sStart > 0 || tEnd-tStart> 0 || (sEnd-sStart<=-1 && tEnd-tStart<=-1)) return false;
        else return true;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
