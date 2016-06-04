// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

// NOTE: count frequency and dfs

class Solution {
public:
    void dfs(vector<string>& res, string& palin, int length, vector<int>& count) {
        if (palin.size()==length) {
            res.push_back(palin);
        }

        for (int i=0; i<count.size(); i++) {
            if (count[i]>=2) {
                palin = (char)i + palin + (char)i;
                count[i]-=2;
                dfs(res, palin, length, count);
                count[i]+=2;
                palin=palin.substr(1, palin.size()-2);
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        vector<string> res;
        string palin;
        vector<int> charCount(256);
        int oddIdx=INT_MAX;
        for (int i=0; i<s.size(); i++) {
            charCount[s[i]]++;
        }

        for (int i=0; i<256; i++) {
            if (charCount[i]%2==1) {
                if (oddIdx==INT_MAX) {
                    oddIdx=i;
                } else {
                    return res;
                }
            }
        }

        if (oddIdx!=INT_MAX) {
            palin.push_back(oddIdx);
            charCount[oddIdx]--;
        }

        dfs(res, palin, s.size(), charCount);

        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
