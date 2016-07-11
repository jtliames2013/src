  class BTIterator {
  public:
      BTIterator(TreeNode *root) {
    	  if (root!=NULL) stk.push(root);
      }

      /** @return whether we have a next smallest number */
      bool hasNext() {
    	  return stk.size()>0;
      }

      /** @return the next smallest number */
      int next() {
    	  if (hasNext()) {
    		  TreeNode *t=stk.top();
    		  stk.pop();
    		  if (t->right) stk.push(t->right);
    		  if (t->left) stk.push(t->left);
    		  return t->val;
    	  } else {
    		  return -1;
    	  }
      }
  private:
      stack<TreeNode*> stk;
  };

