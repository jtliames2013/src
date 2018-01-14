也就是strstr匹配.. 反正中间写得也不行，怎么读file也随便写.. 最后抓住机会题了用hash code的方法，减掉最前面的，加上新加的byte算出来的hashcode..如果一样的话，再strstr匹配就行.. 问了下复杂度

判断文件里是否含有一个字符串。字符串可以含有/n等一切可能
给一个文件和一个byte数组，判断这个byte数组是否在文件里出现过？本质是字符串匹配，然而不同的是文件可能很大，不能一次性读进内存。我是假设了一个常量表示了内存分配给我（要解释为什么需要这个常量），创建一段buffer，一开始将它填满，然后匹配buffer和byte数组（过程就和字符串匹配一样，我是用最蠢的办法），配不上的话，将最后的（byte数组长度-1）个byte移到buffer前端，然后继续读文件更新buffer剩下的部分，再次匹配，重复这个过程知道文件到尾或者匹配成功。写完后出了两个bug，在面试官提示下修复了，不是自己找出来的= = 然后是followup，提高时间效率，我说用KMP？他说我不期望你用KMP，那是有点research的方法。我又想了一下，他给我hint说你知道rollinghash吗？我说不知道= =他就跟我简单解释了一下，就是一个byte数组有一个hash值，然后当删除一个前端的byte或者添加一个新的byte在末尾的时候，可以通过运算在O(1)时间内算出新的hash值。然后就给我一个class rollinghash，三个方法addbyte,removebyte,hash，叫我根据这个改代码。改完之后（这一次应该没有bug了= =），他问我有什么好方法可以实现这个hash函数吗（要求当然就是rollinghash这个类里的三个方法都是常数复杂度），不要求unique，但尽量要求不同？我说XOR每个byte？每个byte相加？他说可以，然后他说了一个他们在用的办法：设一个常数a，假设byte数组是bytes[0:n-1]，那么hash值为a^(n-1)*byte[n-1]+a^(n-2)*byte[n-2]+...+a^0*byte[0]-

判断一个 byte[] array是否存在在一个file里面
一开始用了很没有效率到方法。
后来在面试哥哥到提示下。才想到用hash。
最后又在面试哥哥的提示下。用了rolling hash。（其实我根本不知道rolling hash这种东西）
哥哥让我自己设计rolling hash的interface。然后拿来用

class Solution {
public:
	bool matchFile(string infile, char pattern[]) {
		streampos size;
		char *buf;
		ifstream file(infile, ios::in|ios::binary|ios::ate);
	    if (file.is_open())
	    {
	    	size = file.tellg();
	    	buf = new char [size];
	    	file.seekg (0, ios::beg);
			file.read(buf, size);
			bool b=match(buf, size, pattern, strlen(pattern));

			file.close();
			delete[] buf;
			return b;
	    } else {
	    	return false;
	    }
	}

private:
	/*bool match(char buf[], int blen, char pattern[], int plen) {
		for (int i=0; i<=blen-plen; i++) {
			int j=0;
			for (; j<plen; j++) {
				if (buf[i+j]!=pattern[j]) break;
			}
			if (j==plen) return true;
		}
		return false;
	}*/

	bool match(char buf[], int blen, char pattern[], int plen) {
		//hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
		//hash( txt[s .. s+m-1] ) : Hash value at shift s.
		//hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
		//d: Number of characters in the alphabet
		//q: A prime number
		//h: d^(m-1)
		const int d=256;
		const int q=101;
		long h=1;
		long phash=0;
		long bhash=0;
		for (int i=0; i<plen-1; i++) h=(h*d)%q;

		for (int i=0; i<plen; i++) {
			phash=(d*phash+pattern[i])%q;
			bhash=(d*bhash+buf[i])%q;
		}

		for (int i=0; i<=blen-plen; i++) {
			if (phash==bhash) {
				int j=0;
				for (; j<plen; j++) {
					if (pattern[j]!=buf[i+j]) break;
				}
				if (j==plen) return true;
			}

			if (i<blen-plen) {
				bhash=(d*(bhash-buf[i]*h)+buf[i+plen])%q;
				// bhash might be negative now, so add modulus
				if (bhash<0) bhash+=q;
			}
		}

		return false;
	}
};

int main() {
	Solution s;
	cout << s.matchFile("test.bin", "abcdef") << endl;
	return 0;
}

