#include<iostream>

using namespace std;

int main()
{
 int x,y;
  cin>>x;
	/*how many test cases*/
   for(int a=0;a<x;a++)
       {
         cin>>y;
         int arr[y-1];
         for(int b=0;b<y;b++)
             {
                cin>>arr[b];
			    /*length of sticks*/
             }

         int l=0,w=0;
         for(int c=0;c<(y-1);c++)
           {
             for(int d=c+1;d<=(y-1);d++)
              {
                if(arr[c]>arr[d])
                {
                  int s=arr[d];
                  arr[d]=arr[c];
                  arr[c]=s;
                }
              }
           }




          int s=0;
          for(int c=(y-1);c>=0;c--)
           {
              if(arr[c]==arr[c-1])
               { if(s>=4)
                  break;
                  if(s==0)
                  l=arr[c];
                  else
                   w=arr[c];

                 s=s+2;
                 c=c-1;
               }
           }

        if(s==4)
          {
          cout<<(l*w)<<endl;
          }
        else{
          cout<<-1<<endl;
          }
      }
     }
