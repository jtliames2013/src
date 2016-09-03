题目较长, 理解题意花了不少时间， 趁着还记得简短地说一下(交流很重要，有些信息题目里没有明说):
大意是实现一个game simulator:
Objective:
收集最多价值的宝藏，在氧气耗尽前返回base.


Description:
有一个长度为25的一维地图，base在index0处， 剩下24个index分别放着价值1～24的宝藏. 两个玩家从base为起点同时进行游戏, 每个玩家初始时有一个容量为20的氧气瓶, 玩家有三个状态: 1.目前的位置 2. 朝向 3.背着的宝藏的价值. 


Rules:
1. 如果oxygen剩余<0, 玩家没回到base. 玩家丢弃保障，得分为0，game over.
2. 如果玩家回到base且oxygen剩余量>=0. 得分=宝藏价值
3. 氧气消耗量 ＝ 身上宝藏的价值.
4. 每一个时刻玩家都可以选择掉头回家.
5. 玩家每走到一个position会捡起此position对应价值的宝藏
6. 玩家每次的位移 ＝ max(0, rand(2,6)) - 身上宝藏的价值. 
7. 如果某position的宝藏被拿走了，则下一次经过这个position时, 玩家身上的宝藏的价值不会增加


Requirement:
自由设计class, simulate游戏过程, 最后暴露一个方法getWinner(), 返回得分高的玩家.

struct Player {
	int pos;
	int oxygen;
	int treasure;
	Player():pos(0), oxygen(20), treasure(0) {}
};

#define NUM 25

class Solution {
public:
	Solution(vector<int>& treasures) {
		this->treasures=treasures;
	}

	void play(int player, int offset) {
		int start, end;
		if (offset>0) {
			start=players[player].pos;
			end=players[player].pos+offset;
			if (end >=NUM) end=NUM-1;
		} else {
			start=players[player].pos+offset;
			end=players[player].pos;
			if (start<=0) start=0;
		}

		for (int i=start; i<=end; i++) {
			players[player].treasure+=treasures[i];
			treasures[i]=0;
			players[player].oxygen-=players[player].treasure;
		}
	}

	int getWinner() {
		if (players[0].oxygen>0 && players[1].oxygen>0) {
			return players[0].treasure>players[1].treasure?1:2;
		} else if (players[0].oxygen>0) {
			return 1;
		} else if (players[1].oxygen>0) {
			return 2;
		} else {
			return 0;
		}
	}

private:
	vector<int> treasures;
	Player players[2];
};

int main(int argc, char** argv) {
	vector<int> treasures(NUM, 0);
	for (int i=1; i<NUM; i++) {
		treasures[i]=rand()%10;
	}
	Solution s(treasures);

	return 0;
}

