class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++)
        {
            res[i].resize(i+1);
            res[i][0]=res[i][i]=1;
            
            for(int j=1;j<i;j++)
                res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
        return res;
    }
};