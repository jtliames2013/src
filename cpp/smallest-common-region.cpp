1257. Smallest Common Region
Medium

54

10

Favorite

Share
You are given some lists of regions where the first region of each list includes all other regions in that list.

Naturally, if a region X contains another region Y then X is bigger than Y. Also by definition a region X contains itself.

Given two regions region1, region2, find out the smallest region that contains both of them.

If you are given regions r1, r2 and r3 such that r1 includes r3, it is guaranteed there is no r2 such that r2 includes r3.

It's guaranteed the smallest region exists.

 

Example 1:

Input:
regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
Output: "North America"
 

Constraints:

2 <= regions.length <= 10^4
region1 != region2
All strings consist of English letters and spaces with at most 20 letters.

Airbnb
|
LeetCode

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        unordered_set<string> ancestor;
        for (auto& r:regions) {
            for (int i=1; i<r.size(); ++i) parent[r[i]]=r[0];
        }
        while (1) {
            ancestor.insert(region1);
            if (parent.find(region1)==parent.end()) break;
            region1=parent[region1];
        }
        while (1) {
            if (ancestor.find(region2)!=ancestor.end()) return region2;
            if (parent.find(region2)==parent.end()) break;
            region2=parent[region2];
        }
        return "";
    }
};

