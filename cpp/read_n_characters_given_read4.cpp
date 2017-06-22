157. Read N Characters Given Read4
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.

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
        idx=cnt=0;
    }
    
    int read(char *buf, int n) {
        int i=0;
        while (i<n) {
            cnt=read4(b);
            if (cnt==0) break;
            while (i<n && idx<cnt) buf[i++]=b[idx++];
            if (idx==cnt) idx=0;
        }
        
        return i;
    }
private:
    char b[4];
    int idx;
    int cnt;
};

