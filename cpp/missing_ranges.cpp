163. Missing Ranges  QuestionEditorial Solution  My Submissions
Total Accepted: 13045 Total Submissions: 43520 Difficulty: Medium
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Summary Ranges

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int start=lower-1, end;

        for (int i=0; i<nums.size(); i++) {
            end=nums[i];
            if (end>start+1) {
                if (end>start+2) {
                    res.push_back(to_string(start+1) + "->" + to_string(end-1));
                } else {
                    res.push_back(to_string(start+1));
                }
            }
            start=nums[i];
        }

        if (upper>start) {
            if (upper>start+1) {
                res.push_back(to_string(start+1) + "->" + to_string(upper));
            } else {
                res.push_back(to_string(upper));
            }
        }
        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
