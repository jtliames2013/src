1202. Smallest String With Swaps
Medium

168

7

Favorite

Share
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i]=i;
        unordered_map<int, vector<int>> mp;
        for (auto p:pairs) {
            int p1=find(root, p[0]);
            int p2=find(root, p[1]);
            if (p1!=p2) {
                root[p1]=p2;
            }
        }
        
        for (int i=0; i<n; ++i) mp[find(root,i)].push_back(i);  
        
        for (auto iter:mp) {            
            if (iter.second.size()>1) {
                string str;
                for (auto i:iter.second) str+=s[i];
                sort(str.begin(), str.end());
                for (int i=0; i<str.size(); ++i) s[iter.second[i]]=str[i];
            }
        }
        return s;
    }
private:
    int find(vector<int>& root, int i) {
        // path halving
        /* while (i!=root[i]) {
            root[i]=root[root[i]];
            i=root[i];
        }
        return i; */
        // path compression
        if (i!=root[i]) {
            root[i]=find(root, root[i]);
        }
        return root[i];
    }
};
