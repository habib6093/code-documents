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
     int arr[100]={};
     for(int y=0;y<8;y++)
     {  
         //cout<<"index: "<<y+1<<"   "<<matrix[x][y]<<endl;
         if((index.empty() || index.top().first<=matrix[x][y]) && matrix[x][y]>0)
         {
         	index.push(make_pair(matrix[x][y],y));
         	//cout<<"pushed  "<<index.top().second<<endl;
         }
         else if(!index.empty() && matrix[x][y]<index.top().first)
         {
         	int count=index.top().second+1,last_index=0,cnt=0;
         	
         	while(!index.empty() && matrix[x][y]<index.top().first)
         	 {
         	    if(index.top().second>last_index)
         	     last_index=index.top().second;
         	     
         	    temp=(count-index.top().second)*index.top().first+arr[index.top().second];
         	    index.pop();
         	 
         	    cnt++;
         	    if(temp>final)
         	     final=temp;
         	     
         	    // cout<<"poped"<<endl;
         	     
              }
         	
         	if(matrix[x][y] > 0)
         	 {
         	   index.push(make_pair(matrix[x][y],y+1));
         	   arr[index.top().second]=cnt*matrix[x][y];
         	   //cout<<"pushed  "<<index.top().second<<"  count is: "<<cnt*matrix[x][y] <<endl;
         	 }
         }
     	
     }
     
     if(!index.empty())
     {
         	int count=index.top().second+1,last_index,cnt=0;
         	
         	while(!index.empty())
         	{
         	    if(index.top().second>last_index)
         	     last_index=index.top().second;
         	      
         	    temp=(count-index.top().second)*index.top().first+arr[index.top().second];
         	    index.pop();
         	    //cout<<"popedes"<<endl;
         	    
         	    if(temp>final)
         	     final=temp;

         	}
     }
     
     //cout<<"final is: :::::: "<<final<<endl;
 
   }
   
   cout<<final<<endl;
   
}
