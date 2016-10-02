the k elements from the right will be shift to the begining, the n-k elements at the begining will shift to end.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

  class Solution {
  public:
	  void reverse(vector<int>& nums, int start, int end) {
		  while (start<end) {
			  int tmp=nums[start];
			  nums[start]=nums[end];
			  nums[end]=tmp;
			  start++;
			  end--;
		  }
	  }

	  void rotate(vector<int>& nums, int k) {
		  int n=nums.size();
		  k=k%n;
		  reverse(nums, 0, n-k-1);
		  reverse(nums, n-k, n-1);
		  reverse(nums, 0, n-1);
      }
  };

2.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

3.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int count=0, start=0, curr=0;
        int num=nums[0];
        if (k<1) return;
        
        while (count<n) {
            do {
                swap(nums[(curr+k)%n], num);
                curr=(curr+k)%n;
                count++;
            } while (curr!=start);
            
            start++;
            num=nums[start];
            curr=start;
        }
    }
};

int main()
{
	return 0;
}

