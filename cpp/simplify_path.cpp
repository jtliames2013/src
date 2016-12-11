#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> v;
        string res;
        string val;
        while (getline(iss, val, '/')) {
            if (val!="." && val!=".." &&!val.empty()) {
                v.push_back(val);
            } else if (val=="..") {
                if (v.size()>0) {
					// v.pop_back();
                    v.erase(v.end()-1, v.end());
                }
            }
        }
        
        if (v.size()==0) return "/";
        for (int i=0; i<v.size(); i++) {
            res+="/"+v[i];
        }
       
        return res;
    }
};

int main()
{
	return 0;
}


