上來先請我解釋merge sort，問了time space complexity

follow up我們來逆向merge，也就是把一個array裡面的element還原到他們原本的subarray
假設每個element內有variable紀錄這個element是left subarray or right subarray 來的
請你把element還原到他們原本的subarray

寫完後follow up，假設我想用一個iterator來iterator這個array的所有left element 
請你implement這個iterator. 
ex: 1(L), 4(R), 6(R), 8(L), 9(R), 15(L) ,31(R)
第一次call get_next()得到1. 
第二次call get_next()得到8
第三次call get_next()得到15
第四次call get_next() throw exception

struct Element {
	int val;
	bool left;
	Element(int v, bool l):val(v), left(l) {}
};

class Solution {
public:
	Solution() {}

	Solution(vector<Element>& elements) {
		this->elements=elements;
		index=0;
		tryAdvance();
	}

	void moveLeft(vector<Element>& elements) {
		int left, right;
		for (right=0; right<elements.size(); right++) {
			if (elements[right].left==false) break;
		}
		for (left=right+1; left<elements.size(); left++) {
			if (elements[left].left==true) break;
		}

		while (left<elements.size()) {
			swap(elements[left], elements[right]);
			right++;
			while (left<elements.size()) {
				if (elements[left].left==true) break;
				left++;
			}
		}
	}

	void tryAdvance() {
		while (index<elements.size()) {
			if (elements[index].left==true) break;
			index++;
		}
	}

	bool hasNext() {
		return index<elements.size();
	}

	int next() {
		if (hasNext()) {
			int res=elements[index].val;
			index++;
			tryAdvance();
			return res;
		} else {
			return -1;
		}
	}

private:
	vector<Element> elements;
	int index;
};

int main() {
	Solution s;
	vector<Element> elements={Element(1,true),Element(4,false),Element(6,false),Element(8,true),Element(9,false),Element(15,true),Element(31,false)};
	s.moveLeft(elements);

	vector<Element> elements2={Element(1,true),Element(4,false),Element(6,false),Element(8,true),Element(9,false),Element(15,true),Element(31,false)};
	Solution s2(elements2);
	while (s2.hasNext()) {
		cout << s2.next() << endl;
	}

	return 0;
}

