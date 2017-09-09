Given a 2D array. Each row is constructed by 0's at the beginning and 1's at the following. 
ex: [
       [0,0,0,0,0,1,1]
       [0,0,0,1,1,1,1]
       [0,0,0,0,1,1,1]
      ]
Return the first column number that has 1 occurs. In the example it should be 3. more info on 1point3acres.com
第二题的时候花了好久才在提示下给出了最优解。依次先给了O(m*n)的brute force和O(m*lgn)的稍微optimize了一点的解。虽然说只是一面，但是虚的不行。发一篇面经，也算积累一下人品吧。

class Solution {
public:
	int firstColumn(vector<vector<int>> grid) {
		int m=grid.size();
		if (m==0) return 0;
		int n=grid[0].size();
		if (n==0) return 0;
		int i=0, j=n-1;
		while (i<m && j>=0) {
			if (grid[i][j]==1) {
				j--;
			}
			else i++;
		}
		return j+1;
	}
};

binary search each row
int binarysearch(vector<int> row) {
    int l=0, r=row.size();
    while (l<r) {
        int mid=l+(r-l)/2;
        if (row[mid]==0) l=mid+1;
        else r=mid;
    }
    return l;
}
