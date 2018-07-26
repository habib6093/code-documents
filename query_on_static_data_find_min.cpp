#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int arr[n+1];
  
  for(int i=0;i<n;i++)
   cin>>arr[i];
   
  map<int,map<int,int> > check;
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(j==j+i)
         check[j][j]=arr[j];
      else if(j+i<n)
       {
         check[j][j+i]=min(check[j][j+i-1],check[j+i][j+i]);
       }
    }
  }
  
  int m;
  cin>>n>>m;                   //query range
  
  cout<<check[n-1][m-1]<<endl;
  
}


/*
5
1 -2 -5 -1 5
2 4
*/
