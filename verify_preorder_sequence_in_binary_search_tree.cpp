Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?

Kinda simulate the traversal, keeping a stack of nodes (just their values) of which we're still in the left subtree. If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes, so just push the new one onto the stack. But before that, pop all smaller ancestor values, as we must now be in their right subtrees (or even further, in the right subtree of an ancestor). Also, use the popped values as a lower bound, since being in their right subtree means we must never come across a smaller number anymore.


1. Use recursion

  class Solution {
  public:
	  bool verifyRecur(vector<int>& preorder, int start, int end) {
		  if (start>=end) return true;
		  int i;
		  for (i=start+1; i<=end; i++) {
			  if (preorder[i]>preorder[start]) break;
		  }
		  if (i>end) {
			  return verifyRecur(preorder, start+1, end);
		  } else {
			  bool left=verifyRecur(preorder, start+1, i-1);
			  bool right=verifyRecur(preorder, i, end);
			  return left && right;
		  }
	  }

      bool verifyPreorder(vector<int>& preorder) {
    	  int size=preorder.size();
    	  if (size==0) return true;

    	  return verifyRecur(preorder, 0, size-1);
      }
  };


2. Use stack

  class Solution {
  public:
      bool verifyPreorder(vector<int>& preorder) {
    	  stack<int> stk;
    	  int lowbound=INT_MIN;

    	  for (auto p:preorder) {
    		  if (p<lowbound) return false;

    		  while (!stk.empty() && stk.top()<p) {
    			  lowbound=stk.top();
    			  stk.pop();
    		  }
    		  stk.push(p);
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

