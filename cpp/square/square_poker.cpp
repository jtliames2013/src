skype面试，题目分5部分。一开始是54张扑克牌按1-52（就是每张牌都有自己的编号）, JokerA, JokerB排好。
1. 把JokerA往下移一张，如果JokerA已经是最后一张牌，那把JokerA放到第二张
2. 把JokerB往下移两张
3. 两张Joker把所有牌分成3部分，把第一部分和第三部分交换一下. 
4. 获取最后一张牌的编号，然后把相对应数量的牌从牌堆的上方移到牌堆的下方，但最后一张牌不变。比如一开始是1,2,5, 6........10, 9, 3，那经过这一步就变成6.....10,9,1,2,5,3-google 1point3acres
5. 获取第一张牌的编号，跳过编号数量的牌后，把后一张牌的编号输出相对应的字母。比如牌堆一开始是2,3,4,5的话，就跳过2和3，4对应的字母是D，那就输出D。如果第一张是大小王或者要输出的那张牌是大小王的话就跳过这一轮，从第一步开始重新做。

最后就是它给你一个数字，比如25，你就要用这个方法输出一个长度是25的string。

题其实挺简单的完全没有什么坑。就是第一次做这种让实时compile然后输出结果的电面还蛮紧张的0.0 不过成功过啦~ 半小时内就来通知二面了

#define NUM 54
#define JOKERA 53
#define JOKERB 54

class Solution {
public:
	void playcard(vector<int>& cards) {
		vector<int> data=cards;
		vector<int> tmp;
		while (1) {
			int idxA=-1, idxB=-1;
			for (int i=0; i<NUM; i++) {
				if (data[i]==JOKERA) idxA=i;
				if (data[i]==JOKERB) idxB=i;
				if (idxA!=-1 && idxB!=-1) break;
			}

			int newIdxA=(idxA+2)%NUM;
			data.erase(data.begin()+idxA);
			if (newIdxA>idxA) {
				data.insert(data.begin()+newIdxA-1, JOKERA);
			} else {
				data.insert(data.begin()+newIdxA, JOKERA);
			}

			int newIdxB=(idxB+3)%NUM;
			data.erase(data.begin()+idxB);
			if (newIdxB>idxB) {
				data.insert(data.begin()+newIdxB-1, JOKERB);
			} else {
				data.insert(data.begin()+newIdxB, JOKERB);
			}

			int idx1=min(newIdxA, newIdxB);
			int idx2=max(newIdxA, newIdxB);

			tmp.clear();
			for (int i=idx2+1; i<NUM; i++) {
				tmp.push_back(data[i]);
			}
			for (int i=idx1; i<=idx2; i++) {
				tmp.push_back(data[i]);
			}
			for (int i=0; i<idx1; i++) {
				tmp.push_back(data[i]);
			}
			data=tmp;

			int idx=data[NUM-1];
			tmp.clear();
			for (int i=idx; i<NUM-1; i++) {
				tmp.push_back(data[i]);
			}
			for (int i=0; i<idx; i++) {
				tmp.push_back(data[i]);
			}
			if (idx<NUM) tmp.push_back(data[NUM-1]);
			data=tmp;

			int val=data[0];
			if (val==JOKERA || val==JOKERB) continue;
			if (data[val]==JOKERA || data[val]==JOKERB) continue;
			cout << (char)('A'+data[val]-1) << endl;
			break;
		}
	}
};

int main(int argc, char** argv) {
	vector<int> cards;
	for (int i=1; i<=NUM; i++) cards.push_back(i);
	Solution s;
	s.playcard(cards);

	return 0;
}

