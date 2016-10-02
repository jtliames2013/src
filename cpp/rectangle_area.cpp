 Note when common area is negative. 

 class Solution {
  public:
      int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	  int left1=min(A, C), right1=max(A, C), bottom1=min(B, D), top1=max(B, D);
    	  int left2=min(E, G), right2=max(E, G), bottom2=min(F, H), top2=max(F, H);

    	  int left=max(left1, left2);
    	  int right=min(right1, right2);
    	  int bottom=max(bottom1, bottom2);
    	  int top=min(top1, top2);
    	  int common=0;
    	  if (right>left && top>bottom) {
    		  common=(right-left)*(top-bottom);
    	  }

    	  return (right1-left1)*(top1-bottom1)+(right2-left2)*(top2-bottom2)-common;
      }
  };

2.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left=max(A, E);
        int right=min(C, G);
        int bottom=max(B, F);
        int top=min(D, H);
        int common=0;
        
        if (right>left && top>bottom) {
            common=(right-left)*(top-bottom);
        }
        
        return (C-A)*(D-B)+(G-E)*(H-F)-common;
    }
};
