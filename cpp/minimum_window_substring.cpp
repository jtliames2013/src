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

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (auto ch:t) count[ch]++;
        
        int total=0, start, minLen=INT_MAX;
        
        for (int l=0, r=0; r<s.size(); r++) {
            if (count.find(s[r])!=count.end()) {
                if (count[s[r]]>0) total++;
                count[s[r]]--;
            }
            
            if (total==t.size()) {
                while (total==t.size()) {
                    if (count.find(s[l])!=count.end()) {
                        if (count[s[l]]>=0) total--;
                        count[s[l]]++;                        
                    }
                    l++;
                }
                
                // l-1 is start of string, r is end of string
                if (minLen>r-l+2) {
                    start=l-1;
                    minLen=r-l+2;
                }
            }
        }
                
        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};

2. Use array instead of hash table
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128,0);
        for (auto ch:t) count[ch]++;        
        int total=0, start, minLen=INT_MAX;
        
        for (int l=0, r=0; r<s.size(); r++) {
            if (count[s[r]]>0) total++;
            count[s[r]]--;
            
            if (total==t.size()) {
                while (total==t.size()) {
                    if (count[s[l]]>=0) total--;
                    count[s[l]]++;
                    l++;
                }
                
                if (minLen>r-l+2) {
                    start=l-1;
                    minLen=r-l+2;
                }
            }
        }
                
        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};

3. Simplified version. Use set of char as input
  class Solution {
  public:
      string minWindow(string s, set<char> st) {
    	  map<char, int> count;
    	  for (auto c:st) count[c]++;
    	  int total=0;
    	  int minLen=INT_MAX;
    	  int start;

    	  for (int l=0, r=0; r<s.size(); r++) {
    		  if (count.find(s[r])!=count.end()) {
    			  if (count[s[r]]>0) total++;
    			  count[s[r]]--;
              }

              if (total==st.size()) { 
    			  while (total==st.size()) {
    				  if (count.find(s[l])!=count.end()) {
    					  if (count[s[l]]>=0) total--;
    					  count[s[l]]++;
    				  }
    				  l++;
    			  }

                  if (minLen>r-l+2) {
                      minLen=r-l+2;
                      start=l-1;
                  }
    		  }
    	  }

          return minLen==INT_MAX?"":s.substr(start, minLen);
      }
  };
    
