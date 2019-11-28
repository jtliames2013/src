84. Largest Rectangle in Histogram  QuestionEditorial Solution  My Submissions
Total Accepted: 64486 Total Submissions: 261273 Difficulty: Hard
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

Show Tags
Show Similar Problems

How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar on left 
of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ 
respectively.
We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from 
stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. 
How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous 
item in stack is the ‘left index’.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        stack<int> idx;
        heights.push_back(0);
        
        for (int i=0; i<heights.size(); i++) {
            while (!idx.empty() && heights[idx.top()]>=heights[i]) {
                int curr=idx.top();
                idx.pop();
                // idx.top() - left where height <= heights[curr]
                // i - right where height <= heights[curr]
                res=max(res, heights[curr]*(idx.empty()?i:(i-1-idx.top())));
            }
            idx.push(i);
        }
        return res;
    }
};

后来又在网上发现一种比较流行的解法，是利用栈来解，可参见网友实验室小纸贴校外版的博客，但是经过仔细研究，其核心思想跟上面那种
剪枝的方法有异曲同工之妙，这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，当当前值小于栈顶值时，取出栈顶
元素，然后计算当前矩形面积，然后再对比当前值和新的栈顶值大小，若还是栈顶值大，则再取出栈顶，算此时共同矩形区域面积，照此类推，
可得最大矩形。这两种解法的时间复杂度很依赖于输入数组的情况，在最坏的情况下，比如输入数组是个递减数列，那么此时的时间复杂度
会变为O(n^2)。代码如下：

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int cur = s.top(); s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};

