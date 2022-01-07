class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int c = m[s[0]];
        for(auto x:m)
        {
            if(c!=x.second)
                return false;
        }
        return true;
    }
};