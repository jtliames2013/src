paint house大变种. n houses, k colors. neighboring houses cannot be painted with the same color.
看做一个graph。然后分组。初始所有house都为group 0
用bfs遍历这个图。然后根据相邻house颜色不一样改变组号。。。
最后颜色根据cost排序，然后最大group的house涂cost最小的颜色，以此类推

class Solution {
public:
	int minPaintCost(vector<int> costs, unordered_map<int, unordered_set<int>> houses) {
		int k=costs.size();
		if (k==0) return 0;
		sort(costs.begin(), costs.end());

		vector<set<int>> groups;
		set<int> group;
		for (auto h:houses) group.insert(h.first);

		while (!group.empty()) {
			set<int> next;
			auto iter=group.begin();
			while (iter!=group.end()) {
				int h=*iter;
				if (next.find(h)!=next.end()) {
					iter=group.erase(iter);
				} else {
					for (auto neighbor:houses[h]) {
						if (group.find(neighbor)!=group.end()) {
							next.insert(neighbor);
						}
					}
					iter++;
				}
			}

			groups.push_back(group);
			group=next;
		}

		sort(groups.begin(), groups.end(),[](set<int>& a, set<int>& b) {return a.size()>b.size();});
		int res=0;
		for (int i=0; i<groups.size(); i++) {
			for (auto g:groups[i]) cout << g << " ";
			cout << endl;
			res+=costs[i]*groups[i].size();
		}
		return res;
	}
};

int main()
{
	Solution s;
	unordered_map<int, unordered_set<int>> houses;
	houses[0]={1,2,3,4};
	houses[1]={0,2,5,6};
	houses[2]={0,1,3,5,7};
	houses[3]={0,2,8,9};
	houses[4]={0,6,9};
	houses[5]={1,2};
	houses[6]={1,4};
	houses[7]={2,8};
	houses[8]={3,7,10};
	houses[9]={3,4};
	houses[10]={8};
	vector<int> costs={1,1,1,1,1,1,1};
	s.minPaintCost(costs, houses);
	return 0;
}

