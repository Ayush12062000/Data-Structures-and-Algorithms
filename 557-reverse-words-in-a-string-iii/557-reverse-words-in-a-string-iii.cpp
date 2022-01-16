class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        if(s==" ") return s;
        string ans="",str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(str.begin(),str.end());
                ans+=str;
                ans+=" ";
                str="";
            }
            else
                str+=s[i];
        }
        return ans.substr(0,ans.size()-1);
    }
};