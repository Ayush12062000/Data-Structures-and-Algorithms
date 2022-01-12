class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while( j>i)
        {
            if(!(isalpha(s[i])))
                i++;
            if(!(isalpha(s[j])))
                j--;
            if(isalpha(s[i]) && isalpha(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            
        }
        return s;
    }
};