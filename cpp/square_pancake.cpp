2. 
a. 一堆 pancakes, 根据大小排序，但是要先 implement swap(List<Pancake> pancakes, int end),  把从 index 0 ~ end 的pancakes的顺序全部倒过来，然后用这个方法正常排序pancakes, 最后size 从小到大。

比如 {3, 2, 5, 4, 6}  swap(pancakes, 3) 之后是 {4, 5, 2, 3, 6} implement 一个方法 不停地 swap 得到 {2, 3, 4, 5, 6}, 数字表示对应 pancake size. 

b. 也是一堆 pancakes, 现在有两面，有的是正面朝下，有的是反面朝下，也是implement swap(List<Pancake> pancakes, int end), 把从 index 0 ~ end 的pancakes的顺序全部倒过来，同时对应的面也要反过来， 最后要得到的结果是全部正面朝上。


比如 T 表示正面朝上，F 表示反面朝上。


{T, F, F, F, T},  swap(pancakes, 3) 之后 是 {T, T, T, F, T}, 最后用swap 方法，最终得到{T, T, T, T, T}

struct Pancake {
	int size;
	bool up;
	Pancake(int s, bool u): size(s), up(u) {}
};

class Solution {
public:
	void swapPancake(vector<Pancake>& pancakes, int end) {
		int l=0, r=end;
		if (l==r) {
			pancakes[l].up=!pancakes[l].up;
		} else {
			while (l<r) {
				swap(pancakes[l], pancakes[r]);
				pancakes[l].up=!pancakes[l].up;
				pancakes[r].up=!pancakes[r].up;
				l++;
				r--;
			}
		}
	}

	void swapSort(vector<Pancake>& pancakes) {
		for (int i=pancakes.size()-1; i>0; i--) {
			int maxval=INT_MIN;
			int maxidx=0;
			for (int j=0; j<=i; j++) {
				if (maxval<pancakes[j].size) {
					maxval=pancakes[j].size;
					maxidx=j;
				}
			}
			swapPancake(pancakes, maxidx);
			swapPancake(pancakes, i);
		}
	}

	void swapFlip(vector<Pancake>& pancakes) {
		for (int i=pancakes.size()-1; i>=0; i--) {
			if (pancakes[i].up==false) {
				if (pancakes[0].up==true) {
					swapPancake(pancakes, 0);
				}
				swapPancake(pancakes, i);
			}
		}
	}
};

int main() {
	vector<Pancake> pancakes={Pancake(3, true), Pancake(2, false), Pancake(5, false), Pancake(4, false), Pancake(6, true)};
	Solution s;
	s.swapFlip(pancakes);
	//s.swapSort(pancakes);

	return 0;
}

