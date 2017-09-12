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

Use a sweep line approach to reduce the dimensionality of the problem.  Each rectangle will have two events: one when it enters the sweep line and one when it exits the sweep line.  

Now note that at each point, there is some set of rectangles intersecting the sweep line.  Thus, we are now looking the one-dimensional version of the problem.  Each rectangle defines an interval on the sweep line and we want to find the point on the sweep line which is contained in the maximum number of intervals.  

The most obvious way to do this is to again use a sweep line.  Let each interval on the first sweep line have an enter and an exit event.  Our second sweep line goes through each event in order, keeping track of how many intervals are intersecting it.  It returns the point at which this number is at a maximum.  

This approach requires O(nlogn)O(nlog⁡n) time for each one-dimensional problem.  Since there are O(n)O(n) events for the first sweep line, there are O(n)O(n) iterations, resulting in a runtime of O(n2logn)O(n2log⁡n).

Clearly we can do better - we are not taking advantage of the first sweep line at all!

Instead of resolving the one-dimensional problem at each event, we should simply update our solution to the one-dimensional problem.  Here's how.  Note that at any point there are O(n)O(n) intervals in our one-dimensional problem.  These segment the sweep line into O(n)O(n) disjoint intervals.  We only need to keep track of these intervals and, for each interval, keep track of how many rectangles contain it.  Once we solve this once it is easy to update it when a rectangle enters or exits.  Whenever a rectangle enters or exits, O(1)O(1) intervals are created, O(1)O(1) intervals are destroyed (or joined together), and a number of intervals in a range have their counts incremented or decremented.  

I imagine there are a number of ways to implement something like this.  For now, what comes to my mind are splay trees.  We represent each interval as a node in the splay tree, with the count as its key.  Insertion and deletion are O(logn)O(log⁡n) amortized.  The tricky part is incrementing or decrementing the keys of a range of nodes efficiently.  We can do this by a neat trick: augment each node with an 'extra' field, which denotes how much to add to the keys of the nodes in its subtree.  It can be shown that maintaining this field does not change the amortized runtime.  With this field, we can increment or decrement a range of nodes by first putting the nodes all in one subtree (splay the min of the subtree, split it off the main tree, then splay the max of the subtree, split it off), updating the 'extra' field of its root, and then joining the trees into one again.

Now, each event for the sweep line takes amortized O(logn)O(log⁡n) leading to the desired O(nlogn)O(nlog⁡n) complete runtime.
