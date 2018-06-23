#include<iostream>
#include<algorithm>


using namespace std;

void nqueen(int n,int row,int column[],int left[],int right[],int result[])
{
  
    if(row>n)
    { 
      cout<<".................................."<<endl;
      for(int i=1;i<=n;i++)
       {
         for(int j=1;j<=n;j++)
           {
        	if(result[i]==j)
        	 cout<<1<<" ";
        	else
        	 cout<<0<<" ";
           }
         cout<<endl;
       }
       return;
    }
    
    
    for(int i=1;i<=n;i++)
    {
    	if(column[i]==0 && left[row-i+n]==0 && right[row+i]==0)
    	{
    	    column[i]=1;
    	    left[row-i+n]=1;
    	    right[row+i]=1;
    	    
    	    result[row]=i;
    	    
    	    nqueen(n,row+1,column,left,right,result);
    	    
    	    column[i]=0;
    	    left[row-i+n]=0;
    	    right[row+i]=0;
    	    
    	    result[row]=0;
    	}
    }
}

 
 
 
 
 
 
int main()
{
   int n;
   cin>>n;
   
   int column[100]={},left[100]={},right[100]={},result[100]={},rows[100]={};
   
   nqueen(n,1,column,left,right,result);
    
}
