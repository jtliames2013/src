本文简单介绍Binary indexed tree (Fenwick tree)


Fenwick tree

它又叫 Binary indexed tree ，也叫树状数组。

能在log(n)查询区间和，并且在log(n)时间内进行结点更新操作。

 

 

lowbit(x)函数

定义lowbit(x)为x的二进制表达式中最右边的1所对应的值。

比如，1234的二进制是0100 1101 0010  lowbit(1234)=2，在程序的实现中，


Lowbit(x)=x&-x;（为什么这样写呢？因为计算机内部采用补码表示，-x是x按位取反，尾数+1的结果）

 

树的结构图

让我们来看看图：横坐标是x, 纵坐标是lowbit(x)

对于节点x，

为左子结点，则父结点的编号是x+lowbit(x)，
为右子结点，则父结点的编号是x-lowbit(x)
设C[i] 为以i结尾的水平长条内的元素之和，如c[6]=a5+a6。

顺着结点I往左走，边走边往上爬，沿途经过的c[i]所对应的长条不重复不遗漏的包含了所有需要累加的元素。
如sum(6) = c[6] + c[4]
如果修改了一个a[i] ,那么从c[i]往右走，边走边网上爬，沿途修改所有结点对应的c[i]即可。
如a[1] + 1 那么 c[1] + 1, c[2]+1,c[4]+1………一直到最大值。

inline int lowbit(int x) { return x&(-x) ; }
 
int sum(int x)            
{ 
    int ans=0; 
    while(x>0)        
    {        
        ans+=C[x]; 
       x-=lowbit(x); 
    } 
    return ans; 
} 
 
void add(int x,int d) 
{ 
    while(x<=N) 
    { 
        C[x]+=d; 
       x+=lowbit(x); 
    } 
} 

