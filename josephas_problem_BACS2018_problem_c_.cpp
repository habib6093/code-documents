#include<iostream>

using namespace std;

int main()
{
  int t;
  cin>>t;
  
  for(int i=1;i<=t;i++)
  {
    long long x,l,n,a=0,b=1,temp_total=0,temp_pro=0;
    cin>>x>>l>>n;
    
    temp_total=n-l+1;
    
    if(l<x)
    {
      temp_pro=(x-l);
      l=x;
    }
    
    if(x%2!=0)
    {
      long long m=1;
      temp_pro+=(n-l+1);
      
      while(m*2<l)
      {
        m*=2;
      }
      //cout<<"m: "<<m<<"  "<<temp_pro<<endl;
      
      while(m*2<=n)
      {
        temp_pro--;
        m*=2;
      }
      
      if(m!=n && ((n-m)*2)+1>=l)
      {
        temp_pro--;
      }
     //cout<<"m: "<<m<<"  "<<temp_pro<<endl;

      
    }
    
    if(temp_pro>0)
     {
       a=temp_pro;
       b=temp_total;
     }
    
    cout<<"Case "<<i<<": "<<a<<"/"<<b<<endl;
  }
}
