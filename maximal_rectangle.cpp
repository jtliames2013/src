85. Maximal Rectangle  QuestionEditorial Solution  My Submissions
Total Accepted: 45588 Total Submissions: 189955 Difficulty: Hard
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Hide Company Tags Facebook
Hide Tags Array Hash Table Stack Dynamic Programming
Hide Similar Problems (H) Largest Rectangle in Histogram (M) Maximal Square


优化就是先预处理成保存成，当前点向上都是1的最高的高度，就变成每一行都是一个直方图，
之后用O（n）的直方图求最大面积去算，之前一篇文章 http://blog.csdn.net/havenoidea/article/details/11854723 介绍过这个步骤，就不细说。

class Solution {  
public:  
    int maximalRectangle(vector<vector<char> > &matrix) {  
         
        int i,j,k,row,col,maxx=0;  
        row=matrix.size();  
        if(row==0)return 0;  
        col=matrix[0].size();  
        if(col==0)return 0;             
        for(j=0;j<col;++j)  
            for(i=0;i<row;++i)  
                if(matrix[i][j]=='0')height[i][j]=0;  
                else if(i==0)height[0][j]=1;  
                else height[i][j]=height[i-1][j]+1;  
          
        stack<int>s;  
        for(i=0;i<row;++i)  
        {  
            for(j=0;j<col;++j)  
            {  
                if(s.empty())s.push(j);  
                else  
                {  
                    while(!s.empty()&&height[i][s.top()]>height[i][j])  
                    {  
                        int ph=s.top();  
                        s.pop();  
                        if(!s.empty())  
                            maxx=max(maxx,(j-s.top()-1)*height[i][ph]);  
                        else   
                            maxx=max(maxx,j*height[i][ph]);                      
                    }    
                    s.push(j);  
                }  
            }  
            while(!s.empty())  
            {  
                int ph=s.top();  
                s.pop();  
                if(!s.empty())  
                     maxx=max(maxx,(col-s.top()-1)*height[i][ph]);  
                else   
                     maxx=max(maxx,col*height[i][ph]);    
                  
            }  
        }  
        return maxx;  
    }  
};  
