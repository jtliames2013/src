  class Solution {
  public:
      vector<int> countBits(int num) {
    	  vector<int> res(num+1);
    	  res[0]=0;
    	  res[1]=1;

    	  for (int i=2; i<=num; i++) {
    		  res[i]=res[i>>1] + (i & 0x1);
    	  }

    	  return res;
      }
  };

