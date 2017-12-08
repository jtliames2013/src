给了一些paper，作者，和reference paper
paper1 : [David, Mark] : [paper2]
paper2 : [Linsey] : []
paper3: [Mark]:[paper2]
如果两个人合作一个paper，两者之间有一个连接，如果一个人reference了另一个人的paper也是一个连接
找到两个作者之间的一条path。.

struct Paper {
	int id;
	vector<string> authors;
	vector<int> references;
	Paper(int i, vector<string> a, vector<int> r):id(i), authors(a), references(r) {}
};

class Solution {
public:
	bool findPath(vector<string>& path, set<string>& visited, string start, string end) {
		if (start==end) {
			path.push_back(start);
			return true;
		}

		path.push_back(start);
		visited.insert(start);

		for (auto neighbor:authorGraph[start]) {
			if (visited.find(neighbor)==visited.end()) {
				if (findPath(path, visited, neighbor, end)==true) return true;
			}
		}
		visited.erase(start);
		path.pop_back();
		return false;
	}

	vector<string> findPath(string start, string end) {
		vector<string> path;
		set<string> visited;
		findPath(path, visited, start, end);
		return path;
	}

	void buildGraph(vector<Paper>& papers) {
		map<int, set<string> > authors;
		map<int, set<int> > references;
		for (auto p:papers) {
			for (auto auth:p.authors) {
				authors[p.id].insert(auth);
			}
			for (auto ref:p.references) {
				references[p.id].insert(ref);
			}
		}

		for (auto iter:authors) {
			set<string> refAuthors;
			for (auto ref:references[iter.first]) {
				for (auto auth:authors[ref]) {
					refAuthors.insert(auth);
				}
			}

			for (auto authIter=iter.second.begin(); authIter!=iter.second.end(); authIter++) {
				for (set<string>::iterator coauthIter=authIter; coauthIter!=iter.second.end(); coauthIter++) {
					if (*authIter!=*coauthIter) {
						authorGraph[*authIter].insert(*coauthIter);
						authorGraph[*coauthIter].insert(*authIter);
					}
				}
			}

			for (auto authIter=iter.second.begin(); authIter!=iter.second.end(); authIter++) {
				for (auto refIter=refAuthors.begin(); refIter!=refAuthors.end(); refIter++) {
					if (*authIter!=*refIter) {
						authorGraph[*authIter].insert(*refIter);
						authorGraph[*refIter].insert(*authIter);
					}
				}
			}
		}
	}
private:
	map<string, set<string> > authorGraph;
};

int main() {
	Solution s;
	vector<Paper> papers={Paper(1, {"Alice", "Bob"}, {2}), Paper(2, {"Bob", "Charlie", "David"}, {3}), Paper(3, {"David", "Frank"}, {})};
	s.buildGraph(papers);
	vector<string> path=s.findPath("Alice", "Frank");
	for (int i=0; i<path.size(); i++) cout << path[i] << " ";
	cout << endl;
	return 0;
}

