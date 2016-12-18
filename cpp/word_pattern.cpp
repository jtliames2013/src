290. Word Pattern  
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.

Hide Company Tags Dropbox Uber
Hide Tags Hash Table
Hide Similar Problems (E) Isomorphic Strings (H) Word Pattern II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

  class Solution {
  public:
      bool wordPattern(string pattern, string str) {
    	  map<char, string> m;
    	  unordered_set<string> mapped;
    	  istringstream iss(str);
    	  int i=0;

    	  for (string word; iss >> word; i++) {
    		  if (i>=pattern.size()) return false;

    		  if (m.find(pattern[i])!=m.end()) {
    			  if (word != m[pattern[i]]) return false;
    		  } else {
    			  if (mapped.find(word)!=mapped.end()) return false;
    			  mapped.insert(word);
    			  m[pattern[i]]=word;
    		  }
    	  }

    	  return i==pattern.size();
      }
  };

int main()
{
	return 0;
}

