#include<iostream>

usign namespace std;

int main()
{
	int x,y,value=0;
	cin>>x>>y;

	for(int a=x;a<=y;a++)
	{    int b=a;
         while(b!=0)
         {  int c=b%10;
         	     b=b/10;

         	if(c==1)
         		value=value+2;
         	else if(c==2||c==3||c==5)
         		value=value+5;
         	else if(c==4)
         		value=value+4;
         	else if(c==6||c==9||c==0)
         		value=value+6;
         	else if(c==7)
         		value=value+3;
         	else if(c==8)
         		value=value+7;
         
             
         }
	}
	cout<<value<<endl;
}
