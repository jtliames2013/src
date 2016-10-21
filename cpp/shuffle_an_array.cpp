384. Shuffle an Array   QuestionEditorial Solution  My Submissions
Total Accepted: 11296 Total Submissions: 25391 Difficulty: Medium Contributors: Admin
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res=nums;
        for (int i=res.size()-1; i>0; i--) {
            int j=rand()%(i+1);
            swap(res[j],res[i]);
        }
        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
