一上来直接code，找小偷问题，有n个房间，其中一个房间有小偷。早上我们
可以打开一个房间的门看小偷在不在里面，晚上小偷会向左边或者右边的房间走。
现在给你一个开门的sequence，你输出这个sequence能不能保证找到小偷。
比如：如果只有三个房间那么如果打开房间的sequence是{1，1}那么一定会找到小偷。
因为如果小偷在中间那么第一天就会被找到，如果小偷在两边那么第二天一定回来
到中间也会被找到。房间数为n，sequence长度为k

跟着我开始brute force假设小偷在某个房间然后dfs所有路径，大概是O(n*n^k)。 
考官说好，如果考虑cut branch呢？跟着我就说可以拿一个n*k的matrix跟着根据
sequence来cut branch，reduce到O(n*n*k)。他说有没有可能同时从所有房间
开始呢？我说可以跟着直接在那个n*kmatrix上做一个类似dp的东西。跟着reduce 到 
O(n*k)。他说有没有可能把space reduce呢？我说可以我只要O(n)的space
跟着他就让我再写一个叫nextRow的function来实现O(n)space。 我觉得这题我
基本是答得非常漂亮的而且思路很清晰，考官也很开心

面试官说是道新题  finding ali baba
就是ali baba是个怪兽，他可能在[0，1, ..., numCaves-1]出现，他每隔一天就要换
一个地方，但他每次只能移左右一格。
然后给你一个strategy[]数组，数组里面是猜测每天ali baba的位置。如果里面有一个
猜中了，这个strategy就是正确的。
问题就是让你写一个判断函数 alibaba(int numCaves, int[] strategy)来判别这个
strategy数组是不是稳赢的策略。写完后问时间复杂度，然后问了下大概怎么样可以优
化～～～

我感觉这题是DP，但不知道转移方程怎么写，不知走过路过的大神能给点idea咩？

class Solution {
public:
	bool canCatch(int n, vector<int> strategy) {
		int k=strategy.size();
		// dp[i]==true - thief can arrive at room i
		vector<bool> prev(n, true), dp(n);
		for (int i=0; i<k; i++) {
			for (int j=0; j<n; j++) {
				if ((j>0 && prev[j-1]) || (j<n-1 && prev[j+1])) {
					dp[j]=true;
				}
			}
			dp[strategy[i]]=false;
			prev=dp;
		}
		for (int j=0; j<n; j++) {
			if (dp[j]==true) return false;
		}
		return true;
	}
};

