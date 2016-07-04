// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    struct comp {
        bool operator() (const pair<int,int>& left, const pair<int,int>& right) { return left.second<right.second; };
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> frequency;
        for (auto n:nums) {
            frequency[n]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;

        for (auto f:frequency) {
            q.push(make_pair(f.first, f.second));
        }

        int i=0; 
        while (i<k && !q.empty()) {
            res.push_back(q.top().first);
            q.pop();
            i++;
        }

        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}