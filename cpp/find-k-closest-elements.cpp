658. Find K Closest Elements
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int i=lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        int l=i-1, r=i;
        while (k--) {
            if (l<0) r++;
            else if (r>=arr.size()) l--;
            else {
                if (abs(arr[l]-x)>abs(arr[r]-x)) r++;
                else l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }    
};

2.
It's the first index i so that arr[i] is better than arr[i+k] (with "better" meaning closer to or equally close to x).
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size(), l=0, r=n-k, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (abs(arr[mid]-x)<=abs(arr[mid+k]-x)) r=mid;
            else l=mid+1;
        }
        return vector<int>(arr.begin()+r, arr.begin()+r+k);
    }    
};
