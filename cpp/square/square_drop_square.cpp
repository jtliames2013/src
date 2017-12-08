1. 不停地增加squares，表示成 (float x, float size) , 只要有重叠，新的方块会积在旧方块上， 最后实现 getHight(float x)， 这题目是面经里电面题，就没准备。看着简单，写起来巨烦，最后跑是跑出来了，但是感觉还是有bug, 目测跪在了这一题。

是写一个function, drop(double position, double size), 即从高处掉一个方块，左边的x坐标是position，方块的边长是size。然后它会一个个叠起来。
比如drop(1,4), drop(3,3)的话就会变成这样：
   bbb
   bbb
   bbb
aaaa
aaaa
aaaa. 
aaaa

然后它掉一大堆方块下来之后任何时候想要call一个叫getHeight()的function的话，你就得返回这堆方块里地最高点（但getHeight在面试中没有写，面试官只叫我写了drop）

我就用map做了，做完后面试官说可以用tree，这样可以更加efficient。我感觉他那个方法还是没太懂。。。有没有大神来解释一下。。

square的经典题目，drop square. 
就是实现drop(double x, double size) 和getHeight(double x) 

用了Intervel的思路，就是mergeInterval的时候比较繁琐。Followup问怎么提高mergeInterval, 面试官提示用BST. 时间就差不多了

struct Interval {
	float start;
	float end;
	float height;
	Interval(float s, float e, float h): start(s), end(e), height(h) {}
};

class Solution {
public:
	void drop(float x, float size) {
		vector<Interval> res;
		int pos=0;
		float height=0;
		for (int i=0; i<intervals.size(); i++) {
			if (x>=intervals[i].end) {
				res.push_back(intervals[i]);
				pos++;
			} else if (x+size<=intervals[i].start) {
				res.push_back(intervals[i]);
			} else {
				if (x>intervals[i].start) {
					res.push_back(Interval(intervals[i].start, x, intervals[i].height));
					pos++;
				}
				if (x+size<intervals[i].end) {
					res.push_back(Interval(x+size, intervals[i].end, intervals[i].height));
				}
				height=max(height, intervals[i].height);
			}
		}

		res.insert(res.begin()+pos, Interval(x, x+size, height+size));
		intervals=res;
	}

	float getHeight(float x) {
		for (int i=0; i<intervals.size(); i++) {
			if (x>=intervals[i].start && x<=intervals[i].end) {
				return intervals[i].height;
			}
		}

		return 0;
	}
private:
	vector<Interval> intervals;
};

int main() {
	Solution s;
	s.drop(0, 3);
	s.drop(4, 5);
	s.drop(2, 6);

	cout << s.getHeight(1.5) << endl;
	cout << s.getHeight(3.5) << endl;
	cout << s.getHeight(8.5) << endl;
	return 0;
}

