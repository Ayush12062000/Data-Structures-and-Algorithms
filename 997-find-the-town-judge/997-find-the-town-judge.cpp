class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degreecount(n+1,0);
        
        for(auto i:trust)
        {
            degreecount[i[0]]--;
            degreecount[i[1]]++;
        }
        for(int i=1;i<degreecount.size();i++)
        {
            if(degreecount[i]==n-1)
                return i;
        }
        return -1;
    }
};