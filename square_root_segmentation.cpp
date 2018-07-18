//////// searching summetion from square root segment. search and update O(root(n)) time..




#include<iostream>
#include<sstream>
#include<stack>
#include<cmath>
using namespace std;


int search(int a,int b,int root,int arr[],int sum[])
{
   if(a>b)
    return 0;
    
   int right_l=ceil((double)a/root)*root;
   int left_r=(ceil((double)b/root)*root)-root+1;
 
	
   if(b<=right_l && a>=left_r)
   {
      if(b-a+1 == root)
         return sum[b/root];
      else
       {
     
         if(a>left_r)
          return arr[b]-arr[a-1];
         else
          return arr[b];
       } 
   }
   else
    return search(a,right_l,root,arr,sum)+search(right_l+1,b,root,arr,sum);
}






void update(int value,int pos,int arr_size,int arr[],int sum[],int root)
{
  int right=ceil((double)pos/root)*root;
  int temp=arr[pos];
  
  arr[pos]=value;
  
  for(int i=pos+1;i<=right && right<=arr_size;i++)
   {
     arr[i]-=temp;
     arr[i]+=arr[pos];
     
     if(i==right)
      sum[i/root]=arr[i];
   }
  
}





int main()
{
    int n,root=0,temp=1;
    cin>>n;
    
    root=ceil(sqrt(n));
 
    int arr[n+2],sum[n+2];
    arr[0]=0;
    sum[0]=0;
    
                             
    for(int i=1;i<=n;i++)     /////// making segment from here
     {
        cin>>arr[i];
        if(i%root!=1)
        {
          arr[i]+=arr[i-1];
        }
        if(i%root==0)
        {
          sum[temp]=arr[i];
          temp++;
        }
     }
     
    
     
     update(10,1,n,arr,sum,root);
     
     int m;
     cin>>m;
     while(m--)
     {
        int a,b;
        cin>>a>>b;
        
        cout<<search(a,b,root,arr,sum)<<endl;
     }
   
}






*/
10                         //total number
1 2 3 4 5 6 7 8 9 10       //numbers
5                          //total queries
1 2                        // queries //summetion of index 1 to 2
2 4
3 6
1 10
4 8
*/
