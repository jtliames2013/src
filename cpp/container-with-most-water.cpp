11. Container With Most Water  QuestionEditorial Solution  My Submissions
Total Accepted: 85544 Total Submissions: 242603 Difficulty: Medium
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Hide Company Tags Bloomberg
Hide Tags Array Two Pointers
Hide Similar Problems (H) Trapping Rain Water

1.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0, l=0, r=height.size()-1;
        while (l<r) {
            res=max(res, min(height[l],height[r])*(r-l));
            if (height[l]<height[r]) l++;
            else r--;
        }

        return res;
    }
};

2.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        if (height.empty()) return area;
        int left=0, right=height.size()-1;
        while (left<right) {
            int h=min(height[left], height[right]);
            area=max(area, h*(right-left));
            while (left<right && height[left]<=h) left++;
            while (left<right && height[right]<=h) right--;
        }
        
        return area;
    }
};
