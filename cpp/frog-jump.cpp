403. Frog Jump Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 13750
Total Submissions: 43532
Difficulty: Hard
Contributor: LeetCode
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.

Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming

1. DFS
class Solution {
public:
    struct myHash {
        size_t operator()(const pair<int,int>& k) const
        {
            return hash<int>()(k.first) ^ (hash<int>()(k.second) << 1);
        }
    };    

    bool canCross(vector<int>& stones, int pos, int lastJump, unordered_map<pair<int,int>, int, myHash>& mp) {
        if (pos==stones.size()-1) return true;
        if (mp.find({pos, lastJump})!=mp.end()) return mp[{pos, lastJump}];
        
        for (int i=pos+1; i<stones.size(); i++) {
            int gap=stones[i]-stones[pos];
            if (gap<lastJump-1) continue;
            if (gap>lastJump+1) {
                mp[{pos, lastJump}]=false;
                return false;
            }
            if (canCross(stones, i, gap, mp)) {
                mp[{pos, lastJump}]=true;
                return true;
            }
        }
        return false;
    } 
    
    bool canCross(vector<int>& stones) {
        unordered_map<pair<int,int>, int, myHash> mp;
        return canCross(stones, 0, 0, mp);
    }
};

2. DP
Use map to represent a mapping from the stone (not index) to the steps that can be taken from this stone.
so this will be
[0,1,3,5,6,8,12,17]
{17=[], 0=[1], 1=[1, 2], 3=[1, 2, 3], 5=[1, 2, 3], 6=[1, 2, 3, 4], 8=[1, 2, 3, 4], 12=[3, 4, 5]}
Notice that no need to calculate the last stone.
On each step, we look if any other stone can be reached from it, if so, we update that stone's steps by adding step, step + 1, step - 1. If we can reach the final stone, we return true. No need to calculate to the last stone.
Here is the code:

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return false;
        unordered_map<int, unordered_set<int>> mp;
        mp[0].insert(1);
        
        for (int i=0; i<stones.size()-1; i++) {
            for (auto step:mp[stones[i]]) {
                int reach=stones[i]+step;
                if (reach==stones[stones.size()-1]) return true;
                if (reach<stones[stones.size()-1]) {
                    if (step>1) mp[reach].insert(step-1);
                    mp[reach].insert(step);
                    mp[reach].insert(step+1);
                }
            }
        }
        return false;
    }
};

