168. Excel Sheet Column Title 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

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

2.
class Solution {

public:

    string convertToTitle(int n) {
        string res;
        while (n>0) {
            int num=n%26;
            if (num==0) {
                num=26;
				// borrow from high digit
                n-=26;
            }

            res.insert(res.begin(), 'A'+num-1);
            n/=26;
        }
       
        return res;
    }
};

