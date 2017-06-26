311. Sparse Matrix Multiplication
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

1.
The idea is derived from a CMU lecture.

A sparse matrix can be represented as a sequence of rows, each of which is a sequence of (column-number, value) pairs of the nonzero values in the row.
So let's create a non-zero array for A, and do multiplication on B.

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    	int rowA=A.size();
    	int colA=A[0].size();
    	int rowB=colA;
    	int colB=B[0].size();
    	vector<vector<int> > C(rowA, vector<int>(colB, 0));

        vector<vector<pair<int,int>>> listA;
        for (int i=0; i<rowA; i++) {
            vector<pair<int,int>> v;
            for (int j=0; j<colA; j++) {
                if (A[i][j]!=0) v.push_back({j, A[i][j]});
            }
            listA.push_back(v);
        }
        
        for (int i=0; i<rowA; i++) {
            for (int j=0; j<listA[i].size(); j++) {
                int col=listA[i][j].first;
                int val=listA[i][j].second;
                for (int k=0; k<colB; k++) {
                    if (B[col][k]!=0) {
                        C[i][k]+=val*B[col][k];
                    }
                }
            }
        }
        
        return C;        
    }
};

2.
brute force solution, for each C[ i ] [ j ], it uses C[ i ] [ j ] += A[ i ] [ k ] * B[ k ] [ j ] where k = [ 0, n].Note: even A[ i ] [ k ] or B[ k ] [ j ] is 0, the multiplication is still executed.

For the above smart solution, if A[ i ] [ k ] == 0 or B[ k ] [ j ] == 0, it just skip the multiplication . This is achieved by moving for-loop" for ( k = 0; k < n; k++ ) " from inner-most loop to middle loop, so that we can use if-statement to tell whether A[ i ] [ k ] == 0 or B[ k ] [ j ] == 0. 

  class Solution {
  public:
      vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    	  int rowA=A.size();
    	  int colA=A[0].size();
    	  int rowB=colA;
    	  int colB=B[0].size();
    	  vector<vector<int> > C(rowA, vector<int>(colB, 0));

    	  for (int i=0; i<rowA; i++) {
			  for (int k=0; k<colA; k++) {
				  if (A[i][k]!=0) {
					  for (int j=0; j<colB; j++) {
						  if (B[k][j]!=0) C[i][j]+=A[i][k]*B[k][j];
					  }
				  }
    		  }
    	  }

    	  return C;
      }
  };

