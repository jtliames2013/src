780. Reaching Points
DescriptionHintsSubmissionsDiscussSolution
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

Note:

sx, sy, tx, ty will all be integers in the range [1, 10^9].

If sx,sy occurs in the path of Euclidean method to get GCD (by subtracting lesser value from greater value) of tx,ty, then return true.

To see why this is true, consider how the tx, ty could have been formed if tx > ty. Let ax, ay be the pair in previous step. It cannot be ax, ax+ay because both ax and ay are greater than 0. So the only other possibility is ax+ay, ay. This means ay = ty and ax = tx-ty. Now we can optimize this subtraction a bit by doing ax = tx % ty since we will keep subtracting ty from tx until tx > ty.

One special case we need to handle during this optimization is when tx=9,ty=3,sx=6, sy=3 which can be covered using the condition if(sy == ty) return (tx - sx) % ty == 0;
Similar argument applies for tx <= ty.

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy){
            if(tx>ty){
                if(sy==ty) return (tx-sx)%ty==0;
                tx%=ty;
            } else{
                if(sx==tx) return (ty-sy)%tx==0;
                ty%=tx;
            }
        }   
        
        return false;
    }
};
