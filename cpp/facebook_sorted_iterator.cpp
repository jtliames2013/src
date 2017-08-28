第二题有点像有序双链表合并，不过给的是两个iterator，让实现一个类，生成下一个.
class SortedIterator{
    public SortedIterator(Iterator a, Iterator b);
    public boolean hasNext();
    public int next();
}

class SortedIterator {
public:
	struct Peek {
		int val;
		bool hasNext;
		Iterator iter;
		Peek():val(0), hasNext(false) {}
	};

	SortedIterator(Iterator a, Iterator b) {
		pa.iter=a;
		pb.iter=b;
		advance(pa);
		advance(pb);
	}

	void advance(Peek& p) {
		if (p.iter.hasNext()) {
			p.hasNext=true;
			p.val=p.iter.next();
		} else {
			p.hasNext=false;
		}
	}

	bool hasNext(){
		return pa.hasNext || pb.hasNext;
	}

	int next() {
		if (!hasNext()) return 0;
		if (pa.hasNext==false) {
			int res=pb.val;
			advance(pb);
			return res;
		} else if (pb.hasNext==false) {
			int res=pa.val;
			advance(pa);
			return res;
		} else {
			int res;
			if (pa.val<pb.val) {
				res=pa.val;
				advance(pa);
			} else {
				res=pb.val;
				advance(pb);
			}
			return res;
		}
	}

private:
	Peek pa;
	Peek pb;
};

