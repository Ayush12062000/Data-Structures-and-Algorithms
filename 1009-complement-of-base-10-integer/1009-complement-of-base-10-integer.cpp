class Solution {
public:
    
    /*1 = 2*0+1 = 1
      3 = 1*2+1 = 11
      7 = 3*2+1 = 111*/
    
    int bitwiseComplement(int n) {
        int  x=1;
        while(x<n)
            x = (x<<1)+1;
        return x^n;
    }
};