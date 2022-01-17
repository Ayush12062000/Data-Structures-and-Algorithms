class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1="",ans2="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
                ans1+=s[i];
            else
                if(!ans1.empty())
                    ans1.pop_back();
        }

        for(int i=0;i<t.size();i++)
        {
            if(t[i]!='#')
                ans2+=t[i];
            else
                if(!ans2.empty())
                    ans2.pop_back();
        }

        return (ans1==ans2);
    }
};
