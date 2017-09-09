(1) Contact group, 输入是这样的:数字是用户，字母是邮箱，有很多人有多个邮箱，找出相同的用户
  1- {x,y,z},  
  2-{x} .
  3-{a,b}.
  4-{y, z}
  5-{b}
  6-{m}
  7-{t,b}

这样输出就是 [1,2,4] [3,5,7], [6] 这三组。. 
可以用UnionFind或者Connected Components的方法做，

有这么一个class Contact，里面有一个string的name，和一个vector 装着email address，是这个Contact有的address，用一个list装着是因为一个人有可 能有多个email，现在给你vector，比如

{
{ "JohnS", {"john@gmail.com"} },
{ "Mary", {"mary@gmail.com"} },
{ "John", {"john@yahoo.com"} },
{ "John", {"john@gmail.com", "john@yahoo.com", "john@hotmail.com"} },
{ "Bob", {"bob@gmail.com"} }

1. BFS
class Solution {
public:
	vector<vector<string>> dedup(vector<pair<string, vector<string>>> userContact) {
		vector<vector<string>> res;
		unordered_map<string, unordered_set<string>> userGraph;
		unordered_map<string, string> contactUser;
		for (auto u:userContact) {
			userGraph[u.first];
			for (auto c:u.second) {
				if (contactUser.find(c)==contactUser.end()) {
					contactUser[c]=u.first;
				} else {
					userGraph[u.first].insert(contactUser[c]);
					userGraph[contactUser[c]].insert(u.first);
				}
			}
		}

		unordered_set<string> visited;
		for (auto user:userGraph) {
			if (visited.find(user.first)==visited.end()) {
				vector<string> v;
				queue<string> q;
				q.push(user.first);
				visited.insert(user.first);
				while (!q.empty()) {
					string f=q.front();
					q.pop();
					v.push_back(f);
					for (auto n:userGraph[f]) {
						if (visited.find(n)==visited.end()) {
							q.push(n);
							visited.insert(n);
						}
					}
				}

				res.push_back(v);
			}
		}

		return res;
	}
};

2. UnionFind
class Solution {
public:
	string find(unordered_map<string, string>& userRoot, string user) {
		while (userRoot[user]!=user) {
			user=userRoot[user];
		}
		return user;
	}

	vector<vector<string>> dedup(vector<pair<string, vector<string>>> userContact) {
		vector<vector<string>> res;
		unordered_map<string, string> userRoot;
		unordered_map<string, string> contactUser;
		for (auto u:userContact) {
			userRoot[u.first]=u.first;
			for (auto c:u.second) {
				if (contactUser.find(c)==contactUser.end()) {
					contactUser[c]=u.first;
				} else {
					string root=find(userRoot, contactUser[c]);
					userRoot[u.first]=root;
				}
			}
		}

		unordered_map<string, vector<string>> groups;
		for (auto iter:userRoot) groups[iter.second].push_back(iter.first);
		for (auto iter:groups) res.push_back(iter.second);

		return res;
	}
};


int main()
{
	Solution s;
	vector<pair<string, vector<string>>> userContact= {
			{"1", {"x", "y", "z"}},
			{"2", {"x"}},
			{"3", {"a", "b"}},
			{"4", {"y", "z"}},
			{"5", {"b"}},
			{"6", {"m"}},
			{"7", {"t", "b"}}};
	vector<vector<string>> res= s.dedup(userContact);
	for (auto v:res) {
		for (auto s:v) cout << s << " ";
		cout << endl;
	}
	return 0;
}

