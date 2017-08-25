75. Sort Colors  
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
Hide Company Tags Pocket Gems Microsoft Facebook
Hide Tags Array Two Pointers Sort
Hide Similar Problems (M) Sort List (M) Wiggle Sort (M) Wiggle Sort II

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, start=0, end=nums.size()-1;
        while (i<=end) {
            if (nums[i]==0) {
                if (i!=start) swap(nums[i], nums[start]);
                start++;
                i++;
            } else if (nums[i]==1) {
                i++;
            } else {
                if (nums[end]!=2) swap(nums[i], nums[end]);
                end--;
            }
        }
    }
};

2. Counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(3);
        for (int i:nums) count[i]++;
        for (int i=1; i<3; i++) count[i]+=count[i-1];
        
        for (int i=0; i<n; i++) {
            if (i<count[0]) nums[i]=0;
            else if (i<count[1]) nums[i]=1;
            else nums[i]=2;
        }
    }
};

3. Counting sort generic
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(3);
        for (int i:nums) count[i]++;
        
        int total=0;
        for (int i=0; i<3; i++) {
            int tmp=count[i];
            count[i]=total;
            total+=tmp;
        }
        
        vector<int> output(n);
        for (int i=0; i<n; i++) {
            output[count[nums[i]]]=nums[i];
            count[nums[i]]++;
        }
        nums=output;
    }
};

