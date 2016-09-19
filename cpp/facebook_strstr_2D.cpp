大意就是把第一个haystack参数变成一个二维数组，然后找needle在haystack第一次出现的位置，同样的不能用string相关方法，还是返回把haystack[][]二维数组看成一维以后的第一次匹配的字符下标，举例：haystack := [[a,b,c,c], [c,b,d]], needle := [c,c,b,d] , return 2; needle := [b, d] return 5 (5是把haystack看成一维的以后的找到第一个bd以后b的下标)。

class Solution {
public:
	bool needleHasNext() {
		return needleRow<haySize;
	}

	void tryNeedleAdvance() {
		while (needleRow<haySize) {
			if (needleCol<haystack[needleRow].size()) break;
			needleRow++;
			needleCol=0;
		}
	}

	bool hayHasNext() {
		return hayRow<haySize;
	}

    void tryHayAdvance() {
    	while (hayRow<haySize) {
			if (hayCol<haystack[hayRow].size()) break;
			hayRow++;
			hayCol=0;
    	}
	}

    int strStr(vector<string> haystack, string needle) {
    	this->haystack=haystack;
    	haySize=haystack.size();
    	hayRow=hayCol=0;
    	int n=needle.size();
    	tryHayAdvance();
    	int index=0;

    	while (hayHasNext()) {
    		needleRow=hayRow;
    		needleCol=hayCol;
    		int i;
    		for (i=0; i<n; i++) {
    			if (!needleHasNext()) return -1;
    			if (needle[i]!=haystack[needleRow][needleCol]) break;
    			needleCol++;
    			tryNeedleAdvance();
    		}
    		if (i==n) return index;

    		hayCol++;
    		tryHayAdvance();
    		index++;
    	}

    	return -1;
    }
private:
    vector<string> haystack;
    int hayRow;
    int hayCol;
    int needleRow;
    int needleCol;
    int haySize;
};

int main()
{
	Solution s;
	vector<string> haystack;
	haystack.push_back("abcc");
	haystack.push_back("cbd");
	string needle="ccbd";
	//string needle="bd";
	//string needle="efg";
	int res = s.strStr(haystack, needle);
	cout << res << endl;
	return 0;
}

