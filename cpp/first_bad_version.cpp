  278. First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Facebook
Hide Tags Binary Search
Hide Similar Problems (M) Search for a Range (M) Search Insert Position

由于这题很有规律，好版本和坏版本一定有个边界，那么我们用二分法来找这个边界，对mid值调用API函数，如果是坏版本，说明边界在左边，则把mid赋值给right，如果是好版本，则说明边界在右边，则把mid+1赋给left，最后返回left即可。需要注意的是，OJ里有个坑，那就是如果left和right都特别大的话，那么left+right可能会溢出，我们的处理方法就是变成left + (right - left) / 2，很好的避免的溢出问题.

  // Forward declaration of isBadVersion API.
  bool isBadVersion(int version);

  class Solution {
  public:
      int firstBadVersion(int n) {
    	  long l=1, r=n, m;
    	  while (l<r) {
    		  m=(l+r)/2;
    		  if (isBadVersion(m)) r=m;
    		  else l=m+1;
    	  }

    	  return r;
      }
  };

