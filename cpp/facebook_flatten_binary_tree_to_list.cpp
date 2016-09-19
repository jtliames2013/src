半轮culture flt, project deep dive. 算法题是convert binary tree to linked list.
Coding. 先出了一个题是convert binary tree to doubly linked list.我说第一轮做过了非常类似的题。然后就直接写了他的Backup 

class Solution {
public:
	ListNode* convert(TreeNode *root, ListNode *parent, ListNode **tail) {
		if (root==NULL) return NULL;
		ListNode *n=new ListNode(root->val);
		if (parent!=NULL) parent->next=n;
		*tail=n;

		if (root->left) {
			convert(root->left, n, tail);
		}

		if (root->right) {
			convert(root->right, *tail, tail);
		}

		return n;
	}
	ListNode* convertBinaryTreeToLinkedList(TreeNode *root) {
		ListNode *dummy=new ListNode(0);
		ListNode** tail=&dummy;
		return convert(root, NULL, tail);
	}
};

int main()
{
	Solution s;
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	TreeNode t7(7);
	t1.left=&t2;
	t1.right=&t3;
	t2.left=&t4;
	t2.right=&t5;
	t3.left=&t6;
	t3.right=&t7;
	ListNode* res=s.convertBinaryTreeToLinkedList(&t1);

	return 0;
}

