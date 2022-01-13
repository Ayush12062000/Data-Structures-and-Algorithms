class Solution {
public:
    
    int reverse(int n)
    {
        int rev=0;
        while(n>0)
        {
            int r = n%10;
            rev  = rev*10+r;
            n/=10;
        }
        return rev;
    }
    
    
    bool isSameAfterReversals(int num) {
        int ori=num;
        num = reverse(num);
        num = reverse(num);
        if(num==ori) return true;
        else    return false;
            
    }
};