class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int n = s.size();
        int i=0,j=n;
        while(i<j)
        {
            if(i<j && !isvowel(s[i])) i++;
            if(i<j && !isvowel(s[j])) j--;
            if(isvowel(s[i]) && isvowel(s[j]))
            {
                char temp = s[i];
                s[i]  = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            
        }
        return s;
    }
};