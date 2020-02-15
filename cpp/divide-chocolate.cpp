1231. Divide Chocolate
Hard

125

3

Add to List

Share
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

 

Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
 

Constraints:

0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5

Google
|
6

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int l=INT_MAX, r=0, mid;
        for (auto& s:sweetness) {
            l=min(l, s);
            r+=s;
        }

        while (l<r) {
            mid=l+(r-l)/2+1;
            if (getCounts(sweetness, mid)<K+1) r=mid-1;
            else l=mid;
        }
        return l;
    }
private:
    int getCounts(vector<int>& sweetness, int minBound) {
        int res=0, sum=0;
        for (auto& s:sweetness) {
            sum+=s;
            if (sum>=minBound) {
                sum=0;
                res++;
            }
        }
        return res;
    }
};

