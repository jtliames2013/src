255. Verify Preorder Sequence in Binary Search Tree
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?

Mathworks
|
5

1. Use recursion. Time limit exceeded on skewed BST.
class Solution {
public:
	bool verify(vector<int>& preorder, int start, int end) {
		if (start>=end) return true;
		int i;
		for (i=start+1; i<=end; i++) {
			if (preorder[i]>preorder[start]) break;
		}
		for (int j=i; j<=end; j++) {
		    if (preorder[j]<preorder[start]) return false;
		}

		bool left=verify(preorder, start+1, i-1);
		bool right=verify(preorder, i, end);
		return (left&&right);
	}
	
    bool verifyPreorder(vector<int>& preorder) {
    	int n=preorder.size();
    	if (n==0) return true;
    	return verify(preorder, 0, n-1);
    }
};

2. Use stack
//[4,2,1,3,6,5,7]
// if the node is right child of parent, then all node after it 
// must have value greather than parent
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int lowerbound=INT_MIN;
        stack<int> stk;
        for (int i=0; i<preorder.size(); i++) {
            if (preorder[i]<lowerbound) return false;
            while (!stk.empty() && preorder[i]>stk.top()) {
                lowerbound=stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        return true;
    }
};

3. Use original array as stack
  class Solution {
  public:
      bool verifyPreorder(vector<int>& preorder) {
    	  int lowbound=INT_MIN;
    	  int i=-1;

    	  for (auto p:preorder) {
    		  if (p<lowbound) return false;

    		  // i is the top of stack
    		  while (i>=0 && preorder[i]<p) {
    			  lowbound=preorder[i];
    			  i--;
    		  }
    		  preorder[++i]=p;
    	  }

		  return true;
      }
  };

