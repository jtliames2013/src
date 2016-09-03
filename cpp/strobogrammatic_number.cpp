A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

  class Solution {
  public:
      bool isStrobogrammatic(string num) {
    	  int size=num.size();
    	  int l=0, r=size-1;
    	  while (l<=r) {
    		  if (num[l]=='0') {
    			  if (num[r]!='0') return false;
    		  } else if (num[l]=='1') {
    			  if (num[r]!='1') return false;
    		  } else if (num[l]=='8') {
    			  if (num[r]!='8') return false;
    		  } else if (num[l]=='6') {
    			  if ((l==r || num[r]!='9')) return false;
    		  } else if (num[l]=='9') {
    			  if ((l==r || num[r]!='6')) return false;
    		  } else {
    			  return false;
    		  }
    		  l++;
    		  r--;
    	  }

    	  return true;
      }
  };

