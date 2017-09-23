给一个返回值依次为[A, C, C, C, D, D]的iterator, 要求返回另一个iterator, 这个新的iterator要能依次输出如下结果
[(A, 1), (C, 3), (D, 2)]

class Iterator {
public:
	Iterator() {
		data={'A', 'C', 'C', 'C', 'D', 'D'};
		i=0;
	}
	bool hasNext() {
		return i<data.size();
	}
	char next() {
		if (i<data.size());
		char res=data[i];
		i++;
		return res;
	}
private:
	vector<char> data;
	int i;
};

class Solution {
public:
	Solution() {
		count=1;
		if (iter.hasNext()) prev=iter.next();
		else prev='\0';
	}

	bool hasNext() {
		return iter.hasNext() || prev!='\0';
	}

	pair<char, int> next() {
		if (!iter.hasNext()) return {'\0', 0};
		char curr;
		while (1) {
			if (!iter.hasNext()) {
				curr='\0';
				break;
			} else {
				curr=iter.next();
				if (curr!=prev) break;
				count++;
			}
		}
		pair<char,int> res={prev, count};
		prev=curr;
		count=1;
		return res;
	}
private:
	Iterator iter;
	char prev;
	int count;
};

int main()
{
	Solution s;
	while (s.hasNext()) {
		pair<char,int> res=s.next();
		cout << res.first << " " << res.second << endl;
	}
	return 0;
}

