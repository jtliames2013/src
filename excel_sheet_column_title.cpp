  class Solution {
  public:
      string convertToTitle(int n) {
    	  string res;
    	  char c;
    	  while (n>0) {
    		  int mod=n%26;
    		  if (mod==0) c='Z';
    		  else c=mod-1+'A';
    		  res.insert(res.begin(), c);
    		  if (mod==0) n-=26;
    		  n/=26;
    	  }

    	  return res;
      }
  };

