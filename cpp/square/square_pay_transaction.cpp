店面就一轮，顺便问问有没有更好的思路，算是设计题目，第一问就是一堆人出去玩，吃饭或者什么的，有人先付钱，其他人欠着，最后求每个人的balance.
比如 person A,B,C
Transaction 1 is 12$, A pays for A,B,C
Transaction 2 is 10$, B pays for A,B

那么最后balance就是
A: -3
B: -1
C: 4 (C需要给A,B各1元和3元)

设计数据结构和打印出每个人的balance.

第二问是打印出谁应该给谁多少钱，比如上例中，应该是

C gives 1 to B
C gives 3 to A.

第一问没什么好说的，第二问的时间复杂度是可以做到o(n)的，我想的是维持两个queue,一个是欠钱的，一个是收钱的，队首print，然后balance清零出队。不知道有没有更好的思路。

struct Transaction {
	string name;
	float total;
	vector<string> attendee;
	Transaction(string s, float t, vector<string> a):name(s), total(t), attendee(a) {}
};

class Solution {
public:
	void processTransaction(vector<Transaction> transactions) {
		for (auto t:transactions) {
			float avg=t.total/t.attendee.size();
			for (auto att:t.attendee) {
				if (att!=t.name) {
					people[att][t.name]+=avg;
					people[t.name][att]+=-avg;
				}
			}
		}
	}

	void printBalance() {
		for (auto p:people) {
			int sum=0;
			for (auto b:p.second) {
				sum+=b.second;
			}
			cout << p.first << " " << sum << endl;
		}
	}

	void printTransaction() {
		for (auto p:people) {
			for (auto b:p.second) {
				if (b.second>0) {
					cout << p.first << "->" << b.first <<  " " << b.second << endl;
				}
			}
		}
	}
private:
	map<string, map<string, float> > people;
};

int main(int argc, char** argv) {
	Solution s;
	vector<Transaction> transactions={Transaction("A", 12, {"A", "B", "C"}),
									  Transaction("B", 10, {"A", "B"})};
	s.processTransaction(transactions);
	s.printBalance();
	s.printTransaction();

	return 0;
}

