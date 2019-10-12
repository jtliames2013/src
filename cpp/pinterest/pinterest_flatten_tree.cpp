一道把二叉树转化成双向链表的题目，而且要求最优解

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	ListNode* flatten(TreeNode* root, ListNode* head, ListNode** tail) {
		if (root==NULL) return NULL;
		ListNode* node=new ListNode(root->val);
		*tail=node;
		if (head!=NULL) head->next=node;
		flatten(root->left, node, tail);
		flatten(root->right, *tail, tail);

		return node;
	}

	ListNode* flattenTree(TreeNode* root) {
		ListNode *dummy=new ListNode(0);
		ListNode** tail=&dummy;
		return flatten(root, NULL, tail);
	}
};

int main() {
	TreeNode *n1=new TreeNode(1);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	n1->left=n2;
	n1->right=n3;
	Solution s;
	ListNode* res=s.flattenTree(n1);
	return 0;
}

