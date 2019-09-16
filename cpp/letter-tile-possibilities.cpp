1079. Letter Tile Possibilities
Medium

261

11

Favorite

Share
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188
 

Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26);
        for (auto t:tiles) cnt[t-'A']++;
        int sum=0;
        dfs(cnt, sum);
        return sum;
    }
private:
    void dfs(vector<int>& cnt, int& sum) {
        for (int i=0; i<26; ++i) {
            if (cnt[i]!=0) {
                cnt[i]--;
                sum++;
                dfs(cnt, sum);                
                cnt[i]++;
            }
        }
    }
};
