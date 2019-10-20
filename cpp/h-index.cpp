274. H-Index 
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

使用长度为N + 1的数组cnts记录引用次数在0 ~ N（N篇以上的记为N）的文章个数
然后遍历cnts数组，计算h值的最大值

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if (n==0) return 0;
        vector<int> count(n+1);
        for (auto c:citations) {
            if (c<n) count[c]++;
            else count[n]++;
        }
        
        int sum=0, i;
        for (i=n; i>=0; i--) {
            sum+=count[i];
            if (sum>=i) break;
        }
        return i;
    }
};

