#include<bits/stdc++.h>
#define input(n) int n; cin>>n

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return (a.first / a.second) >(b.first / b.second);
}

int main()
{
    vector<pair<int,int>> v;
    cout<<"Enter n:";
    input(n);
    cout<<"Enter Max weight of sack w:";
    input(w);
    cout<<"Enter profit and weight:\n";
    for(int i=0;i<n;i++)
    {
        input(profit);
        input(weight);
        v.push_back(make_pair(profit,weight));
    }
    sort(v.begin(),v.end(),compare);

    /*cout<<"You Entered:\n";
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }*/

    double mprofit=0.0;
    int curw= w,maxi=0;
    int added[n]={0};
    /*cout<<"added\n";
    for(int i=0;i<n;i++)
        cout<<added[i]<<" ";*/
    while(curw>=0)
    {
        for(int i=maxi;i<n;i++)
        {
            if(added[i] == 0){
                maxi = i;
                break;
            }
        }
        //cout<<maxi<<endl;
        added[maxi] = 1;
        mprofit += v[maxi].first;
        curw -= v[maxi].second;
        if(curw>0)
            continue;
        else
        {
            mprofit -= v[maxi].first;
            mprofit += (v[maxi].first*1.0/v[maxi].second)*(v[maxi].second+curw);
        }
    }

    cout<<"Maximum Profit:"<<mprofit<<endl;
    return 0;
}

/*
Output:

Test Case #1:
Enter n:7
Enter Max weight of sack w:15
Enter profit and weight:
10 2
5 3 
15 5
7 7 
6 1 
18 4
3 1
Maximum Profit:55.3333

Test Case #2:
Enter n:5
Enter Max weight of sack w:50
Enter profit and weight:
30 5
20 10
100 20
90 30
160 40
Maximum Profit:230
*/













/*
int main()
{
    cout<<"input number of objects: ";
    input(n);
    cout<<"input Max weight of the knapsack: ";
    input(w);
    int arr[2][n],added[n]={0};
    cout<<"enter profit weight:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[0][i]>>arr[1][i];
    }
    cout<<"Entered Profit(0) and weights(1):\n";
    for(int i=0;i<n;i++)
        cout<<arr[0][i]<<" "<<arr[1][i]<<endl;

    int curw = w,maxi;
    double profit = 0.0;
    while(curw>=0)
    {
        maxi=-1;
        for(int i=0;i<n;i++)
        {
            float pwi = (float)(arr[0][i]/arr[1][i]*1.0);
            float pwm = (float)(arr[0][maxi]/arr[1][maxi]*1.0);
            if((added[i]==0)&&(maxi==-1) || (pwi>pwm))
                maxi = i;
        }
        added[maxi] = 1;
        curw -= arr[1][maxi];
        profit += arr[0][maxi]; 
        if(curw >=0)
            continue;
        else
        {
            profit -= arr[0][maxi];
            profit += ((arr[0][maxi] / arr[1][maxi]))*(arr[1][maxi]+curw);
        }
    }
    cout<<"Max Profit: "<<profit<<"\n";

    return 0;
}
*/

/*
input number of objects: 3
input Max weight of the knapsack: 50
enter profit weight:
60 10
100 20
120 30
Max Profit: 240 */