Given a list of time blocks where a particular person is already booked/busy, a start and end time to search between, a minimum duration to search for, find all the blocks of time that a person is free for a potential meeting that will last the aforementioned duration.

Given: start_time, end_time, duration, meetings_list -> suggested_meeting_times

Let's assume we abstract the representation of times as simple integers, so a valid time is any valid integer supported by your environment. Here is an example input:

meetings_list: [3,20], [-2, 0], [0,2], [16,17], [19,23], [30,40], [27, 33]
start_time: -5
end_time: 27
min_duration: 2
expected answer:

free_time: [-5, -2], [23,27]
Feel free to represent the meetings however you would like, i.e. List of Lists, Lists of Objects etc.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFreeBlock(vector<vector<int>> intervals, int startTime, int endTime, int minDuration) {
        vector<vector<int>> res;
        int n=intervals.size();
        if (n==0) {
            if (endTime-startTime>=minDuration) {
                res.push_back({startTime, endTime});
            }
            return res;
        }
        vector<pair<int, bool>> points;
        for (auto& i:intervals) {
            points.push_back({i[0], true});
            points.push_back({i[1], false});
        }
        sort(points.begin(), points.end(), [](pair<int, bool>& a, pair<int, bool>& b){ return a.first<b.first || (a.first==b.first && a.second==false); });

        int count=0, start=startTime, end;
        for (auto& p:points) {
            if (p.second==true) count++;
            else count--;
            if (count==0) start=p.first;
            else if (count==1) {
                if (start!=INT_MIN) {
                    end=p.first;
                    if (end-start>=minDuration) res.push_back({start, end});
                    start=INT_MIN;
                }
            }
        }

        if (endTime-points[2*n-1].first>=minDuration) res.push_back({points[2*n-1].first, endTime});

        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> intervals={{3,20}, {-2, 0}, {0,2}, {16,17}, {19,23}, {30,40}, {27, 33}};
    vector<vector<int>> res=sol.findFreeBlock(intervals, -5, 27, 2);
    for (auto& v:res) {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}

