第二题parse html，存到hashmap里，hashmap的key是string，value是object（可以是string或者hashmap）。
html
      body-google 1point3acres
            title
                 resume
            /title
      /body
/html
给了一个函数getNextNode(),
返回结果依次是：
(openTag, html)
(openTag, body)
(openTag, title)
(value, resume)
(closeTag, title)
(closeTag, body)
(closeTag, html)

返回的结果是一个hashmap链。
|--------|       |--------|      |--------|       |--------|--------|
| html  ----->|body  ----->|title  ----->  |value |resume|
|--------|       |--------|       |--------|      |--------|--------|
注意是哈希表，不是链表，前面三个哈希表的value是下一个哈希表
解决方法就是用一个stack，数据类型是哈希表，遇到openTag就new一个哈希表并且push到stack里，遇到close时pop栈顶得到hashmap A，获得getNode的node.text，假设现在栈顶的哈希表是B，则B.put(node.text, A)

class Node {
public:
    string eventType;
    string text;
}

class XmlNode {
public:
	string value;
	map<string, XmlNode*> children;
};

class XmlStream {
public:
	Node* getNextNode() {
		return NULL;
	}
};

class Solution {
public:
	XmlNode* parseXml(XmlStream *stream) {
		Node *node;
		stack<XmlNode*> stk;
		XmlNode* res;

		while ((node=stream->getNextNode())!=NULL) {
			if (node->eventType=="openNode") {
				XmlNode *n=new XmlNode();
				if (!stk.empty()) {
					stk.top()->children[node->text]=n;
				}
				stk.push(n);
			} else if (node->eventType=="nodeValue") {
				if (!stk.empty()) {
					stk.top()->value=node->text;
				}
			} else if (node->eventType=="closeNode") {
				if (stk.size()==1) res=stk.top();
				stk.pop();
			}
		}

		if (!stk.empty()) { cerr<< "input incorrect" << endl;}
		return res;
	}
};

int main() {
	Solution s;

	return 0;
}

