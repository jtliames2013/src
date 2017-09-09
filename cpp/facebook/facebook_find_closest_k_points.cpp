struct Point {
	int x;
	int y;
	int dist;
	Point(int a, int b): x(a), y(b) {}
	Point(int a, int b, Point orig): x(a), y(b), dist(sqrt((a-orig.x)*(a-orig.x)+(b-orig.y)*(b-orig.y))) {}
};

class Compare {
public:
	bool operator()(Point a, Point b) {
		return a.dist<b.dist;
	}
};

class Solution {
public:
	vector<Point> findClosestKPoints(vector<Point> points, Point origin, int k) {
		vector<Point> res;
		priority_queue<Point, vector<Point>, Compare> pq;
		for (int i=0; i<points.size(); i++) {
			if (pq.size()<k) {
				pq.push(points[i]);
			} else {
				if (points[i].dist<pq.top().dist) {
					pq.pop();
					pq.push(points[i]);
				}
			}
		}

		while (!pq.empty()) {
			res.push_back(pq.top());
			pq.pop();
		}

		return res;
	}
 };

2. quick select
class Solution {
public:
	int partition(vector<Point> points, int l, int r, int pivot) {
		Point pivotValue=points[pivot];
		swap(points[r], points[pivot]);
		int index=l;
		for (int i=l; i<r; i++) {
			if (points[i].dist<pivotValue.dist) {
				swap(points[index], points[i]);
				index++;
			}
		}
		swap(points[index], points[r]);
		return index;
	}

	vector<Point> findClosestKPoints(vector<Point> points, int k) {
		vector<Point> res;
		int n=points.size();
		if (n==0) return res;
		int l=0, r=n-1;
		int pivotIndex;
		while (1) {
			if (l==r) {
				pivotIndex=l;
				break;
			}
			pivotIndex=rand()%(r-l+1)+l;
			pivotIndex=partition(points, l, r, pivotIndex);
			if (pivotIndex==k-1) break;
			else if (pivotIndex>k-1) r=pivotIndex-1;
			else l=pivotIndex+1;
		}

		for (int i=0; i<=pivotIndex; i++) res.push_back(points[i]);
		return res;
	}
 };

int main()
{
	Solution s;
	Point origin(1,1);
	vector<Point> points={Point(1, 1, origin), Point(2, 3, origin),
			Point(-1, 5, origin), Point(3, 3, origin), Point(2, 2, origin),
			Point(4, -1, origin), Point(5, -3, origin)};
	vector<Point> res=s.findClosestKPoints(points, origin, 2);
	for (int i=0; i<res.size(); i++) {
		cout << res[i].x << " " << res[i].y << endl;
	}
	return 0;
}

