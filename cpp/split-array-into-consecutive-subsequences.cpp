659. Split Array into Consecutive Subsequences
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]

We iterate through the array once to get the frequency of all the elements in the array
We iterate through the array once more and for each element we either see if it can be appended to a previously constructed consecutive sequence or if it can be the start of a new consecutive sequence. If neither are true, then we return false.

Note: both sequences are consecutive

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, prev;
        for (auto i:nums) count[i]++;
        for (auto i:nums) {
            if (count[i]==0) continue;
            if (prev[i]>0) {
                prev[i]--;
                prev[i+1]++;
            } else if (count[i+1]>0 && count[i+2]>0) {
                count[i+1]--;
                count[i+2]--;
                prev[i+3]++;
            } else {
                return false;
            }
            count[i]--;
        }
        return true;
    }
};

