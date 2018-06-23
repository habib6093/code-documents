#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
   int total_coin;
   cin>>total_coin;
   
   int arr[total_coin+2];
   
   for(int i=0;i<total_coin;i++)
   {
     cin>>arr[i];
   }
   
   int change;
   cin>>change;
   
   int possible[10000000]={};
   possible[0]=1;
   
   sort(arr,arr+total_coin);
   
   for(int i=0;i<total_coin;i++)
      for(int j=1;j<=change;j++)
       {
         if(j>=arr[i] && possible[j-arr[i]]>0)
          {
          	possible[j]+=possible[j-arr[i]];
          }
       }
       
       
       
    cout<<possible[change]<<endl; ///how many possible way to make a change with given number
	
	
}
