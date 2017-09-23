给一个unsorted array， 给定index i and j， a) 找到i j 之间点的值的和   b)找到 i  j 之间点的最大值。 期望的最优解 a) O(n)  b) 小于 n2

http://algs4.cs.princeton.edu/99misc/SegmentTree.java.html

class NumArray {
public:
    NumArray(vector<int> nums) {
        n=nums.size();
        if (n==0) return;
        tree.resize(2*n);
        buildTree(nums);
    }

    void buildTree(vector<int>& nums) {
    	for (int i=n, j=0; i<2*n; i++, j++) {
    		tree[i]=nums[j];
    	}
    	for (int i=n-1; i>0; i--) {
    		tree[i]=max(tree[2*i], tree[2*i+1]);
    	}
    }

    void update(int i, int val) {
    	i+=n;
    	tree[i]=val;
    	while (i>0) {
    		int l=i, r=i;
    		if (i%2==0) r=i+1;
    		else l=i-1;
    		tree[i/2]=max(tree[l], tree[r]);
    		i/=2;
    	}
    }

    int maxRange(int i, int j) {
    	i+=n;
    	j+=n;
    	int maxVal=INT_MIN;
    	while (i<=j) {
    		if (i%2==1) {
    			maxVal=max(maxVal, tree[i]);
    			i++;
    		}
    		if (j%2==0) {
    			maxVal=max(maxVal, tree[j]);
    			j--;
    		}
    		i/=2;
    		j/=2;
    	}
    	return maxVal;
    }
private:
    vector<int> tree;
    int n;
};


int main()
{
	NumArray a({2, 1, 3, 5, 9, 2, 6});
	cout << a.maxRange(1,5) << endl;
	a.update(4, 0);
	cout << a.maxRange(1,5) << endl;
	return 0;
}

