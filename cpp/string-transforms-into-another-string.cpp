1153. String Transforms Into Another String
Hard

148

41

Add to List

Share
Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

 

Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
 

Note:

1 <= str1.length == str2.length <= 10^4
Both str1 and str2 contain only lowercase English letters.

Google
|
14

a chain: this is easy, we peel this chain from end. For example s="abc" and t="bcd", we have the graph a->b->c->d, 
we can do c->d then b->c then a->b.
a cycle: to break it we need a placeholder, i.e. a free character can be used so far. For example s="abc" and t="bca", 
we have the graph a->b->c->a which is a cycle, we can do c->z then b->c then a->b then z->a.
In both case, there should at least one character that is unused,
to use it as the tmp for transformation.
So we need to return if the size of set of unused characters < 26.

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1==str2) return true;
        
        unordered_map<char, char> mp;
        for (int i=0; i<str1.size(); ++i) {
            if (mp.find(str1[i])!=mp.end()) {
                if (mp[str1[i]]!=str2[i]) return false;
            } else {
                mp[str1[i]]=str2[i];
            }
        }
        return unordered_set<char>(str2.begin(), str2.end()).size()<26;
    }
};

