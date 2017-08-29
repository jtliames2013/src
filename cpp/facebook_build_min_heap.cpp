input是一个array，要求生成一个树，有以下三个属性
1）二叉树
2）Min Heap，表示node的每个子节点的值都大于或者等于这个node的值
3）做inorder traversal的时候要保持array的顺序

举个例子input是 5, 2, 10, 7
       2
      / \
    5   7
        /
        10

follow up 是一个addNode的函数，输入是root node，还有个int value，保持原有的属性，返回root

class Solution {
public:
	TreeNode* buildMinHeap(vector<int>& nums, int start, int end) {
		if (start>end) return NULL;
		int val=INT_MAX, idx=0;
		for (int i=start; i<=end; i++) {
			if (nums[i]<val) {
				val=nums[i];
				idx=i;
			}
		}
		TreeNode* n=TreeNode(nums[idx]);
		n->left=buildMinHeap(nums, start, idx-1);
		n->right=buildMinHeap(nums, idx+1, end);
		return n;
	}

	TreeNode* buildMinHeap(vector<int> nums) {
		int n=nums.size();
		return buildMinHeap(nums, 0, n-1);
	}

	TreeNode* addNode(TreeNode* root, int val) {
		// if current val is less than val, then insert, current node become left
		// else go to right
		if (root==NULL) return new TreeNode(val);
		TreeNode *parent=NULL, *curr=root;
		while (1) {
			if (curr->val>val) {
				TreeNode* n=new TreeNode(val);
				if (parent) parent->right=n;
				else root=n;
				n->left=curr;
				n->right=curr->right;
				curr->right=NULL;
				break;
			} else {
				if (curr->right==NULL) {
					curr->right=new TreeNode(val);
					break;
				}
				parent=curr;
				curr=curr->right;
			}
		}
		return root;
	}
};

