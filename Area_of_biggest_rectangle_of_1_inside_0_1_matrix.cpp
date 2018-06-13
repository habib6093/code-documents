#include<iostream>
#include<stack>
#include <utility>


using namespace std;


int main()
{
   int matrix[5][8];
   
   for(int x=0;x<5;x++)
   {
     for(int y=0;y<8;y++)
     {
     	cin>>matrix[x][y];
     	
     	if(x>0 && matrix[x][y]==1)
     	{
     	  matrix[x][y]+=matrix[x-1][y];
     	}
     	
     //	cout<<matrix[x][y]<<" ";
     }
    // cout<<endl;
   }
   
   
 
   
   int final=0,temp=0;
   stack<pair<int,int>> index;
   pair<int,int> now;
  
  
  
  for(int x=0;x<5;x++)
   {
     
     for(int y=0;y<8;y++)
     {  
         //cout<<matrix[x][y]<<endl;
         if((index.empty() || index.top().first<=matrix[x][y]) && matrix[x][y]>0)
         {
         	index.push(make_pair(matrix[x][y],y));
         	//cout<<"pushed  "<<index.top().second<<endl;
         }
         else if(!index.empty() && matrix[x][y]<index.top().first)
         {
         	int count=index.top().second+1,last_index;
         	while(!index.empty() && matrix[x][y]<index.top().first)
         	{
         	    last_index=index.top().second;
         	    temp=(count-index.top().second)*index.top().first;
         	    index.pop();
         	    //cout<<"poped"<<endl;
         	    //cout<<"result: "<<temp<<endl;
         	    
         	    if(temp>final)
         	     final=temp;
         	     

         	}
         	
         	if(matrix[x][y] > 0)
         	 {
         	   index.push(make_pair(matrix[x][y],last_index));
         	   //cout<<"pushed  "<<index.top().second<<endl;
         	 }
         }
     	
     }
     
     if(!index.empty())
     {
         	int count=index.top().second+1,last_index;
         	while(!index.empty())
         	{
         	    last_index=index.top().second;	 
         	    temp=(count-index.top().second)*index.top().first;
         	    index.pop();
         	    //cout<<"popedes"<<endl;
         	    
         	    if(temp>final)
         	     final=temp;
         	     

         	}
     }
 
   }
   
   cout<<final<<endl;
   
}
