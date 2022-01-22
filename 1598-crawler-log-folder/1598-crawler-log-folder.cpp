class Solution {
public:
    int minOperations(vector<string>& logs) {
        int main =0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../"){
                if(main!=0) 
                    main-=1;
            }
            else if(logs[i]=="./") continue;
            else main+=1;
        }
        return main;
    }
};