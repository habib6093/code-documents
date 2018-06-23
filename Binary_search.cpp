#include<iostream>
#include<algorithm>


using namespace std;

int binarySearch(int arr[],int start,int end,int m)
{

   
   if(start==end && arr[start]!=m)
    return -1;
   
   if(arr[start]==m)
     return start;
   
    
   int mid=(start+end)/2;
   
   if(m<=arr[mid])
      return binarySearch(arr,start,mid,m);
   else
      return binarySearch(arr,mid+1,end,m);
  
}


int main()
{
   int n,arr[1000]={};
   
   cin>>n;
   
   for(int i=0;i<n;i++)
   {
   	cin>>arr[i];
   }
   
   sort(arr,arr+n);
   int m;
   cin>>m;
   
   cout<<binarySearch(arr,0,n,m);
}
