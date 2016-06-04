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
    void dfs(string& low, string& high, string& str, int left, int right) {
        if (left>right) {
            long lowint=atol(low.c_str());
            long highint=atol(high.c_str());
            long strint=atol(str.c_str());
            if (lowint<=strint && strint<=highint) {
                count++;
            }

            return;
        }

        for (int i=0; i<l.size(); i++) {
            str[left]=l[i];
            str[right]=r[i];
            if (str.size()>1 && str[0]=='0') continue;
            if (left<right || l[i]==r[i]) {
                dfs(low, high, str, left+1, right-1);
            }
        }
    }

    int strobogrammaticInRange(string low, string high) {
        l="01689";
        r="01986";
        count=0;

        for (int i=low.size(); i<=high.size(); i++) {
            string str(i, 'a');
            dfs(low, high, str, 0, i-1);
        }

        return count;
    }
private:
    string l, r;
    int count;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
