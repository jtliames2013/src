For every digit in n (Suppose n = 240315, the digits are 2, 4, 0, 3, 1, 5)，I respectively count the number of digit 1 assuming the position of current digit is 1 and other digits of n is arbitrary.

For example, I select 3 in n as the current digit, and I suppose the position of 3 is 1.

The highn is the number composed with the digits before the current digit. In the example, highn = 240;

The lown is the number composed with the digits after the current digit. In the example, lown = 15.

The lowc = 10 ^ (the number of lower digits). In the example, lowc = 100;

As curn = 3 and curn > 1, (highn * 10 + 1) must be less than (highn * 10 + curn). Then the higher part can be 0 ~ highn, the lower part can be 0 ~ (lowc-1), and the current result = (highn + 1) * lowc.

int countDigitOne(int n) {
        long long int res(0);
        int highn(n), lowc(1), lown(0);
        while(highn > 0){
            int curn = highn % 10;
            highn = highn / 10;
            if(1 == curn){
                //higher: 0~(highn-1);  lower:  0 ~ (lowc-1)
                res += highn * lowc;
                //higher: highn ~ highn;     lower:0~lown
                res += lown + 1;
            }else if(0 == curn){  
                //curn < 1
               //higher: 0~(highn-1);  lower:  0 ~ (lowc-1)
                res += highn * lowc;
            }else{              
                //curn > 1
                res += (highn + 1) * lowc;
            }
            //update lown and lowc
            lown = curn * lowc + lown;
            lowc = lowc * 10;
        }
        return res;
    }

