给两组排好序的non-intersected的internvals，比如 [0, 0], [2, 2], [5, 10]
跟LC的interval的区别是这里intervals是离散的，类似[0, 0], [1, 2]这样的是invalid，因为可以写成[0, 2]

让写出对两组intervals的AND操作以及OR操作，输入输出，数据结构都可以自己定义

Interval is defined with left and right border and discrete points, like [2, 3], [0, 0], etc.. 

Set of intervals is non intersected set of sorted intervals, for example: [0, 0], [2, 2], [5, 10] is a valid set of intervals, but :
* [0, 0], [1, 2] is not valid, because you can write it as [0, 2]
* [0, 2], [1, 5] is not valid as well, since these two intervals intersect.

You need to find the AND operation of these two sets. For example:

1st set: [0, 2], [5, 10], [16, 20] [25, 26] [28, 30]
2nd set: [1, 5], [11, 12], [14, 18] [20, 23]

AND Result: [1, 2], [5, 5], [16, 18], [20, 20]

OR 

1st set: [0, 2], [6, 8], [16, 20]
2nd set: [1, 5], [12, 18], [20, 23]

[0,8], [12,23]

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> IntervalAnd(vector<Interval> v1, vector<Interval> v2) {
		sort(v1.begin(), v1.end(), [](Interval& a, Interval& b) {return a.start<b.start;});
		sort(v2.begin(), v2.end(), [](Interval& a, Interval& b) {return a.start<b.start;});
		vector<Interval> res;
		int i=0, j=0, m=v1.size(), n=v2.size();
		while (i<m && j<n) {
			if (v1[i].end<v2[j].start) i++;
			else if (v2[j].end<v1[i].start) j++;
			else {
				res.push_back(Interval(max(v1[i].start, v2[j].start), min(v1[i].end, v2[j].end)));
				if (v1[i].end<v2[j].end) i++;
				else j++;
			}
		}

		return res;
	}

	vector<Interval> IntervalOr(vector<Interval> v1, vector<Interval> v2) {
		sort(v1.begin(), v1.end(), [](Interval& a, Interval& b) {return a.start<b.start;});
		sort(v2.begin(), v2.end(), [](Interval& a, Interval& b) {return a.start<b.start;});
		vector<Interval> res;
		int i=0, j=0, m=v1.size(), n=v2.size();
		while (i<m || j<n) {
			Interval l;
			if (i>=m) l=v2[j++];
			else if (j>=n) l=v1[i++];
			else {
				if (v1[i].start<v2[j].start) {
					l=v1[i++];
				} else {
					l=v2[j++];
				}
			}
			if (res.empty() || res.back().end<l.start-1) res.push_back(l);
			else {
				res.back().end=max(res.back().end, l.end);
			}
		}

		return res;
	}
};


int main()
{
	Solution s;
	vector<Interval> v1={Interval(0,2), Interval(5,10), Interval(16,20), Interval(25,26), Interval(28,30)};
	vector<Interval> v2={Interval(1,5), Interval(11,12), Interval(14,18), Interval(20,23)};
	vector<Interval> v3={Interval(0,2), Interval(6,8), Interval(16,20)};
	vector<Interval> v4={Interval(1,5), Interval(12,18), Interval(20,23)};
	vector<Interval> res1=s.IntervalAnd(v1, v2);
	for (auto i:res1) cout << i.start << " " << i.end << endl;
	cout << endl;
	cout << "++++++++++" << endl;
	vector<Interval> res2=s.IntervalOr(v3, v4);
	for (auto i:res2) cout << i.start << " " << i.end << endl;
	cout << endl;

	return 0;
}

