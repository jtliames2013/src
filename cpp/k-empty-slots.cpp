683. K Empty Slots
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].

The idea is to use an array days[] to record each position's flower's blooming day. That means days[i] is the blooming day of the flower in position i+1. We just need to find a subarray days[left, left+1,..., left+k-1, right] which satisfies: for any i = left+1,..., left+k-1, we can have days[left] < days[i] && days[right] < days[i]. Then, the result is max(days[left], days[right]).

1.
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        vector<int> days(n);
        for (int i=0; i<n; i++) days[flowers[i]-1]=i+1;
        int l=0, r=k+1, res=INT_MAX;
        for (int i=0; r<n; i++) {
            if (days[i]<days[l] || days[i]<=days[r]) {
                if (i==r) res=min(res, max(days[l], days[r]));
                l=i;
                r=l+k+1;
            }
        }
        return res==INT_MAX?-1:res;
    }
};

2.
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        vector<bool> bloom(n);
        for (int i=0; i<n; i++) {
            int pos=flowers[i]-1, l=pos-1, r=pos+1;
            bloom[pos]=true;
            while (l>=0 && bloom[l]==false) l--;
            if (l>=0 && pos-l-1==k) return i+1;
            while (r<n && bloom[r]==false) r++;
            if (r<n && r-pos-1==k) return i+1;
        }
        return -1;
    }
};

