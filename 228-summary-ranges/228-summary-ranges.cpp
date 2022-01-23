class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> res;
        string range="";
        bool Start=true;
        int low,high;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(Start)
            {
                low=nums[i];
                Start=false;
            }
            if(nums[i+1]!=nums[i]+1)
            {
                high = nums[i];
                Start=true;
                range = (low==high)? to_string(low):to_string(low)+"->"+to_string(high);
                
                res.push_back(range);
            }
        }
        range = to_string(nums[nums.size()-1]);
        
        res.push_back((!Start)? to_string(low)+"->"+range:range);
        return res;
    }
};