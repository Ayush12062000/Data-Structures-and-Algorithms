class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> ans;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                int a=ans.top();
                ans.pop();
                int b=ans.top();
                ans.pop();
                ans.push(b);
                ans.push(a);
                ans.push(a+b);

            }
            else if(ops[i]=="D")
            {
                ans.push(ans.top()*2);
            }
          else if(ops[i]=="C")
            {
                ans.pop();
            }
           else  ans.push(stoi(ops[i]));
        }
        int a=0;
        while(!ans.empty())
        {
            //cout<<ans.top();
            a += ans.top();
            ans.pop();
        }
        return a;
    }
};