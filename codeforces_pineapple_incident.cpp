#include<iostream>

using namespace std;

int main()
{

	int x,y,z,value=0;

	cin>>x>>y>>z;

    value=x;


    if(x<=z&&(x==z||(z-x)%y==0||((z-x-1)!=0&&(z-x-1)%y==0)))
    {   
    	cout<<"YES"<<endl;
    }
  
    else
    	cout<<"NO"<<endl;
}
