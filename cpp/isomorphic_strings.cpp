note case "ab" -> "aa"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> table;
        unordered_set<char> st;
        int m=s.size(), n=t.size();
        if (m!=n) return false;
        for (int i=0; i<m; i++) {
            if (table.find(s[i])!=table.end()) {
                if (table[s[i]]!=t[i]) return false;
            } else {
                if (st.find(t[i])!=st.end()) return false;
                table[s[i]]=t[i];
                st.insert(t[i]);
            }
        }
        
        return true;
    }
};

