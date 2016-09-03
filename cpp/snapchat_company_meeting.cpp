题目是你要举办一个party，给你一些人和他们的上下级关系，如果你邀请了一个人就不能邀请他的直接上级或者直接下级，问怎样邀请能使邀请的所有人的级别加起来和最高（比如CEO是10级然后VP9级这样，类似每个人有一个分数）

class Node {
	int val;
	vector<Node*> children;
};
  class Solution {
public:
	  pair<int, int> getMaximum(Node* node) {
		  if (node==NULL) return {0, 0};
		  int sumfirst=0, sumsecond=0;
		  for (int i=0; i<node->children.size(); i++) {
			  pair<int, int> res=getMaximum(node->children[i]);
			  sumfirst+=res.first;
			  sumsecond+=res.second;
		  }
		  return {node->val+sumsecond, max(sumfirst, sumsecond)};
	  }

	  int getMaximumLevel(Node *root) {
		  pair<int,int> res=getMaximum(root);
		  return max(res.first, res.second);
	  }
  };

  int main() {
	  Node *ceo=new Node(10);
	  Node *vp1=new Node(9);
	  Node *vp2=new Node(9);
	  ceo->children.push_back(vp1);
	  ceo->children.push_back(vp2);

	  for (int i=0; i<3; i++) {
		  Node *staff=new Node(1);
		  vp1->children.push_back(staff);
	  }

	  Solution s;
	  int res=s.getMaximumLevel(ceo);
	  return 0;
  }

