class Solution {
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int min(int a, int b)
	{
		return a < b ? a : b;
	}

    int maxProduct(int A[], int n) {
    	int max_local = A[0];
    	int min_local = A[0];
    	int global = A[0];

    	for (int i = 1; i < n; i++)
    	{
    		int max_copy = max_local;
    		max_local = max(max(max_local * A[i], A[i]), A[i] * min_local);
    		min_local = min(min(max_copy * A[i], A[i]), A[i] * min_local);
    		global = max(global, max_local);
    	}

    	return global;
    }
};

