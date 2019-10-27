457. Circular Array Loop
Medium

192

1050

Favorite

Share
You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 

Example 1:

Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.
Example 2:

Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.
Example 3:

Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.
 

Note:

-1000 ≤ nums[i] ≤ 1000
nums[i] ≠ 0
1 ≤ nums.length ≤ 5000
 

Follow up:

Could you solve it in O(n) time complexity and O(1) extra space complexity?

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        if (n<=1) return false;
        
        for (int i=0; i<n; ++i) {            
            if (nums[i]==0) continue;
            int j=i, k=i;
            while (nums[k]!=0) {   
                j=getNext(j, nums);
                k=getNext(k, nums);                
                if (nums[k]*nums[i]<0) break;
                k=getNext(k, nums);                
                if (nums[k]*nums[i]<0) break;
                
                if (j==k) {
                    // check if there is one element in loop
                    if (j==getNext(j, nums)) break;
                    else return true;
                }
            }
            
            j=i;            
            while (nums[j]*nums[i]>0) {
                int next=getNext(j, nums);                
                nums[j]=0;
                j=next;
            }
        }
        return false;
    }
private:
    int getNext(int i, vector<int>& nums) {
        int n=nums.size();
        return i+nums[i]>=0?(i+nums[i])%n:n+((i+nums[i])%n);
    }
};
