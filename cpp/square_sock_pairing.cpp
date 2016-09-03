总共一个题，有三个部分, 总的来说就是socks pairing，

(1) Given input: (id, left or right)
01,left\n
02,right\n. 
03,left\n
04,right\n
05,left

要求输出一种solution: (01,02),(03,04) 
刚开始没仔细听，以为要输出全部solution。。。。结果后来发现下面的题全都是只要一种solution就行了。。醉了. 
还有就是parse input string, sock class什么的要自己写. 

(2) Given input: (id, left or right，color)
01,left, black\n 
02,right, pink\n
03,left, pink\n
04,right, black\n
05,left, white

要求输出 (01,04),(03,02). 

(3) 在第二题的基础上，在leftover的socks里面如果颜色相近（从string input里面读取的信息）也可以pair
最后没时间写完了。。。因为做第一题的时候脑贱想复杂了。。。

enum Color {
	black=0,
	pink,
	red,
	white
};

struct Sock {
	int id;
	bool left;
	Color color;
	Sock(int i, bool l): id(i), left(l) {}
	Sock(int i, bool l, Color c): id(i), left(l), color(c) {}
};

class Solution {
public:
	vector<pair<Sock, Sock> > pairSocks1(vector<Sock> socks) {
		vector<pair<Sock, Sock> > res;
		vector<Sock> left;
		vector<Sock> right;

		for (int i=0; i<socks.size(); i++) {
			if (socks[i].left==true) {
				if (!right.empty()) {
					res.push_back({socks[i], right.back()});
					right.pop_back();
				} else {
					left.push_back(socks[i]);
				}
			} else {
				if (!left.empty()) {
					res.push_back({left.back(), socks[i]});
					left.pop_back();
				} else {
					right.push_back(socks[i]);
				}
			}
		}

		return res;
	}

	vector<pair<int, int> > pairSocks2(vector<Sock> socks) {
		vector<pair<int,int> > res;
		map<Color, set<int> > left, right;
		for (int i=0; i<socks.size(); i++) {
			if (socks[i].left==true) {
				auto iter=right.find(socks[i].color);
				if (iter!=right.end()) {
					res.push_back({socks[i].id, *iter->second.begin()});
					iter->second.erase(iter->second.begin());
				} else {
					left[socks[i].color].insert(socks[i].id);
				}
			} else {
				auto iter=left.find(socks[i].color);
				if (iter!=left.end()) {
					res.push_back({*iter->second.begin(), socks[i].id});
					iter->second.erase(iter->second.begin());
				} else {
					right[socks[i].color].insert(socks[i].id);
				}
			}
		}

		return res;
	}

	vector<pair<int, int> > pairSocks3(vector<Sock> socks, int gap) {
		vector<pair<int,int> > res;
		map<Color, set<int> > left, right;
		for (int i=0; i<socks.size(); i++) {
			if (socks[i].left==true) {
				auto iter=right.find(socks[i].color);
				if (iter!=right.end()) {
					res.push_back({socks[i].id, *iter->second.begin()});
					iter->second.erase(iter->second.begin());
				} else {
					left[socks[i].color].insert(socks[i].id);
				}
			} else {
				auto iter=left.find(socks[i].color);
				if (iter!=left.end()) {
					res.push_back({*iter->second.begin(), socks[i].id});
					iter->second.erase(iter->second.begin());
				} else {
					right[socks[i].color].insert(socks[i].id);
				}
			}
		}

		for (auto sock:left) {
			while (!sock.second.empty()) {
				bool found=false;
				for (int color=sock.first-gap; color<=sock.first+gap; color++) {
					auto iter=right.find((Color)color);
					if (iter!=right.end() && !iter->second.empty()) {
						res.push_back({*sock.second.begin(), *iter->second.begin()});
						sock.second.erase(sock.second.begin());
						iter->second.erase(iter->second.begin());
						found=true;
						break;
					}
				}
				if (!found) break;
			}
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<Sock> socks={Sock(1,true, black), Sock(2,false, pink), Sock(3,true, white), Sock(4,true,pink), Sock(5,false, black), Sock(6,false,red)};
	vector<pair<Sock,Sock>> res1=s.pairSocks1(socks);
	vector<pair<int,int>> res2=s.pairSocks2(socks);
	vector<pair<int,int>> res3=s.pairSocks3(socks,1);
	return 0;
}

