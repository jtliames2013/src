Airbnb: Rectangle
You have a plain with lots of rectangles on it, find out how many of them intersect.

  struct Point {
       int x;
       int y;
  };

  struct Rect {
	  Point lb;
	  Point rt;
  };

class Solution {
public:
	  bool isOverlap(Point lb1, Point rt1, Point lb2, Point rt2) {
		  if (lb1.x>rt2.x || lb2.x>rt1.x) return false;
		  if (lb1.y>rt2.y || lb2.y>rt1.y) return false;

		  return true;
	  }

	  int findIntersect(vector<Rect> rects) {
		  int res=0;
		  sort(rects.begin(), rects.end(), [](Rect a, Rect b) { return a.lb.x<b.lb.x;});

		  for (int i=0; i<rects.size(); i++) {
			  int x=rects[i].rt.x;
			  int l=i+1, r=rects.size()-1;
			  while (l<=r) {
				  int mid=(l+r)/2;
				  if (rects[mid].lb.x>=x) r=mid-1;
				  else l=mid+1;
			  }
			  for (int k=i+1; k<=r; k++) {
				  if (isOverlap(rects[i].lb, rects[i].rt, rects[k].lb, rects[k].rt)) {
					  res++;
				  }
			  }
		  }
		  return res;
	  }
  };

int main() {
	vector<Rect> r={{{1,1},{3,3}}, {{2,2},{4,4}}, {{3,2},{5,5}}};
	Solution s;
	int res=s.findIntersect(r);
	return 0;
}

