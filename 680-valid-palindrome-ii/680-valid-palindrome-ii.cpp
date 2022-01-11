class Solution {
public:
    
    bool ispal(int s,int e,string str)
    {
        while(s<=e)
        {
            if(str[s]!=str[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        if(s.size()==1) return true;
        
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j]) 
            {
                i++;
                j--;
            }
            else
            {
                if(ispal(i+1,j,s)||ispal(i,j-1,s))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};