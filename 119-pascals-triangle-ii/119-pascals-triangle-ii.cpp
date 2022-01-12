class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=1;i<=rowIndex+1;i++)
        {
            vector<int> x(i,1);
           for(int j=1;j<i-1;j++)
           {
               x[j] = res[j-1]+res[j];
           }
            res=x;
        }
        return res;
    }
};