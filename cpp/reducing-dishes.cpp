1402. Reducing Dishes
Hard

82

26

Add to List

Share
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.
Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3

1.
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        unordered_map<int, int> memo;
        sort(satisfaction.begin(), satisfaction.end());
        return dfs(satisfaction, memo, 0, 1);
    }
private:
    int dfs(vector<int>& satisfaction, unordered_map<int, int>& memo, int start, int count) {
        if (start==satisfaction.size()) return 0;
        int key=(start<<16) | count;
        if (memo.find(key)!=memo.end()) return memo[key];
        memo[key]=max(dfs(satisfaction, memo, start+1, count),
                      dfs(satisfaction, memo, start+1, count+1)+satisfaction[start]*count);

        return memo[key];
    }
};

2.
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size(), res=0, sum=0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i=n-1; i>=0 && satisfaction[i]>-sum; --i) {
            sum+=satisfaction[i];
            res+=sum;
        }
        return res;
    }
};

