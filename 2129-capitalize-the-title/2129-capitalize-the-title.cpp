class Solution {
public:
    string capitalizeTitle(string title) {
        title+=' ';
        vector<string> temp;
        string s = "";
        for(int i=0;i<title.size();i++)
        {
            if(title[i]==' ')
            {
                temp.push_back(s);
                s="";
            }
            else
                s+=tolower(title[i]);
        }
        //for(auto &word:temp) cout<<word<<endl;
        s="";
        for(auto &word:temp)
        {
            
            if(word.size()<=2)  s+=word+" ";
            else
            {
                word[0] = toupper(word[0]);
                s+=word+" ";
            }
        }
        return s.substr(0,s.size()-1);
    }
};