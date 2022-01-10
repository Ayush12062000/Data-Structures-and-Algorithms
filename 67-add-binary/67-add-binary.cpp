class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1,m=b.size()-1;
        if(n<m) addBinary(b,a);
        string ans="";
        int carry=0;
        while(n>=0||m>=0||carry>0)
        {
            if(n>=0) carry += (a[n--]-'0');
            if(m>=0) carry += (b[m--]-'0');
            ans += to_string(carry%2);
            carry /=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};