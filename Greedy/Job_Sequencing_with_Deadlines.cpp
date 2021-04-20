#include<bits/stdc++.h>
#define input(n) int n; cin>>n

using namespace std;

struct job
{
    char id;
    int dl;
    int profit; 
};

bool comparison(job a,job b)
{
    return (a.profit > b.profit);
}

int main()
{
    cout<<"input number of jobs: ";
    input(n);
    job arr[n];
    cout<<"enter id deadline profit:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].id>>arr[i].dl>>arr[i].profit;
    }
    sort(arr,arr+n,comparison);
    //cout<<"Entered Profit(0) and deadline(1):\n";
    //for(int i=0;i<n;i++)
        //cout<<arr[i].id<<" "<<arr[i].dl<<" "<<arr[i].profit<<endl;

    int result[n];
    vector<bool> slot(n,false);


    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dl)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Maximum profit sequence of jobs : ";
    for (int i=0; i<n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    return 0;
}


/*
test case #1:
input number of jobs: 5
enter id deadline profit:
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
Maximum profit sequence of jobs : c a e
*/