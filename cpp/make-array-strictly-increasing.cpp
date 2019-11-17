1187. Make Array Strictly Increasing
Hard

171

6

Favorite

Share
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

 

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
 

Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9

In the above code. dp is the data structure storing all promising current states. A state here refers to a key-value pair, whose first element is the number we choose for current position. This can be either chosen from the original arr1 or from a replacement action from arr2. The second element is how many times we change the number. In the outer iteration, each time we first pick up the original element in arr1 as i. Then we look up in dp, trying to prolong each valid state we generated from the previous iteration. For example, we have state (5,0), and now i=7, we say um, it looks good so far we can generate a new state (7,0) because 7>5 it is increasing. No need to pick up a number from arr2. Meanwhile, another road is to choose a number from arr2 to replace 7. This number should be slightly bigger than 5. We choose the minimum number in arr2 that is bigger than 5, say 6. We can also add state (6,1) to dp. When both roads die, we can claim that the previous state can not be extended in this round. After we finish the final round, we look up into dp to see who survived the procedure and choose the minimum change one

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int res=INT_MAX;
        unordered_map<int, int> dp;
        dp[-1]=0;
        sort(arr2.begin(), arr2.end());
        for (auto i:arr1) {
            unordered_map<int, int> next;
            for (auto iter:dp) {                
                if (i>iter.first) next[i]=next.find(i)==next.end()?iter.second:min(next[i], iter.second);                
                auto upper=upper_bound(arr2.begin(), arr2.end(), iter.first);
                if (upper!=arr2.end()) next[*upper]=next.find(*upper)==next.end()?iter.second+1:min(next[*upper], iter.second+1);                
            }
            dp=next;
            
            if (dp.empty()) return -1;
        }
        
        for (auto iter:dp) res=min(res, iter.second);
        return res;
    }
};

