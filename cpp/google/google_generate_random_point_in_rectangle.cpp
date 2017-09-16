给一个平行于x轴的矩形，要求随机生成一个矩形内的坐标点。follow up：给一堆不相交的平行于x轴的矩形。要求随机生成一个坐标点在任意一个矩形内。落在某一个矩形内的概率和矩形面积成正比。

struct Rect {
	int x1;
	int y1;
	int x2;
	int y2;
	Rect(int a, int b, int c, int d):x1(a), y1(b), x2(c), y2(d) {}
};

class Solution {
public:
	pair<int,int> randomOne(Rect rect) {
		int rows=rect.y2-rect.y1+1;
		int cols=rect.x2-rect.x1+1;
		int idx=rand()%(rows*cols);
		return {rect.x1+idx%cols, rect.y1+idx/cols};
	}

	pair<int,int> randomMultiple(vector<Rect> rectangles) {
		int n=rectangles.size();
		vector<int> sum(n);
		for (int i=0; i<n; i++) {
			int rows=rectangles[i].y2-rectangles[i].y1+1;
			int cols=rectangles[i].x2-rectangles[i].x1+1;
			sum[i]+=rows*cols;
		}
		int idx=rand()%sum[n-1];
		int j=0;
		for (; j<n; j++) {
			if (idx<sum[j]) break;
		}
		// binary search for j, the first sum that greater than j
		//int l=0, r=n-1;
		//while (l<r) {
		//	int mid=l+(r-l)/2;
		//	if (sum[mid]<idx) l=mid+1;
		//	else r=mid;
		//}

		int rows=rectangles[j].y2-rectangles[j].y1+1;
		int cols=rectangles[j].x2-rectangles[j].x1+1;
		idx-=j==0?0:sum[j-1];
		return {rectangles[j].x1+idx%cols, rectangles[j].y1+idx/cols};
	}
};

