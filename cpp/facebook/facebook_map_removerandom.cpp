就一个问题，写一个map，能实现remove random. （刚开始我的自我介绍10分钟了)
写了10来分钟，他又自己介绍了一段时间，到最后用了35分钟，我问就一题吗， 他说没时间了就一题）

class RandomizedMap {
public:
    /** Initialize your data structure here. */
    RandomizedMap() {

    }

    void insert(int key, int val) {
        if (mp.find(key)!=mp.end()) {
        	data[mp[key]].second=val;
        } else {
			mp[key]=data.size();
			data.push_back({key,val});
        }
    }

    int get(int key) {
    	if (mp.find(key)==mp.end()) return -1;
    	return data[mp[key]].second;
    }

    bool remove(int key) {
        if (mp.find(key)==mp.end()) return false;
        if (data.back().first!=key) {
            int idx=mp[key];
            mp[data.back().first]=idx;
            data[idx]=data.back();
        }
        data.pop_back();
        mp.erase(key);
        return true;
    }

    /** Remove a random element from the set. */
    bool removeRandom() {
        if (data.empty()) return false;
        int idx=data[rand()%data.size()];
        if (idx<data.size()-1) {
        	swap(data[idx], data.back());
        }
        mp.erase(data.back().first);
        data.pop_back();
        return true;
    }
private:
    vector<pair<int,int>> data;
    unordered_map<int,int> mp;
};

