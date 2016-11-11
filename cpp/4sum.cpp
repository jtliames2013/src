#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void kSum(vector<vector<int> >& res, vector<int>& sum, vector<int>& nums, int start, int k, int target) {
		if (k==0) return;
		else if (k==1) {
			for (int i=start; i<nums.size(); i++) {
				if (nums[i]==target) {
					if (i==start || nums[i]!=nums[i-1]) {
						sum.push_back(nums[i]);
						res.push_back(sum);
						sum.pop_back();
					}
				}
			}
		}
		else if (k==2) {
			int l=start, r=nums.size()-1;
			while (l<r) {
				if (nums[l]+nums[r]==target) {
					if ((l==start || nums[l]!=nums[l-1]) &&
						(r==nums.size()-1 || nums[r]!=nums[r]+1)) {
						sum.push_back(nums[l]);
						sum.push_back(nums[r]);
						res.push_back(sum);
						sum.pop_back();
						sum.pop_back();
					}
					l++;
					r--;
				} else if (nums[l]+nums[r]>target) {
						r--;
				} else {
					l++;
				}
			}
		} else {
			for (int i=start; i<nums.size()-k+1; i++) {
				if (i==start || nums[i]!=nums[i-1]) {
					sum.push_back(nums[i]);
					kSum(res, sum, nums, i+1, k-1, target-nums[i]);
					sum.pop_back();
				}
			}
		}

	}

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int> > res;
    	if (nums.size() < 4) return res;
    	sort(nums.begin(), nums.end());
    	vector<int> sum;
  		kSum(res, sum, nums, 0, 4, target);

    	return res;
    }
};

2.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if (n<4) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-3; i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
                if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
                for (int j=i+1; j<n-2; j++) {
                    if (j==i+1 || nums[j]!=nums[j-1]) {
                        if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                        if (nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                        int left=j+1, right=n-1;
                        while (left<right) {
                            int sum=nums[left]+nums[right]+nums[i]+nums[j];
                            if (sum==target) {
                                res.push_back({nums[i],nums[j],nums[left],nums[right]});
                                left++;
                                right--;
                                while (left<right && nums[left]==nums[left-1]) left++;
                                while (left<right && nums[right]==nums[right+1]) right--;
                            } else if (sum>target) {
                                right--;
                            } else {
                                left++;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
	return 0;
}


