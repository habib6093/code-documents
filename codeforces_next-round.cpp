#include<iostream>
using namespace std;

int main()
{
    int x,y,value=0;
    cin>>x>>y;
    int arr[x];
    
    for(int a=0;a<x;a++)
    {
        cin>>arr[a];
        if(a>=(y-1)&&arr[a]!=0)
        {
           if(arr[a]>=arr[y-1])
           value++;
        }
    }
    
    for(int a=0;a<(y-1);a++)
    {
        if(arr[a]!=0&&arr[a]>=arr[y-1])
        value++;
    }
    cout<<value;
    
    
    
}
