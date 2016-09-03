// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(string& s, int start, int end) {
        while (start<end) {
            char tmp=s[start];
            s[start]=s[end];
            s[end]=tmp;
            start++;
            end--;
        }
    }

    void reverseWords(string &s) {
        int size=s.size();
        reverseString(s, 0, size-1);

        bool start=false;
        int startIdx, endIdx;
        for (int i=0; i<size; i++) {
            if (start==false) {
                if (s[i]!=' ') {
                    start=true;
                    startIdx=i;
                }
            } else {
                if (s[i]==' ') {
                    endIdx=i;
                    start=false;
                    reverseString(s, startIdx, endIdx-1);
                }
            }
        }

        if (start) {
            reverseString(s, startIdx, size-1);
        }
    }
};

3. Use std::reverse

class Solution {
public:
    void reverseWords(string &s) {
        int size=s.size();
        bool started;
        int sIdx=0;
        
        reverse(s.begin(), s.end());
        
        for (int i=0; i<size; i++) {
            if (started) {
                if (s[i]==' ') {
                    reverse(s.begin()+sIdx, s.begin()+i);
                    started=false;
                }
            } else {
                if (s[i]!=' ') {
                    started=true;
                    sIdx=i;
                }
            }   
        }
        
        if (started) {
            reverse(s.begin()+sIdx, s.end());
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
