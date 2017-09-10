struct Point {
	int x;
	int y;
	Point(int a, int b): x(a), y(b) {}
};

1. MaxHeap
class Solution {
public:
	int dist(Point& a, Point& b) {
		return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}

	vector<Point> findClosestKPoints(vector<Point> points, Point origin, int k) {
		vector<Point> res;
		int n=points.size();
		vector<pair<int,int>> d(n);
		for (int i=0; i<n; i++) d[i]={dist(points[i], origin), i};

		auto comp = [] (pair<int,int>& a, pair<int,int>& b) {
			return a.first<b.first;
		};

		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
		for (int i=0; i<points.size(); i++) {
			if (pq.size()<k) {
				pq.push(d[i]);
			} else {
				if (d[i].first<pq.top().first) {
					pq.pop();
					pq.push(d[i]);
				}
			}
		}

		while (!pq.empty()) {
			res.push_back(points[pq.top().second]);
			pq.pop();
		}

		return res;
	}
 };

2. Quick Select
class Solution {
public:
	int dist(Point& a, Point& b) {
		return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}

	int partition(vector<pair<int,int>>& d, int l, int r, int pivot) {
		pair<int,int> pivotValue=d[pivot];
		swap(d[r], d[pivot]);
		int index=l;
		for (int i=l; i<r; i++) {
			if (d[i].first<pivotValue.first) {
				if (index!=i) swap(d[index], d[i]);
				index++;
			}
		}
		swap(d[index], d[r]);
		return index;
	}

	vector<Point> findClosestKPoints(vector<Point> points, Point origin, int k) {
		vector<Point> res;
		int n=points.size();
		if (k<=0) return res;
		if (k>n) return points;

		vector<pair<int,int>> d(n);
		for (int i=0; i<n; i++) d[i]={dist(points[i], origin), i};

		int l=0, r=n-1;
		int pivotIndex;
		while (1) {
			pivotIndex=rand()%(r-l+1)+l;
			pivotIndex=partition(d, l, r, pivotIndex);
			if (pivotIndex==k-1) break;
			else if (pivotIndex>k-1) r=pivotIndex-1;
			else l=pivotIndex+1;
		}

		for (int i=0; i<=pivotIndex; i++) res.push_back(points[d[i].second]);
		return res;
	}
 };

int main()
{
	Solution s;
	Point origin(1,1);
	vector<Point> points={Point(1, 1), Point(2, 3),
			Point(-1, 5), Point(3, 3), Point(2, 2),
			Point(4, -1), Point(5, -3)};
	vector<Point> res=s.findClosestKPoints(points, origin, 2);
	for (int i=0; i<res.size(); i++) {
		cout << res[i].x << " " << res[i].y << endl;
	}
	return 0;
}

