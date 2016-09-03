358. Rearrange String k Distance Apart 
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Hash Table Heap Greedy

我们需要一个哈希表来建立字符和其出现次数之间的映射，然后需要一个堆来保存这每一堆映射，按照出现次数来排序。然后如果堆不为空我们就开始循环，我们找出k和str长度之间的较小值，然后从0遍历到这个较小值，对于每个遍历到的值，如果此时堆为空了，说明此位置没法填入字符了，返回空字符串，否则我们从堆顶取出一对映射，然后把字母加入结果res中，此时映射的个数减1，如果减1后的个数仍大于0，则我们将此映射加入临时集合v中，同时str的个数len减1，遍历完一次，我们把临时集合中的映射对由加入堆中，参见代码如下：

  // "a"
  // "abb"
  class Solution {
  public:
      string rearrangeString(string str, int k) {
    	  if (k == 0) return str;
		  string res;
		  int len = str.size();
		  unordered_map<char, int> cnt;
		  priority_queue<pair<int, char>> pq;
		  vector<pair<int, int>> next;
		  for (auto ch:str) cnt[ch]++;
		  for (auto c:cnt) pq.push({c.second, c.first});

		  while (!pq.empty()) {
			  int l = min(k, len);
			  for (int i = 0; i < l; i++) {
				  if (pq.empty()) return "";
				  auto t = pq.top();
				  pq.pop();
				  res.push_back(t.second);
				  t.first--;
				  if (t.first > 0) next.push_back(t);
				  len--;
			  }
			  for (auto n:next) pq.push(n);
			  next.clear();
		  }
		  return res;
      }
  };

