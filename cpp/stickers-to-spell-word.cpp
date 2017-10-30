691. Stickers to Spell Word
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
We are given N different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

Example 1:

Input:

["with", "example", "science"], "thehat"
Output:

3
Explanation:

We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
Example 2:

Input:

["notice", "possible"], "basicbasic"
Output:

-1
Explanation:

We can't form the target "basicbasic" from cutting letters from the given stickers.
Note:

stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.

Optimization: If the target can be spelled out by a group of stickers, at least one of them has to contain character target[0]. So I explicitly require next sticker containing target[0], which significantly reduced the search space.

class Solution {
public:
    int dfs(unordered_map<string, int>& mp, vector<vector<int>>& count, string target) {
        if (mp.find(target)!=mp.end()) return mp[target];
        int res=INT_MAX, n=count.size();
        vector<int> tc(26);
        for (auto c:target) tc[c-'a']++;
        
        for (int i=0; i<n; i++) {
            string next;
            if (count[i][target[0]-'a']==0) continue;
            for (int j=0; j<26; j++) {
                if (tc[j]>count[i][j]) next.append(tc[j]-count[i][j], 'a'+j);                
            }
            
            int cnt=dfs(mp, count, next);
            if (cnt!=-1) res=min(res, cnt+1);
        }
        
        mp[target]=res==INT_MAX?-1:res;
        return mp[target];
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int n=stickers.size();
        unordered_map<string, int> mp;
        mp[""]=0;
        vector<vector<int>> count(n, vector<int>(26));
        for (int i=0; i<n; i++) {
            for (auto c:stickers[i]) count[i][c-'a']++;
        }
        
        return dfs(mp, count, target);
    }
};
