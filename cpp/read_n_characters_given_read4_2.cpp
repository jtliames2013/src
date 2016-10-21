157. Read N Characters Given Read4 
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.

Hide Company Tags Facebook
Hide Tags String
Hide Similar Problems (H) Read N Characters Given Read4 II - Call multiple times

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

class Solution {
public:
	Solution () {
		readCnt=0;
	}

    int read(char *buf, int n) {
    	int index=0;

    	while (index<=n-4) {
    		readCnt=read4(buf+index);
    		index+=readCnt;
    		if (readCnt<4) return index;
    	}

		if (index<n) {
			char readBuf[4];
			readCnt=read4(readBuf);
			if (readCnt==0) return index;
			int i=0;
			while (index<n && i<readCnt) {
				buf[index++]=readBuf[i++];
			}
		}

    	return index;
    }
private:
    int readCnt;
};

	class Solution {
public:
	Solution () {
		readCnt=0;
	}

    int read(char *buf, int n) {
    	int index=0;

    	for (int i=0; i<n/4; i++) {
    		readCnt=read4(buf+index);
    		index+=readCnt;
    		if (readCnt<4) return index;
    	}

    	if (index<n) {
    		char readBuf[4];
			readCnt=read4(readBuf);
			if (readCnt==0) return index;
			int i=0;
			while (index<n && i<readCnt) {
				buf[index++]=readBuf[i++];
			}
    	}
    	return index;
    }
private:
    int readCnt;
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
