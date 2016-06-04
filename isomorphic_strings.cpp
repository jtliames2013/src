note case "ab" -> "aa"

  class Solution {
  public:
      bool isIsomorphic(string s, string t) {
    	  int size=s.size();
    	  map<char, char> m;
    	  unordered_set<char> mapped;
    	  for (int i=0; i<size; i++) {
    		  if (m.find(s[i])==m.end()) {
    			  if (mapped.find(t[i])!=mapped.end()) return false;
    			  m[s[i]]=t[i];
    			  mapped.insert(t[i]);
    		  } else {
    			  if (t[i]!=m[s[i]]) return false;
    		  }
    	  }

    	  return true;
      }
  };

