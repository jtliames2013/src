47. Permutations II  
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
Hide Company Tags LinkedIn Microsoft
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations (M) Palindrome Permutation II

NOTE: Can't use swap as in I because it will change the sorted order and sorted order is used to avoid duplicate.
E.g., [0,0,0,1,9], after swap [0,9,0,1,0] and index is at 2. swap index 2 and 4 will cause duplicate.
class Solution {
public:
	void getPermuteUnique(vector<vector<int> >& res, vector<int>& nums, vector<int>& solution, vector<bool>& selected) {
		if (solution.size()==nums.size()) {
			res.push_back(solution);
			return;
		}

		for (int i=0; i<nums.size(); i++) {
			if (selected[i]==false && (i==0 || selected[i-1]==true || nums[i]!=nums[i-1])) {
				solution.push_back(nums[i]);
				selected[i]=true;
				getPermuteUnique(res, nums, solution, selected);
				solution.pop_back();
				selected[i]=false;
			}
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int> > res;
    	std::sort(nums.begin(), nums.end());
    	vector<int> solution;
    	vector<bool> selected(nums.size(), false);

    	getPermuteUnique(res, nums, solution, selected);

    	return res;
    }
};


