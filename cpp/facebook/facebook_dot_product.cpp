22. Dot Product.
   A={a1, a2, a3,...}
   B={b1, b2, b3,...}
   dot_product = a1 * b1 + a2 * b2 + a3 * b3 ＋。。。
   如果数组很稀疏，例如-google 1point3acres
   A={a1, ...., a300, ...., a5000}. more info on 1point3acres.com
   B={...., b100, ..., b300, ..., b1000, ...}
  里面有很多0，用什么数据结构表示能节省空间。我开始说用hashmap，但是hashmap不能做有顺序的iteration。然后改用list和array，两个都可以。后面做题的时用的array。. visit 1point3acres.com for more.
  题目是：
  input A=[[1, a1], [300, a300], [5000, a5000]]
          B=[[100, b100], [300, b300], [1000, b1000]]. 鍥磋鎴戜滑@1point 3 acres
  求 dot product. 问了时间复杂度。
  Follow up:
  如果length(B) >>> length(A)，即B非常长，怎么做能减少时间复杂度。对A里面的每个数，用binary search找B中相对应的值，这样时间复杂度是O(nlogm) (n = len(A), m =len(B)).时间不够没写代码， 就说了一下思路和复杂度。
   
  第三题的输入就是稀疏数组的非0的数列出来了，A=[[1, a1], [300, a300], [5000, a5000]]的意思就是A中第1个数是a1,第300个是a300,第5000个是a5000，其他都是0.

class Solution {
public:
	int dotProduct(vector<pair<int,int>> a, vector<pair<int,int>> b) {
		int res=0, m=a.size(), n=b.size(), i=0, j=0;
		while (i<m && j<n) {
			if (a[i].first < b[j].first) i++;
			else if (a[i].first > b[j].first) j++;
			else {
				res+=a[i].second*b[j].second;
				i++;
				j++;
			}
		}

		return res;
	}
};

2. b is big
class Solution {
public:
	int binarySearch(vector<pair<int,int>>& b, int i) {
		int n=b.size(), l=0, r=n-1;
		while (l<=r) {
			int mid=l+(r-l)/2;
			if (b[mid].first==i) return mid;
			else if (b[mid].first<i) l=mid+1;
			else r=mid-1;
		}
		return -1;
	}

	int dotProduct(vector<pair<int,int>> a, vector<pair<int,int>> b) {
		int res=0, m=a.size(), n=b.size(), i=0;
		for (int i=0; i<m; i++) {
			int j=binarySearch(b, a[i].first);
			if (j!=-1) res+=a[i].second*b[j].second;
		}

		return res;
	}
};

