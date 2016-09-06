public class Solution {
    public String intToRoman(int num) {
        StringBuilder sb=new StringBuilder();
        int scale=1000;
        char[] symbols=new char[]{'M','D','C','L','X','V','I'};
        int i=0;
        while (num>0) {
            int digit=num/scale;
            if (digit>0) {
                if (digit<=3) {
                    for (int j=0; j<digit; j++) sb.append(symbols[i]);
                } else if (digit==4) {
                    sb.append(symbols[i]);
                    sb.append(symbols[i-1]);
                } else if (digit==5) {
                    sb.append(symbols[i-1]);
                } else if (digit<=8) {
                    sb.append(symbols[i-1]);
                    for (int j=0; j<digit-5; j++) sb.append(symbols[i]);
                } else if (digit==9) {
                    sb.append(symbols[i]);
                    sb.append(symbols[i-2]);
                }
            }
            num%=scale;
            scale/=10;
            i+=2;
        }
        
        return sb.toString();
    }
}
