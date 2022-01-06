class Solution {
public:
    int sol(int n)
    {
        int sum=0;
        while(n>0)
        {
            int r = n%10;
            sum += r*r;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int sum=n;
        while(sum!=1)
        {
            sum = sol(sum);
            if (sum < 10 && sum > 1 && sum != 6 && sum != 7) 
                return false;
        }
        if(sum==1)
            return true;
        else
            return false;
    }
};