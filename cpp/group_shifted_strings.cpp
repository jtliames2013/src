Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Note: For the return value, each inner list's elements must follow the lexicographic order.

  class Solution {
  public:
	  string convert(string s) {
		  if (s.size()==0) return s;
		  int dist=s[0]-'a';
		  for (int i=0; i<s.size(); i++) {
			  if (s[i]-'a'>=dist) {
				  s[i]-=dist;
			  } else {
				  s[i]-=dist-26;
			  }
		  }
		  return s;
	  }

      vector<vector<string>> groupStrings(vector<string>& strings) {
    	  map<string, vector<string> > groups;
    	  vector<vector<string> > res;

    	  for (int i=0; i<strings.size(); i++) {
    		  string key=convert(strings[i]);
    		  groups[key].push_back(strings[i]);
    	  }

    	  for (auto g:groups) {
    		  sort(g.second.begin(), g.second.end(), [](string a, string b) { return a < b;} );
    		  res. push_back(g.second);
    	  }
    	  return res;
      }
  };

