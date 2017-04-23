解题思路：
由数据范围0 <= m <= n <= 2147483647可知，时间复杂度O（n）及以上的解法是不可接受的。

因此可以判断此题为数学题。

参考LeetCode Discuss链接：https://leetcode.com/discuss/32053/accepted-c-solution-with-simple-explanation

[m, n]范围的按位与的结果为m与n的公共“左边首部（left header）”

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int count=0;

    	while (m!=n) {
    		m>>=1;
    		n>>=1;
    		count++;
    	}

    	return n<<count;
    }
};

