坐标上一堆点，求能组成的最小矩形 

一堆2维点，找出4个点组成最小矩形，可以先从找x-axis平行的矩形开始

矩形那题基本是考数学了，如果矩形的边必须平行于坐标轴，任意取两点作为矩形对角线，算出另外两点，看是否在集合中，再比较面积；

struct Point {
	int x;
	int y;
	Point(int a, int b):x(a), y(b) {}
};

struct myhash
{
    std::size_t operator()(Point const& p) const
    {
        std::size_t h1 = hash<int>{}(p.x);
        std::size_t h2 = hash<int>{}(p.y);
        return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
    }
};

class Solution {
public:
	int minimumRectangle(vector<Point> points) {
		int n=points.size();
		if (n==0) return 0;
		int res=INT_MAX;
		unordered_set<Point, myhash> st;
		for (auto&  p:points) st.insert(p);

		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (points[i].x!=points[j].x && points[j].y!=points[j].y) {
					Point d1(points[i].x, points[j].y);
					Point d2(points[i].y, points[j].x);
					if (st.find(d1)!=st.end() && st.find(d2)!=st.end()) {
						int area=abs(points[i].x-points[j].x)*abs(points[i].y-points[j].y);
						res=min(res, area);
					}
				}
			}
		}

		return res==INT_MAX?0:res;
	}
};

