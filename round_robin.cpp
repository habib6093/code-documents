#include<iostream>
#include<queue>

using namespace std;

class ps{
  public:
    int pno,arrival,et;
    ps(int a,int b,int c)
    {
      pno=a;
      arrival=b;
      et=c;
    }
};

int main()
{
  int quantum,n,time=0,total_time=0;
  cin>>quantum>>n;
  
  queue<ps> arr,scheduler;
  
  for(int i=1;i<=n;i++)
  {
  	
    int x,y;
    cin>>x>>y;
    
    total_time+=y;
    
    ps ob(x,x,y);
    
    arr.push(ob);
  }
  
  scheduler.push(arr.front());
  arr.pop();
  
  while(total_time)
  {
    cout<<"time "<<time<<":  process-> "<<scheduler.front().pno<<endl;
    
    if(scheduler.front().et>=quantum)
     {
      total_time-=quantum;
      time+=quantum;
      
      scheduler.front().et-=quantum; 
     }
    else
     {
       total_time-=scheduler.front().et;
       time+=scheduler.front().et;
        scheduler.front().et=0;
     }
     
     
     while(!arr.empty() && (scheduler.empty() || time>=arr.front().arrival))
     {
       scheduler.push(arr.front());
       arr.pop();
     }
     
     
    if(scheduler.front().et>0)
      scheduler.push(scheduler.front());
      
    scheduler.pop();
    
  }
  
   
   cout<<"no process remaining............."<<endl;
  
}
