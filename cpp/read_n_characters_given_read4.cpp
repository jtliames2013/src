 The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case. 

NOTE: when remaining is less than 4, compare the number of chars to read and have been read.

  // Forward declaration of the read4 API.
  int read4(char *buf);

  class Solution {
  public:
      /**
       * @param buf Destination buffer
       * @param n   Maximum number of characters to read
       * @return    The number of characters read
       */
      int read(char *buf, int n) {
    	  if (n<=0) {
    		  return 0;
    	  }

    	  int chunks=n/4;
    	  int remain=n%4;
    	  int res=0;
    	  int numRead=0;
    	  int end=false;
    	  for (int i=0; i<chunks; i++) {
    		  numRead=read4(buf+i*4);
    		  res+=numRead;
    		  if (numRead<4) {
    			  end=true;
    			  break;
    		  }
    	  }

    	  if (!end && remain>0) {
    		  numRead=read4(buf+chunks*4);
    		  res+=min(numRead, remain);
    	  }

    	  return res;
      }
  };

