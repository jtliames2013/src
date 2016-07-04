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
        leftoverIdx=0;
        leftoverSize=0;
    }

    int read(char *buf, int n) {
        int index=0;

        while (index<n) {
            if (leftoverIdx==0) {
                leftoverSize=read4(leftover);
            }

            if (leftoverSize==0) break;
            while (index<n && leftoverIdx<leftoverSize) {
                buf[index++]=leftover[leftoverIdx++];
            }

            if (leftoverIdx>=leftoverSize) {
                leftoverIdx=0;
            }
        }

        return index;
    }

private:
    char leftover[4];
    int leftoverSize;
    int leftoverIdx;
};

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution() {
        leftoverSize=0;
    }
    
    int read(char *buf, int n) {
        int toRead=n;
        int charRead=0;
        char read4buf[4];
        if (leftoverSize>0) {
            if (toRead<=leftoverSize) {
                memcpy(buf, leftover, toRead);
                leftoverSize -= toRead;
                if (leftoverSize>0) {
                    for (int i=0; i<leftoverSize; i++) {
                        leftover[i]=leftover[i+toRead];
                    }
                }

                charRead=toRead;
                toRead=0;
            } else {
                memcpy(buf, leftover, leftoverSize);
                charRead += leftoverSize;
                toRead -= leftoverSize;
                leftoverSize=0;
            }
        }

        if (toRead>0) {
            int multiple=toRead/4;
            int remain=toRead%4;
            int charRead4;

            int i;
            for (i=0; i<multiple; i++) {
                charRead4 = read4(read4buf);
                memcpy(buf+charRead, read4buf, charRead4);
                charRead += charRead4;

                if (charRead4<4) {
                    break;
                }
            }

            if (i==multiple && remain>0) {
                charRead4=read4(read4buf);
                 
                if (charRead4<=remain) {
                    memcpy(buf+charRead, read4buf, charRead4);
                    charRead += charRead4;
                } else {
                    memcpy(buf+charRead, read4buf, remain);
                    charRead += remain;

                    for (int j=0; j<charRead4-remain; j++) {
                        leftover[j]=read4buf[remain+j];
                    }
                    leftoverSize=charRead4-remain;
                }
            }
        }

        return charRead;
    }

private:
    char leftover[4];
    int leftoverSize;
};

static char str[]="abc";
int index=0;
int read4(char *buf) {
    int len=strlen(str);
    if (index>=len) return 0;

    if (len-index<=4) {
        memcpy(buf, str+index, len-index);
        int res=len-index;
        index=len;
        return res;
    } else {
        memcpy(buf, str+index, 4);
        index+=4;
        return 4;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    Solution s;
    char buf[256];
    s.read(buf, 1);
    s.read(buf, 1);
    s.read(buf, 1);
    s.read(buf, 1);
	return 0;
}
