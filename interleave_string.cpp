//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

//

//For example,

// Given:

//s1 = "aabcc",

//s2 = "dbbca",

//

//When s3 = "aadbbcbcac", return true.

//When s3 = "aadbbbaccc", return false.

　

class Solution {

public:

bool isInterleave(string s1, string s2, string s3) {

int size1=s1.size();

int size2=s2.size();

int size3=s3.size();

if (size1+size2!=size3) return false;

vector<vector<bool>> res(size1+1, vector<bool>(size2+1));

res[0][0]=true;

for (int i=0; i<=size1; i++)

{

for (int j=0; j<=size2; j++)

{

if (i==0 && j==0) continue;

res[i][j]=false;

if ((i>0 && res[i-1][j]==true && s3[i+j-1]==s1[i-1]) ||

(j>0 && res[i][j-1]==true && s3[i+j-1]==s2[j-1]))

{

res[i][j]=true;

}

}

}

return res[size1][size2];

}

};
