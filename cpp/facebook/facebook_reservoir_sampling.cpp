给一个l*w的矩阵，要随机取k个点。

A simple solution is to create an array reservoir[] of maximum size k. One by one randomly select an item from stream[0..n-1]. If the selected item is not previously selected, then put it in reservoir[]. To check if an item is previously selected or not, we need to search the item in reservoir[]. The time complexity of this algorithm will be O(k^2). This can be costly if k is big. Also, this is not efficient if the input is in the form of a stream.

It can be solved in O(n) time. The solution also suits well for input in the form of stream. The idea is similar to this post. Following are the steps.

1) Create an array reservoir[0..k-1] and copy first k items of stream[] to it.
2) Now one by one consider all items from (k+1)th item to nth item.
…a) Generate a random number from 0 to i where i is index of current item in stream[]. Let the generated random number is j.
…b) If j is in range 0 to k-1, replace reservoir[j] with arr[i]

class Solution {
public:
	vector<int> sample(vector<vector<int>> matrix, int k) {
		vector<int> reservoir(k);
		int m=matrix.size(), n=matrix[0].size();
		int i=0;
		for (; i<m*n; i++) {
			if (i<k) {
				reservoir[i]=matrix[i/n][i%n];
			} else {
				int j=rand()%(i+1);
				if (j<k) {
					reservoir[j]=matrix[i/n][i%n];
				}
			}
		}

		return reservoir;
	}
};

