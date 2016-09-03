大意就是把第一个haystack参数变成一个二维数组，然后找needle在haystack第一次出现的位置，同样的不能用string相关方法，还是返回把haystack[][]二维数组看成一维以后的第一次匹配的字符下标，举例：haystack := [[a,b,c,c], [c,b,d]], needle := [c,c,b,d] , return 2; needle := [b, d] return 5 (5是把haystack看成一维的以后的找到第一个bd以后b的下标)。

  class Solution {
  public:
	  void tryNeedleAdvance() {
		  while (r<m) {
			  if (c<haystack[r].size()) break;
			  r++;
			  c=0;
		  }
	  }
	  void tryAdvance() {
		  while (row<m) {
			  if (col<haystack[row].size()) break;
			  row++;
			  col=0;
		  }
	  }

      int strStr(vector<string> haystack, string needle) {
    	  this->haystack=haystack;
    	  m=haystack.size();
    	  row=0;
    	  col=0;
    	  int idx=0;
    	  int n=needle.size();
    	  while (row<m) {
    		  int j;
    		  r=row, c=col;
    		  for (j=0; j<n; j++) {
    			  if (needle[j]!=haystack[r][c]) break;
    			  c++;
    			  tryNeedleAdvance();
    		  }
    		  if (j==n) return idx;
    		  col++;
    		  tryAdvance();

    		  idx++;
    	  }
      }
  private:
      vector<string> haystack;
      int row;
      int col;
      int r;
      int c;
      int m;
  };

int main()
{
	Solution s;
	vector<string> haystack;
	haystack.push_back("abcc");
	haystack.push_back("cbd");
	//string needle="ccbd";
	string needle="bd";
	int res = s.strStr(haystack, needle);
  	return 0;
}

