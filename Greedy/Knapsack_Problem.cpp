#include<bits/stdc++.h>
#define input(n) int n; cin>>n

using namespace std;

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
    /*cout<<"Entered Profit(0) and weights(1):\n";
    for(int i=0;i<n;i++)
        cout<<arr[0][i]<<" "<<arr[1][i]<<endl;*/

    int curw = w,maxi;
    double profit = 0;
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


/*
input number of objects: 3
input Max weight of the knapsack: 50
enter profit weight:
60 10
100 20
120 30
Max Profit: 240 */