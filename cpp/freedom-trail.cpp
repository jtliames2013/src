514. Freedom Trail Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2607
Total Submissions: 7425
Difficulty: Hard
Contributors:
Rabby250
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
Example:


Input: ring = "godding", key = "gd"
Output: 4
Explanation:
 For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
 For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
 Also, we need 1 more step for spelling.
 So the final output is 4.
Note:
Length of both ring and key will be in range 1 to 100.
There are only lowercase letters in both strings and might be some duplcate characters in both strings.
It's guaranteed that string key could always be spelled by rotating the string ring.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Divide and Conquer Dynamic Programming

1. DP
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size(), n=key.size();
        vector<vector<int>> dp(m, vector<int>(n+1));
        
        for (int j=n-1; j>=0; j--) {
            for (int i=0; i<m; i++) {
                dp[i][j]=INT_MAX;
                for (int k=0; k<m; k++) {
                    if (ring[k]==key[j]) {
                        int diff=abs(k-i);
                        int step=min(diff, m-diff);
                        dp[i][j]=min(dp[i][j], dp[k][j+1]+step);
                    }
                }
            }
        }
        
        return dp[0][0]+n;
    }
};

2. DFS
The state is defined by position of thering and the index of character in the key. 
class Solution {
public:
    int dfs(string& ring, string& key, int start, int pos, unordered_map<int, unordered_map<int,int>>& mp) {
        if (start==key.size()) {
            return 0;
        }
        
        if (mp.find(start)!=mp.end() && mp[start].find(pos)!=mp[start].end()) return mp[start][pos];
        
        int i=pos, j=pos, ic=0, jc=0;
        do {
            // forward
            if (ring[i]==key[start]) break;
            i=(i+1)%ring.size();
            ic++;
        } while (i!=pos);

        do {
            // backward
            if (ring[j]==key[start]) break;
            j=j==0?ring.size()-1:j-1;
            jc++;
        } while (j!=pos);

        int f=dfs(ring, key, start+1, i, mp);
        int b=dfs(ring, key, start+1, j, mp);
        mp[start][pos]=min(f+ic, b+jc)+1;
        return mp[start][pos];
    }
    
    int findRotateSteps(string ring, string key) {
        unordered_map<int, unordered_map<int,int>> mp;
        return dfs(ring, key, 0, 0, mp);
    }
};


