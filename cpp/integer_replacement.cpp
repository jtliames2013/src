class Solution {
public:
    int dfs(long long num) {
        if (num==1) return 0;
        if (num==3) return 2;
        if (num%2==0) return dfs(num/2)+1;
        else {
            if ((num+1)%4==0) return dfs(num+1)+1;
            else return dfs(num-1)+1;
        }
    }
    
    int integerReplacement(int n) {
        return dfs(n);
    }
};
