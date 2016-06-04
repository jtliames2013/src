  class Solution {
  public:
      uint32_t reverseBits(uint32_t n) {
    	  int cnt=32;
    	  int res=0;
    	  while (cnt>0) {
    		  int last=n & 0x1;
    		  n >>= 1;
    		  last <<= cnt-1;
    		  res |= last;
    		  cnt--;
    	  }
    	  return res;
      }
  };

