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

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     Solution() {
         read4Idx=0;
         read4Cnt=0;
     }
     
    int read(char *buf, int n) {
        int index=0;
        while (index<n) {
            read4Cnt=read4(read4Buf);
            if (read4Cnt==0) break;
            while (index<n && read4Idx<read4Cnt) {
                buf[index++]=read4Buf[read4Idx++];
            }
            if (read4Idx>=read4Cnt) {
                read4Idx=0;
            }
        }
        
        return index;
    }
    
private:
    char read4Buf[4];
    int read4Idx;
    int read4Cnt;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
