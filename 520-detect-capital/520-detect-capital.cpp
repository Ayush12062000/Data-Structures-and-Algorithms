class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i=0;i<word.size();i++)
        {
            if(isupper(word[i]))
                cap++;
        }
        if(cap==0||(cap==1 && isupper(word[0]))||cap==word.size())
            return true;
        else
            return false;
    }
};