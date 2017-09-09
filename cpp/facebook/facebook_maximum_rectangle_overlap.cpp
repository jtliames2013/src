几何算法问题。如果给你一堆的矩形， 求重合矩形重合最多的坐标位置。我上过一个算法课，大概思路就是做一个二维的meeting room II.

class Solution {
public:
	struct Rect {
		// up left
		int x0;
		int y0;
		// down right
		int x1;
		int y1;
		Rect(int a0, int b0, int a1, int b1):x0(a0), y0(b0), x1(a1), y1(b1) {}
	};

	enum Horizontal {
		left,
		mid,
		right,
	};
	enum Vertical {
		top,
		mid,
		bottom,
	};

	struct Pair {
		int index;
		Horizontal hor;
		Vertical ver;
		Pair(int i, Horizontal h, Vertical v):index(i), hor(h), ver(v) {}
	};

	Rect findMaximalOverlap(vector<Rect> rectangles) {
		unordered_map<int, vector<Pair>> indexToLine;
		for (auto& rect:rectangles) {
			indexToLine[rect.x0].push_back(Pair(rect.y0, left, top));
			indexToLine[rect.x0].push_back(Pair(rect.y1, left, bottom));
			indexToLine[rect.x1].push_back(Pair(rect.y0, right, top));
			indexToLine[rect.x1].push_back(Pair(rect.y1, right, bottom));
		}

		for (auto& rect:rectangles) {
			for (int index=rect.x0+1; index<rect.x1; index++) {
				if (indexToLine.find(index)!=indexToLine.end()) {
					indexToLine[index].push_back(Pair(rect.y0, mid, top));
					indexToLine[index].push_back(Pair(rect.y1, mid, bottom));
				}
			}
		}

		for (auto& iter:indexToLine) {
			// sort from top to bottom
			sort(iter.second.begin(), iter.second.end(), [](Pair& p1, Pair& p2) {return p1.index>p2.index || (p1.index==p2.index && p1.ver==bottom);});
		}

		Rect overlap=Rect(0,0,0,0);
		int maxOverlap=0;
		for (auto& iter:indexToLine) {
			int l=0, r=0;
			for (auto& pair:iter.second) {
				if (pair.ver==top) {
					if (pair.hor==mid || pair.hor==left) {
						r++;
						if (r>maxOverlap) {
							overlap.x0=iter.first;
							overlap.y0=pair.index;
							maxOverlap=r;
						}
					}
					if (pair.hor==mid || pair.hor==right) {
						l++;
					}
				} else {
					if (pair.hor==mid || pair.hor==right) {
						if (l==maxOverlap) {
							overlap.x1=iter.first;
							overlap.y1=pair.index;
							maxOverlap=r;
						}
						l--;
					}
					if (pair.hor==mid || pair.hor==left) {
						r--;
					}
				}
			}
		}
		return overlap;
	}
};

