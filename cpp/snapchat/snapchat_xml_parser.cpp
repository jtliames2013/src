题目： construct string from web page + XML paser，再次感谢面筋，不过有一点不同是需要设计data structure保存paser后的结果。
每个token有如下结构，然后给了个API getNextToken()获取下一个token, 我表示应该还有个hasNextToken()。
token {
  string name; // e.g.  story, id, snaps
  string tag_type; // {open, close, text} 三种type
};

第二题说了用stack 保存状态来解析，但是在设计结构的时候纠结了一会。最近缺乏运动，因而下午有小睡的习惯，结果在这个问题上卡了一会。说用nested hashmap，他表示make sense，就是想了半天没想到用下面这个结构，他提示我可以用vector<unordered_map<string, Node>>的结构，表示恍然大悟，然后发现应该并不需要vector。写完之后follow up就是如果tag不匹配怎么检测。
Node {
  string name;
  string value;
  unordered_map<string, Node>;
};

class XmlNode {
	  string name;
	  string content;
	  vector<XmlNode*> children;
public:
	  XmlNode(string s): name(s) {}
	  void addList(XmlNode* n) {
		  children.push_back(n);
	  }
	  void addContent(string s) {
		  content=s;
	  }
  };

typedef enum {
	open,
	close,
	text
} TokenType;

struct token{
	string name;
	TokenType type;
};

class Tokenizer{
	token getNextToken() {}
	bool hasNextToken() {}
};

class XmlParser {
public:
	XmlNode* parse(Tokenizer tok) {
		stack<XmlNode*>  stk;
		XmlNode *res;
		while (tok.hasNextToken) {
			token t=tok.getNextToken();
			if (t.type==open) {
				XmlNode *node=new XmlNode(t.name);
				if (!stk.empty()) {
					stk.top()->addList(node);
				}
			} else if (t.type==close) {
				if (stk.size()==1) res=stk.top();
				stk.pop();
			} else {
				if (!stk.empty()) {
					stk.top()->addContent(t.name);
				} else {
					// error
				}
			}
		}

		return res;
	}
};

