题目是手机上的通讯录，每条记录只有(name, number)这种pair,有些记录名字重复，有些记录号码重复，让我返回一个list<list<Record>>，将所有记录按人分组。比较tricky的点在于(ABC,123), (ABC, 456), (BCD, 456)三条记录，第一条和第三条也属于同一个人

给一堆(name, phone#)的记录，把属于同一人的记录group到一起打印出来。name一样的，phone一样的都属于都一个group。跟面试官讨论了一下如何用两个map解决的想法，

class Solution {
public:
	  vector<vector<pair<string,string> > > classify(vector<pair<string, string> > contacts) {
		  vector<vector<pair<string,string> > > res;
		  map<string, vector<string> > names;
		  map<string, vector<string> > phones;
		  set<string> visited;
		  set<string> phoneVisited;

		  for (auto c:contacts) {
			  names[c.first].push_back(c.second);
			  phones[c.second].push_back(c.first);
		  }

		  for (auto n:names) {
			  if (visited.find(n.first)==visited.end()) {
				  set<string> group;
				  queue<string> q1, q2;
				  q1.push(n.first);
				  visited.insert(n.first);

				  while (1) {
					  if (q1.empty()) break;
					  while (!q1.empty()) {
						  string f=q1.front();
						  q1.pop();
						  group.insert(f);

						  for (auto ph:names[f]) {
							  if (phoneVisited.find(ph)==phoneVisited.end()) {
								  q2.push(ph);
								  phoneVisited.insert(ph);
							  }
						  }
					  }
					  while (!q2.empty()) {
						  string f=q2.front();
						  q2.pop();

						  for (auto nm:phones[f]) {
							  if (visited.find(nm)==visited.end()) {
								  q1.push(nm);
								  visited.insert(nm);
							  }
						  }
					  }
				  }

				  vector<pair<string, string> > v;
				  for (auto g:group) {
					  for (auto ph:names[g]) {
						  v.push_back({g, ph});
					  }
				  }
				  res.push_back(v);
			  }
		  }

		  return res;
	  }
  };

int main() {
	vector<pair<string, string> > contacts={{"abc", "123"}, {"abc", "456"}, {"bcd", "456"}};
	Solution s;
	vector<vector<pair<string, string> > > res=s.classify(contacts);
	return 0;
}

