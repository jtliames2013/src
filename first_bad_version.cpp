  
  // Forward declaration of isBadVersion API.
  bool isBadVersion(int version);

  class Solution {
  public:
      int firstBadVersion(int n) {
    	  long l=1, r=n, m;
    	  while (l<r) {
    		  m=(l+r)/2;
    		  if (isBadVersion(m)) r=m;
    		  else l=m+1;
    	  }

    	  return r;
      }
  };

