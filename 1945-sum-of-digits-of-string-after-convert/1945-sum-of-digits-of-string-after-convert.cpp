class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> ans;
        string numstring="";
        for(auto &c:s)
        {
            int n = c-'a'+1;
            numstring+=to_string(n);
        }
        
        while(k--)
        {
            int sum=0;
            for(auto &c:numstring)
            {
                sum+=c-'0';
            }
            ans.push_back(sum);
            numstring = to_string(sum);
        }
        return ans.back();
    }
};