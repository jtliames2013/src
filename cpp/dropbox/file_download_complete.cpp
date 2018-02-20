1. 给一堆Chunk和一个file size,问给定的一堆Chunk能不能组成complete file.
Chunk就是一个左开右闭的区间, 如[0, 4)表示这个chunk包含0, 1, 2, 3这4个byte. 给定的size是这个文件大小.
boolean isCompleteFile(List<Chunk> chunks, int size)
例如:.
chunks = [[0, 1), [1, 3), [3, 4)]  size = 4   => 结果是true
chunks = [[0, 1), [1, 3), [3, 4)]  size = 5   => 结果是false
chunks = [[0, 1), [2, 3), [3, 4)]  size = 4   => 结果是false.1point3acres缃�
.2. 实现一个ChunkManager class, 实现一个函数, isCompleteForNow(Chunk chunk), 每call一次这个函数,就会把chunk更新到这个类中,并判断当前类中已经有的list of chunk可不可以组成一个complete file
例如:
ChunkManager chunkManager = new ChunkManager(4);
chunkManager.isCompleteForNow([0, 2)); -> false
chunkManager.isCompleteForNow([2, 3)); -> true

download bit-torrent. 第一題基本上就是merge intervals。後來是interval連續進入，寫了一個binary search找位置然後linear update. 寫完後考慮要問演算法(猜測是用樹來解這題)或是system，選了system.結果問如果真的download這些paritial file後要怎麼merge real files

bitTorent：第一问很常规，很快写出来了，分析了下复杂度，然后followup，很快又想出来了，但是让优化，没想出来，然后最后一看时间来不及了，匆忙写了下我那个方法，后来被告知要用平衡树

给一堆Chunk和一个file size,问给定的一堆Chunk能不能组成complete file.
Chunk就是一个左开右闭的区间, 如[0, 4)表示这个chunk包含0, 1, 2, 3这4个byte. 给定的size是这个文件大小.
boolean isCompleteFile(List<Chunk> chunks, int size)
例如:
chunks = [[0, 1), [1, 3), [3, 4)]  size = 4   => 结果是true
chunks = [[0, 1), [1, 3), [3, 4)]  size = 5   => 结果是false
chunks = [[0, 1), [2, 3), [3, 4)]  size = 4   => 结果是false
我的思路是联系到lc的merge interval那题。
followup是建一个class接收one block at a time，所以不是一下子拿到所有的chunk让你来比较，自己定一个data structure来存chunks。
class Downloader {
    public Downloader(int size) {
    // save size somewhere  }

  public void addBlock(Range r) {
    // TODO: implement   }

  public boolean isDone() {
    // TODO: implement   }
}

struct Interval {
	int start;
	int end;
	Interval(int s, int e):start(s), end(e) {}
};

struct Comp {
	bool operator()(Interval a, Interval b) {
		return a.start < b.start;
	}
};

class Downloader1 {
public:
	bool isComplete(vector<Interval> intervals, int size) {
		int n=intervals.size();
		if (n==0) return false;
		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.start<b.start;});
		int back=0;
		for (int i=1; i<n; i++) {
			if (intervals[back].end<intervals[i].start) {
				intervals[++back]=intervals[i];
			} else {
				intervals[back].end=max(intervals[back].end, intervals[i].end);
			}
		}
		return intervals[0].start<=0 && intervals[0].end>=size;
	}
};

class Downloader2 {
public:
	Downloader2(int size) {
		this->size=size;
	}

	void addInterval(Interval interval) {
		auto iter=intervals.lower_bound(interval);
		while (iter!=intervals.end()) {
			if (iter->start>interval.end) break;
			interval.end=max(interval.end, iter->end);
			iter=intervals.erase(iter);
		}
		while (iter!=intervals.begin()) {
			if ((--iter)->end<interval.start) break;
			interval.start=min(interval.start, iter->start);
			iter=intervals.erase(iter);
		}

		intervals.insert(interval);
	}

	bool isComplete() {
		return intervals.begin()->start<=0 && intervals.begin()->end>=size;
	}
private:
	int size;
	set<Interval, Comp> intervals;
};

int main() {
	Downloader1 d1;
	vector<Interval> i1={Interval(3,7), Interval(0,1), Interval(2,5), Interval(6,8)};
	// false
	cout << d1.isComplete(i1, 8) << endl;
	vector<Interval> i2={Interval(3,7), Interval(0,2), Interval(2,5), Interval(6,8)};
	// true
	cout << d1.isComplete(i2, 8) << endl;
	cout << endl;

	Downloader2 d2(20);
	d2.addInterval(Interval(2,8));
	// false
	cout << d2.isComplete() << endl;
	d2.addInterval(Interval(16,20));
	// false
	cout << d2.isComplete() << endl;
	d2.addInterval(Interval(6,10));
	// false
	cout << d2.isComplete() << endl;
	d2.addInterval(Interval(11,15));
	// false
	cout << d2.isComplete() << endl;
	d2.addInterval(Interval(1,19));
	// false
	cout << d2.isComplete() << endl;
	d2.addInterval(Interval(0,3));
	// true
	cout << d2.isComplete() << endl;

	return 0;
}

