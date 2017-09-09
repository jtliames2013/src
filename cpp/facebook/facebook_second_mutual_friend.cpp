find 2nd mutal friend

第二题就是找两个array 里面相同的数字， follow-up就是给你一个user_id 和API 接口 get_friend(int id), 
让你找出所有user id 是你的朋友的朋友但不是你的朋友，然后根据mutual friends的数量排序，

Could I just get the list of friends from myself and keep a HashMap count of friends of friend? If a friend of a friend doesn't exist in the hashmap, just add that person in, else increase the count. Then we can add all <k,v> pairs to a MaxHeap and get the top n times if we want the top n 2nd degree connections. Else, we can just add all <k,v> pairs to an array list and sort it based on value.

class Solution {
public:
	unordered_set<int> getFriends(int id) {
		return unordered_set<int>();
	}

	vector<int> findSecondMutualFriend(int id) {
		unordered_set<int> friends=getFriends(id);
		unordered_set<int> visited=friends;
		visited.insert(id);
		unordered_map<int, int> mutualCount;

		for (auto f:friends) {
			unordered_set<int> friendfriend=getFriends(f);
			for (auto ff:friendfriend) {
				if (visited.find(ff)==visited.end()) {
					mutualCount[ff]++;
				}
			}
		}
		vector<pair<int,int>> v;
		for (auto& iter:mutualCount) v.push_back({iter.first, iter.second});
		sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {return a.second>b.second;});
		vector<int> res(v.size());
		for (int i=0; i<v.size(); i++) res[i]=v[i].first;
		return res;
	}
};



