关于这题大家百度google S2 Library  也就是Hilbert Curve   LZ看过一眼也是因为之前准备Uber Design说Uber用了Google的S2. 
就是说想象Hilbert Curve 在你面前 （Hilbert曲线可以无限阶下去 从1阶开始） 落在一个矩阵里 让你写个function  三个参数 （x,y,阶数） . 
return 这个点（x,y）是在这阶curve里第几步
写代码实现给一个n，给出对应的hilbert curve的坐标，可以用recursive的方法做…旋转有点麻烦…

//rotate/flip a quadrant appropriately
void rot(int n, int *x, int *y, int rx, int ry) {
    if (ry == 0) {
        if (rx == 1) {
            *x = n-1 - *x;
            *y = n-1 - *y;
        }

        //Swap x and y
        int t  = *x;
        *x = *y;
        *y = t;
    }
}

//convert (x,y) to d
int xy2d (int n, int x, int y) {
    int rx, ry, s, d=0;
    for (s=n/2; s>0; s/=2) {
        rx = (x & s) > 0;
        ry = (y & s) > 0;
        d += s * s * ((3 * rx) ^ ry);
        rot(s, &x, &y, rx, ry);
    }
    return d;
}

//convert d to (x,y)
void d2xy(int n, int d, int *x, int *y) {
    int rx, ry, s, t=d;
    *x = *y = 0;
    for (s=1; s<n; s*=2) {
        rx = 1 & (t/2);
        ry = 1 & (t ^ rx);
        rot(s, x, y, rx, ry);
        *x += s * rx;
        *y += s * ry;
        t /= 4;
    }
}

class Solution {
public:
	//convert (x,y) to d
	int convert2Dto1D (int level, int x, int y) {
		int dist=0;
		int xbit=0, ybit=0;
		// length of square on each axis
		// leve1==1 -> 2x2
		// level==2 -> 4x4 ...
		int len=1<<level;
		for (int l=len/2; l>0; l/=2) {
			// get the most significant bit at this level
			xbit = (x & l) > 0 ? 1 : 0;
			ybit = (y & l) > 0 ? 1 : 0;
			int steps=0;
			if (xbit==0 && ybit==1) steps=1;
			else if (xbit==1 && ybit==1) steps=2;
			else if (xbit==1 && ybit==0) steps=3;
			dist += l*l*steps;
			rotate(l, &x, &y, xbit, ybit);
		}

		return dist;
	}

	void convert1Dto2D(int level, int dist, int *x, int *y) {
		int xbit, ybit;
		int len=1<<level;
		int tmp=dist;
		*x=*y=0;
		for (int l=1; l<len; l*=2) {
			// x is first of two bits
			// 01 10
			// 00 11
			xbit = 1 & (tmp/2);
			ybit = 1 & (tmp ^ xbit);
			rotate(l, x, y, xbit, ybit);
			*x += l * xbit;
			*y += l * ybit;
			tmp /= 4;
		}
	}

	void rotate(int l, int *x, int *y, int xbit, int ybit) {
		if (ybit==0) {
			// only rotate the lower bottom half
			if (xbit==1) {
				*x=l-1-*x;
				*y=l-1-*y;
			}

			// swap
			int tmp=*x;
			*x=*y;
			*y=tmp;
		}
	}
};

int main() {
	Solution s;
	int level=2;
	int xend=(1<<level);
	int yend=(1<<level);
/*	for (int x=0; x<xend; x++) {
		for (int y=0; y<yend; y++) {
			int d1=s.convert2Dto1D(level, x, y);
			int d2=xy2d(1<<level, x, y);
			cout << x << " " << y << " " << d1 << endl;
			if (d1!=d2) cout << "d1=" << d1 << ", d2=" << d2 << endl;
		}
	}
*/
	int dend=(1<<(level*2));
	for (int d=0; d<dend; d++) {
		int x1, y1, x2, y2;
		s.convert1Dto2D(level, d, &x1, &y1);
		d2xy(1<<level, d, &x2, &y2);
		cout << x1 << " " << y1 << " " << d << endl;
		if (x1!=x2 || y1!=y2) cout << "x2=" << x2 << ", y2=" << y2 << endl;
	}

	return 0;
}

