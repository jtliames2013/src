给定N, a, b. 打印所有小于N的能被a或b整除的数
如 7, 2, 3, 输出:
2, 2
3, 3
4, 2
6, 2, 3

void printSeq(int n, int a, int b) {
	int i=0, i1=0, i2=0;
	vector<int> res={1};
	while (1) {
		int num=min(res[i1]*a, res[i2]*b);
		if (num>n) break;
		if (num==res[i1]*a) i1++;
		if (num==res[i2]*b) i2++;
		res.push_back(num);
	}
	for (int i=1; i<res.size(); i++) cout << res[i] << " ";
	cout << endl;
}

int main()
{
	printSeq(100, 2, 3);
	return 0;
}

