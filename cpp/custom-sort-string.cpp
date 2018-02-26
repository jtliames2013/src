791. Custom Sort String
DescriptionHintsSubmissionsDiscussSolution
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
 

Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.

1.
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> mp;
        for (int i=0; i<S.size(); i++) mp[S[i]]=i+1;
        sort (T.begin(), T.end(), [&](char a, char b){ return mp[a]<mp[b]; });
        return T;
    }
};

2.
class Solution {
public:
    string customSortString(string S, string T) {
        string res;
        vector<int> mp(26);
        for (auto c:T) mp[c-'a']++;
        for (auto c:S) {
            res.append(mp[c-'a'], c);
            mp[c-'a']=0;
        }
        for (int i=0; i<26; i++) {
            if (mp[i]!=0) res.append(mp[i], 'a'+i);
        }
        return res;
    }
};
