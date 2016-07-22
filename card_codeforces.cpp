#include<iostream>
using namespace std;

int main()
{
    int x,value=0;
    cin>>x;

    int arr[x];
    for(int a=0;a<x;a++)
    {
        cin>>arr[a];
        value=value+arr[a];
    }
    value=value/(x/2);
    int count=0;
    for(int a=0;a<x;a++)
    {
        for(int b=a+1;b<x;b++)
        {
            if(count==x/2)
                break;
            if(arr[a]+arr[b]==value&&arr[b]>=0)
            {
                cout<<a+1<<" "<<b+1<<endl;
                count++;
                arr[b]=-1;
                break;
            }
        }
    }


}
