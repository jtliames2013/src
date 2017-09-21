315. Count of Smaller Numbers After Self
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

Hide Company Tags Google
Hide Tags Divide and Conquer Binary Indexed Tree Segment Tree Binary Search Tree
Show Similar Problems

这道题给定我们一个数组，让我们计算每个数字右边所有小于这个数字的个数，目测我们不能用brute force，OJ肯定不答应，那么我们为了提高运算效率，首先可以使用用二分搜索法，思路是将给定数组从最后一个开始，用二分法插入到一个新的数组，这样新数组就是有序的，那么此时该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数，参见代码如下：

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return vector<int>();
        vector<int> res(n), sorted;
        
        for (int i=n-1; i>=0; i--) {
            int l=0, r=sorted.size()-1, mid;
            while (l<=r) {
                mid=l+(r-l)/2;
                if (sorted[mid]<nums[i]) l=mid+1;
                else r=mid-1;
            }
            res[i]=l;
            sorted.insert(sorted.begin()+l, nums[i]);
        }
        return res;
    }
};

2.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res, sorted;
        int n=nums.size();
        if (n==0) return res;
        res.resize(n);
        
        for (int i=n-1; i>=0; i--) {
            int l=0, r=sorted.size(), mid;
            while (l<r) {
                mid=l+(r-l)/2;
                if (sorted[mid]<nums[i]) l=mid+1;
                else r=mid;
            }
            res[i]=r;
            sorted.insert(sorted.begin()+r, nums[i]);
        }
        return res;
    }
};
