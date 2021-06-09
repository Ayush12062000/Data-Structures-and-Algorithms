#include <iostream>
#include <cmath>

using namespace std;

int calculate_size(int n)
{
    int x = ceil(log2(n));
    int size =  2*pow(2, x) - 1;
    return size;
}

int* init(int size)
{
    int *temp = new int[size];
    return temp;
}

void buildTree(int *segment_tree, int *arr, int sl, int sr, int i)
{
    if(sl == sr){
        segment_tree[i] = arr[sl];
        return;
    }
    int mid = sl + (sr-sl)/2;
    buildTree(segment_tree, arr, sl, mid, 2*i+1);
    buildTree(segment_tree, arr, mid+1, sr, 2*i+2);
    segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
    return;

}

void update_utils(int *segment_tree, int sl, int sr, int curI, int index, int key, int changeValue)
{
    if(sl == sr){
        segment_tree[curI] = key;
        return;
    }
    segment_tree[curI] += changeValue;

    int mid = sl + (sr - sl)/2;

    if(index <= mid )
        update_utils(segment_tree, sl, mid, 2*curI+1, index, key, changeValue);
    else
        update_utils(segment_tree, mid+1, sr, 2*curI+2, index, key, changeValue);
}

void update(int *arr, int *segment_tree, int n, int index, int key)
{
    int changeValue = key - arr[index];
    arr[index] = key;
    update_utils(segment_tree, 0, n-1, 0, index, key, changeValue);
}

int calculateSum(int *arr, int *segment_tree, int sl, int sr, int index, int ql, int qr)
{
    if(sr < ql || sl > qr) return 0;
    if(sl >= ql && sr <= qr) return segment_tree[index];
    int mid = sl + (sr-sl)/2;
    return calculateSum(arr, segment_tree, sl, mid, 2*index+1, ql, qr)+
           calculateSum(arr, segment_tree, mid+1, sr, 2*index+2, ql, qr);
}

int main()
{
    int n, *arr, Q, index, key, l, r, type;
    cin>>n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int segmentSize = calculate_size(n);
    int *segment_tree = init(segmentSize);
    buildTree(segment_tree, arr, 0, n-1, 0);
    cin>>Q;
    while(Q--)
	{
		cin>>type;
		switch(type)
		{
			case 1: cin>>index>>key;
					update(arr, segment_tree, n, index, key);
				break;
			
			case 2: cin>>l>>r;
					cout<<"Sum = "<<calculateSum(arr, segment_tree, 0, n-1, 0, l, r)<<endl;
				break;
		}
	}
}