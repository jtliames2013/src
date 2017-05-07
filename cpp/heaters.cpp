475. Heaters Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 13547
Total Submissions: 45803
Difficulty: Easy
Contributors:
neelamgehlot
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
Subscribe to see which companies asked this question.

Hide Tags Binary Search

1. Binary search
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m=houses.size(), n=heaters.size();
        if (m==0||n==0) return 0;
        sort(heaters.begin(), heaters.end());
        
        long res=0;
        for (auto h:houses) {
            auto iter=lower_bound(heaters.begin(), heaters.end(), h);
            long l=iter==heaters.end()?heaters.back():(iter==heaters.begin()?INT_MIN:*(iter-1));
            long r=iter==heaters.end()?INT_MAX:*iter;
            res=max(res, min(h-l, r-h));
        }
        return res;
    }
};

2. Sort
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m=houses.size(), n=heaters.size();
        if (m==0||n==0) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int i=0, res=0;
        for (auto h:houses) {
            while (i<n-1 && heaters[i]+heaters[i+1]<=2*h) i++;
            res=max(res, abs(heaters[i]-h));
        }
        
        return res;
    }
};

