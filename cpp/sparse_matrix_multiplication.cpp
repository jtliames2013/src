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

