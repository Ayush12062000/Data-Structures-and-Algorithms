class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1||n==2) return true;
        while(n>0)
        {
            if(n%2!=0) return false;
            n/=2;
            if(n==2) return true;
        }
        return false;
    }
};