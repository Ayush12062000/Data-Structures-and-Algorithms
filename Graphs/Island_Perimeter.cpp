class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int> > visited(m,vector<int>(n));
        
        int peri=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    peri +=4;
                    if(i>0 && grid[i-1][j]==1)
                        peri -=2;
                    if(j>0 && grid[i][j-1]==1)
                        peri -=2;
                }
            }
        }
        return peri;
    }
};