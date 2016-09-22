76. Minimum Window Substring  
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Hide Company Tags LinkedIn Uber Facebook
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Substring with Concatenation of All Words (M) Minimum Size Subarray Sum (H) Sliding Window Maximum


二面刚面完的，是一个老印， 做数据处理的，上来先自我介绍，之后问了一些简历上的project，边问边在那边啪啪的打字。
问了一道题，minimum-window-substring。 写完了，老印没看懂，口述了一个test case， 老印懂了。说cool，cool
之后老印就问了一个问题，我的这个T里面的字符都是unique的，你为什么要记录T里面的字符出现的次数？

  class Solution {
  public:
      string minWindow(string s, set<char> st) {
    	  map<char, int> count;
    	  for (auto c:st) count[c]++;
    	  int total;
    	  int maxLen=INT_MIN;
    	  int start, end;

    	  for (int l=0, r=0; r<s.size(); r++) {
    		  if (count.find(s[r])!=count.end()) {
    			  if (count[s[r]]>0) total++;
    			  count[s[r]]--;

    			  while (total==st.size()) {
    				  if (r-l+1>maxLen) {
    					  maxLen=r-l+1;
    					  start=l;
    					  end=r;
    				  }

    				  if (count.find(s[l])!=count.end()) {
    					  count[s[l]]++;
    					  if (count[s[l]]>0) total--;
    				  }
    				  l++;
    			  }
    		  }
    	  }

    	  if (maxLen==INT_MIN) return "";
    	  else return s.substr(start, end-start+1);
      }
  };

int main()
{
	return 0;
}

