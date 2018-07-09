#include<iostream>
#include <fstream>

using namespace std;


int main()
{
 
   ifstream cin("one.txt");
   ofstream cout("one.out");

   long long t,k,n,v;
   cin>>t;

   for(int j=1;j<=t;j++)
   {
     cin>>k>>n>>v;

     string arr[k+3];

     for(int i=1;i<=k;i++)
     {
       cin>>arr[i];
     }

     long long temp=n*(v-1);

     temp=temp%k;

     temp++;
 

     cout<<"Case #"<<j<<": ";

     for(int i=temp;i<=k && n>0;i++ )
     {
       cout<<arr[i]<<" ";
       n--;
     }

  

     if(n>0)
     {
       for(int i=1;i<temp && n>0;i++ )
        {
          cout<<arr[i]<<" ";
          n--;
        }
     }

     cout<<endl;
   }
   
   
   cin.close();
   cout.close();
   return 0;

}
