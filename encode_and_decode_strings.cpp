// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";

        for (auto s:strs){
            res += s + '\0';
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int start=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='\0') {
                res.push_back(s.substr(start, i-start));
                start=i+1;
            }
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
