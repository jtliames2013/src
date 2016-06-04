// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, string& str, int strlen, int left, int right) {
        if (left>right) {
            res.push_back(str);
            return;
        }
        
        for (int i=0; i<l.size(); i++) {
            str[left]=l[i];
            str[right]=r[i];
            if (strlen>1 && str[0]=='0') continue;
            if (left<right || l[i]==r[i]) {
                dfs(res, str, strlen, left+1, right-1);
            }
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        l="01689";
        r="01986";
        string str(n, 'a');
        vector<string> res;
        dfs(res, str, n, 0, n-1);
        
        return res;
    }
private:
    string l, r;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
