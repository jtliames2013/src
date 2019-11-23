587. Erect the Fence
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.

There are couple of ways to solve Convex Hull problem. https://en.wikipedia.org/wiki/Convex_hull_algorithms
The following code implements Gift wrapping aka Jarvis march algorithm https://en.wikipedia.org/wiki/Gift_wrapping_algorithm and also added logic to handle case of multiple Points in a line because original Jarvis march algorithm assumes no three points are collinear.
It also uses knowledge in this problem https://leetcode.com/problems/convex-polygon . Disscussion: https://discuss.leetcode.com/topic/70706/beyond-my-knowledge-java-solution-with-in-line-explanation


1.
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    struct myhash
    {
        size_t operator()(const Point& p) const
        {
            return (hash<int>{}(p.x)) ^ (hash<int>{}(p.y)<<1);
        }
    };
    
    struct myequal
    {
        bool operator()(const Point& a, const Point& b) const
        {
            return a.x==b.x && a.y==b.y;
        }
    };
        
    int crossProductLength(Point A, Point B, Point C) {
        // Get the vectors' coordinates.
        int BAx = A.x - B.x;
        int BAy = A.y - B.y;
        int BCx = C.x - B.x;
        int BCy = C.y - B.y;
    
        // Calculate the Z coordinate of the cross product.
        return (BAx * BCy - BAy * BCx);
    }

    int distance(Point p1, Point p2) {
        return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    }
    
    vector<Point> outerTrees(vector<Point>& points) {
        unordered_set<Point, myhash, myequal> st;
        // Find the leftmost point
        Point first=points[0];
        int firstIdx=0;
        for (int i=1; i<points.size(); i++) {
            if (points[i].x < first.x) {
                first=points[i];
                firstIdx=i;
            }
        }
        st.insert(first);
        
        Point curr = first;
        int currIdx = firstIdx;
        do {
            Point next=points[0];
            int nextIdx = 0;
            for (int i=1; i<points.size(); i++) {
                if (i==currIdx) continue;
                int cross = crossProductLength(curr, points[i], next);
                if (nextIdx == currIdx || cross > 0 ||
                    // Handle collinear points
                    (cross == 0 && distance(points[i], curr) > distance(next, curr))) {
                    next=points[i];
                    nextIdx = i;
                }
            }
            // Handle collinear points
            for (int i=0; i<points.size(); i++) {
                if (i==currIdx) continue;
                int cross = crossProductLength(curr, points[i], next);
                if (cross == 0) {
                    st.insert(points[i]);
                }
            }

            curr=next;
            currIdx = nextIdx;            
        } while (currIdx != firstIdx);        
        
        vector<Point> res;
        for (auto& p:st) res.push_back(p);
        return res;
    }
};

2.
http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull.cpp

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n=points.size(), k=0;
        vector<vector<int>> res(2*n);

        // Sort points lexicographically
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){ return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]); });

        // Build lower hull
        for (int i=0; i<n; ++i) {
            while (k>=2 && cross(res[k-2], res[k-1], points[i])<0) k--;
            res[k++]=points[i];
        }

        // Build upper hull
        for (int i=n-2, t=k+1; i>=0; --i) {
            while (k>=t && cross(res[k-2], res[k-1], points[i])<0) k--;
            res[k++]=points[i];
        }

        // Remove duplicates
        res.resize(k);
        sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b) { return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]); });
        res.erase(unique(res.begin(), res.end(), [](vector<int>& a, vector<int>& b) { return a[0]==b[0] && a[1]==b[1]; } ), res.end());

        return res;
    }
private:
    long cross(const vector<int>& O, const vector<int>& A, const vector<int>& B) {
        return (A[0]-O[0]) * (long)(B[1]-O[1])-
               (A[1]-O[1]) * (long)(B[0]-O[0]);
    }
};

