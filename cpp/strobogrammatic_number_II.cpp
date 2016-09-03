A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

Hint:

    Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.


NOTE: wrap letter around inner recursion. return inner vector of strings.

  class Solution {
  public:
	  Solution()
	  {
	      l="01689";
	      r="01986";
	  }

	  vector<string> getNum(int n, int start) {
		  vector<string> res;
		  if (n==0) return { "" };
		  if (n==1) return { "0", "1", "8" };
		  vector<string> nums = getNum(n-2, start+1);

		  int i = (start==0) ? 1 : 0;
		  for (auto num:nums) {
			  for (int j=i; j<l.size(); j++) {
				  res.push_back(string(1, l[j]) + num + string(1, r[j]));
			  }
		  }

		  return res;
	  }

      vector<string> findStrobogrammatic(int n) {
    	  return getNum(n, 0);
      }

  private:
      string l;
      string r;
  };

