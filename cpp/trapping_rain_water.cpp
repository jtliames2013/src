42. Trapping Rain Water  QuestionEditorial Solution  My Submissions
Total Accepted: 72624 Total Submissions: 219642 Difficulty: Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        if (n==0) return 0;
        vector<int> left(n), right(n);
        for (int i=1; i<n; i++) left[i]=max(left[i-1], height[i-1]);
        for (int i=n-2; i>=0; i--) right[i]=max(right[i+1], height[i+1]);
        
        for (int i=0; i<n; i++) {
            res+=max(0, min(left[i], right[i])-height[i]);
        }
        return res;
    }
};

2. O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if (n==0) return 0;
        int res=0, left=0, right=n-1;
        int maxleft=0, maxright=0;
        while (left<=right) {
            if (height[left]<=height[right]) {
                if (height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            } else {
                if (height[right]>=maxright) maxright=height[right];
                else res+=maxright-height[right];
                right--;
            }
        }

        return res;
    }
};

