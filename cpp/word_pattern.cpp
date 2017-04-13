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

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> mp;
        unordered_set<string> st;
        istringstream iss(str);
        int i=0;
        
        for (string word; iss>>word; i++) {
            if (i>pattern.size()) return false;
            
            if (mp.find(pattern[i])!=mp.end()) {
                if (word!=mp[pattern[i]]) return false;
            } else {
                if (st.find(word)!=st.end()) return false;
                mp[pattern[i]]=word;
                st.insert(word);
            }
        }
        
        return i==pattern.size();
    }
};
