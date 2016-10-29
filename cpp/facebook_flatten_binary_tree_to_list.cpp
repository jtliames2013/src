半轮culture flt, project deep dive. 算法题是convert binary tree to linked list.
Coding. 先出了一个题是convert binary tree to doubly linked list.我说第一轮做过了非常类似的题。然后就直接写了他的Backup 

inorder
struct ListNode {
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode(int v):val(v), next(NULL), prev(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	ListNode* convertBinaryTreeToLinkedList(TreeNode *root) {
		ListNode* head=NULL, *tail=NULL;
		stack<TreeNode*> stk;
		TreeNode *n=root;
		while (n!=NULL) {
			stk.push(n);
			n=n->left;
		}

		while (!stk.empty()) {
			TreeNode* t=stk.top();
			stk.pop();
			ListNode* ln=new ListNode(t->val);
			if (head==NULL) {
				head=tail=ln;
			} else {
				tail->next=ln;
				ln->prev=tail;
				tail=ln;
			}

			TreeNode *n=t->right;
			while (n!=NULL) {
				stk.push(n);
				n=n->left;
			}
		}

		// make circle using head and tail
		head->prev=tail;
		tail->next=head;

		return head;
	}
};

preorder
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

2. convert BST to double linked list
class Solution {
public:
	TreeNode* convert(TreeNode *root) {
		if (root==NULL) return NULL;
		if (root->left) {
			TreeNode* left=convert(root->left);
			while (left->right) {
				left=left->right;
			}
			left->right=root;
			root->left=left;
		}

		if (root->right) {
			TreeNode* right=convert(root->right);
			while (right->left) {
				right=right->left;
			}
			right->left=root;
			root->right=right;
		}
		return root;
	}

	TreeNode* convertBSTToLinkedList(TreeNode *root) {
		if (root==NULL) return NULL;

		root=convert(root);

		while (root->left) {
			root=root->left;
		}
		return root;
	}
};

3. Circular linked list
class Solution {
public:
	TreeNode* convert(TreeNode *root) {
		if (root==NULL) return NULL;
		if (root->left) {
			TreeNode* left=convert(root->left);
			while (left->right) {
				left=left->right;
			}
			left->right=root;
			root->left=left;
		}

		if (root->right) {
			TreeNode* right=convert(root->right);
			while (right->left) {
				right=right->left;
			}
			right->left=root;
			root->right=right;
		}
		return root;
	}

	TreeNode* convertBSTToLinkedList(TreeNode *root) {
		if (root==NULL) return NULL;

		root=convert(root);

		TreeNode *l=root, *r=root;
		while (l->left) {
			l=l->left;
		}
		while (r->right) {
			r=r->right;
		}
		l->left=r;
		r->right=l;
		return l;
	}
};

4. make circular recursively
class Solution {
public:
	TreeNode* merge(TreeNode* t1, TreeNode* t2) {
		if (t1==NULL) return t2;
		if (t2==NULL) return t1;

		TreeNode* t1left=t1->left;
		TreeNode* t2left=t2->left;

		t1left->right=t2;
		t2->left=t1left;
		t2left->right=t1;
		t1->left=t2left;

		return t1;
	}

	TreeNode* convert(TreeNode *root) {
		if (root==NULL) return NULL;

		TreeNode* left=convert(root->left);
		TreeNode* right=convert(root->right);

		root->left=root;
		root->right=root;

		left=merge(left, root);
		left=merge(left, right);

		return left;
	}
};

5.
class Solution {
public:
	void convert(TreeNode *root, TreeNode **head, TreeNode **tail) {
		if (root==NULL) return;
		*head=*tail=root;
		if (root->left) {
			TreeNode *lefthead=NULL, *lefttail=NULL;
			convert(root->left, &lefthead, &lefttail);
			*head=lefthead;
			lefttail->right=root;
			root->left=lefttail;
		}
		if (root->right) {
			TreeNode *righthead=NULL, *righttail=NULL;
			convert(root->right, &righthead, &righttail);
			root->right=righthead;
			righthead->left=root;
			*tail=righttail;
		}
	}

	void convertBSTToLinkedList(TreeNode *root, TreeNode **head, TreeNode **tail) {
		convert(root, head, tail);
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
	TreeNode *head=NULL, *tail=NULL;
	s.convertBSTToLinkedList(&t1, &head, &tail);

	TreeNode *curr=head;
	while (curr!=NULL) {
		cout << curr->val << endl;
		curr=curr->right;
	}

	return 0;
}

