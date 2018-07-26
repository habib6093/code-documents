#include<iostream>
#include<vector>

using namespace std;


int main()
{
   int row,clm;
   cin>>row>>clm;
   
   int mat[row+1][clm+1];
   
   for(int i=0;i<row;i++)
   {
     for(int j=0;j<clm;j++)
     {
       cin>>mat[i][j];
       
       if(i>0 && mat[i][j]!=0)
        mat[i][j]+=mat[i-1][j];
     }
   }
   
   
   
   vector<pair<int,int>> index; // value,pos
   int final=0;
   
  
   for(int i=0;i<row;i++)
    {
      //cout<<i+1<<"th column.........."<<endl;
      int temp=0,arr[1000000]={};
     
      for(int j=0;j<clm;j++)
       {
        
         if((index.empty() || index.back().first<=mat[i][j]) && mat[i][j]>0)
          {
         	index.push_back(make_pair(mat[i][j],j));
          }
         else
          {
          	 int cnt=0,dist=0;
             while(!index.empty() && index.back().first>mat[i][j])
             {
               if(dist<index.back().second)
                dist=index.back().second;
                 
               temp=( index.back().first * (dist+1 - index.back().second) )+arr[index.back().second];
               
               if(temp>final)
                final=temp;
                
               index.pop_back();
               cnt++;
             }
            
             if(mat[i][j]>0)
             {
               arr[j]=cnt*mat[i][j];
               index.push_back(make_pair(mat[i][j],j));
             }
          	
          }
       }
       
       if(!index.empty())
       {
          int dist=0;
          while(!index.empty())
             {
               if(dist<index.back().second)
                dist=index.back().second;
                 
               temp=( index.back().first * (dist+1 - index.back().second) )+arr[index.back().second];
               
               if(temp>final)
                final=temp;
                
               index.pop_back();
                
             }
         
       }
 
    }
   
   
   cout<<final<<endl;
   
}
