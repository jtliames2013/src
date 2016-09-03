360. Sort Transformed Array 
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Math Two Pointers

但是题目中的要求让我们在O(n)中实现，那么我们只能另辟蹊径。其实这道题用到了大量的高中所学的关于抛物线的数学知识，我们知道，对于一个方程f(x) = ax2 + bx + c 来说，如果a>0，则抛物线开口朝上，那么两端的值比中间的大，而如果a<0，则抛物线开口朝下，则两端的值比中间的小。而当a=0时，则为直线方法，是单调递增或递减的。那么我们可以利用这个性质来解题，题目中说明了给定数组nums是有序的，如果不是有序的，我想很难有O(n)的解法。正因为输入数组是有序的，我们可以根据a来分情况讨论：

当a>0，说明两端的值比中间的值大，那么此时我们从结果res后往前填数，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线两端的数，将它们之中较大的数先存入res的末尾，然后指针向中间移，重复比较过程，直到把res都填满。

当a<0，说明两端的值比中间的小，那么我们从res的前面往后填，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线两端的数，将它们之中较小的数先存入res的开头，然后指针向中间移，重复比较过程，直到把res都填满。

当a=0，函数是单调递增或递减的，那么从前往后填和从后往前填都可以，我们可以将这种情况和a>0合并。

class Solution {
public:
    int calc(int num, int a, int b, int c) {
        return a*num*num+b*num+c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        int size=nums.size();
        if (size==0) return res;
        res.resize(size, 0);
        int start=0, end=size-1;
        int i=(a>=0?size-1:0);
        
        while (start<=end) {
            if (a>=0) {
                // get the larger
                int s=calc(nums[start], a, b, c);
                int e=calc(nums[end], a, b, c);
                if (s>=e) {
                    res[i]=s;
                    start++;
                } else {
                    res[i]=e;
                    end--;
                }
                i--;
            } else {
                // get the smaller
                int s=calc(nums[start], a, b, c);
                int e=calc(nums[end], a, b, c);
                if (s>=e) {
                    res[i]=e;
                    end--;
                } else {
                    res[i]=s;
                    start++;
                }
                i++;
            } 
        }
        
        return res;
    }
};

