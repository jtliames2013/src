// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

//We can solve this problem using backtracking, we just have to keep trying to use a character in the pattern to match different length of substrings in the input string, keep trying till we go through the input string and the pattern.
//
//For example, input string is "redblueredblue", and the pattern is "abab", first let's use 'a' to match "r", 'b' to match "e", then we find that 'a' does not match "d", so we do backtracking, use 'b' to match "ed", so on and so forth ...
//
//When we do the recursion, if the pattern character exists in the hash map already, we just have to see if we can use it to match the same length of the string. For example, let's say we have the following map:
//
//'a': "red"
//
//'b': "blue"
//
//now when we see 'a' again, we know that it should match "red", the length is 3, then let's see if str[i ... i+3] matches 'a', where i is the current index of the input string. Thanks to StefanPochmann's suggestion, in Java we can elegantly use str.startsWith(s, i) to do the check.
//
//Also thanks to i-tikhonov's suggestion, we can use a hash set to avoid duplicate matches, if character a matches string "red", then character b cannot be used to match "red". In my opinion though, we can say apple (pattern 'a') is "fruit", orange (pattern 'o') is "fruit", so they can match the same string, anyhow, I guess it really depends on how the problem states.
//
//The following code should pass OJ now, if we don't need to worry about the duplicate matches, just remove the code that associates with the hash set.

class Solution {
public:
    bool findMatch(string& pattern, int pIdx, string& str, int sIdx, map<char, string>& m, unordered_set<string>& words) {
        if (pIdx==pattern.size() && sIdx==str.size()) return true;
        else if (pIdx==pattern.size() || sIdx==str.size()) return false;

        char currChar=pattern[pIdx++];
        int end=str.size()-(pattern.size()-pIdx);
        for (int i=sIdx; i<end; i++) {
            string currWord=str.substr(sIdx, i-sIdx+1);
            if (m.find(currChar)==m.end()) {
                if (words.find(currWord)==words.end()) {
                    m[currChar]=currWord;
                    words.insert(currWord);
                    if (findMatch(pattern, pIdx, str, i+1, m, words)==true) return true;
                    words.erase(currWord);
                    m.erase(currChar);
                }
            } else {
                if (currWord==m[currChar]) {
                    if (findMatch(pattern, pIdx, str, i+1, m, words)==true) return true;
                }
            }
        }

        return false;
    }

    bool wordPatternMatch(string pattern, string str) {
        map<char, string> m;
        unordered_set<string> words;

        return findMatch(pattern, 0, str, 0, m, words);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
