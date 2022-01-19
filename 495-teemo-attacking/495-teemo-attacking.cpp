class Solution {
public:
    int findPoisonedDuration(vector<int>& timeseries, int duration) {
        if(timeseries.size()==0) return 0;
        int counter=0;
        for(int i=0;i<timeseries.size()-1;i++)
        {
            counter += min(timeseries[i+1]-timeseries[i],duration);
        }
        return counter+duration;
    }
};