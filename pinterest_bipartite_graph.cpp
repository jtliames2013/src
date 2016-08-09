class Solution {
	bool isBipartite(int n, vector<pair<int,int>> edges) {
		if (n==0) return false;
		vector<int> partition(n, 0);
		vector<set<int> > graph(n);
		for (auto e:edges) {
			graph[e.first].insert(e.second);
			graph[e.second].insert(e.first);
		}

		// suppose the graph is strongly connected
		// otherwise iterate over 0 - n-1
		queue<int> q;
		q.push(0);
		partition[0]=1;

		while (!q.empty()) {
			int f=q.front();
			q.pop();

			for (auto neighbor:graph[f]) {
				if (partition[neighbor]==0) {
					q.push(neighbor);
					if(partition[f]==1) partition[neighbor]=2;
					else partition[neighbor]=1;
				} else if (partition[f]==partition[neighbor]) {
					return false;
				}
			}
		}

		return true;
	}
};

class Solution {
	bool isBipartite(vector<pair<int,int>> edges) {
		map<int, int> partition;
		map<int, set<int> > graph;
		for (auto e:edges) {
			graph[e.first].insert(e.second);
			graph[e.second].insert(e.first);
			partition[e.first]=0;
			partition[e.second]=0;
		}
		queue<int> q;
		q.push(graph.begin()->first);
		partition[graph.begin()->first]=1;

		while (!q.empty()) {
			int f=q.front();
			q.pop();

			for (auto neighbor:graph[f]) {
				if (partition[neighbor]==0) {
					q.push(neighbor);
					partition[neighbor]=(partition[f]==1)?2:1;
				} else if (partition[neighbor]==partition[f]) {
					return false;
				}
			}
		}

		return true;
	}
};

