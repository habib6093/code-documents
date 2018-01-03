#include <iostream>
#include <queue>

using namespace std;


void bfs(queue<int> arr[],int start)
{
   queue<int> bf;
   int visited[10000]={};
   
   bf.push(start);
   visited[start]=1;
   
   while(!bf.empty())
   {
   	int cur=bf.front();
   	cout<<cur<<endl;
   	bf.pop();
   	
   	while(!arr[cur].empty())
   	{
   		if(visited[arr[cur].front()]==0)
   		{
   		  bf.push(arr[cur].front());
   		  visited[arr[cur].front()]=1;
   		}
   		
   	            arr[cur].pop();
   	}
   }
}

int main() {
	
	int node,vertex;
	cin>>node>>vertex;
	
	
	queue<int> arr[node+2];
	
	for(int i=0;i<vertex;i++)
	{
		int a,b;
		cin>>a>>b;
		
		arr[a].push(b);
		arr[b].push(a);
	}
	
	bfs(arr,6);
	
	return 0;
}
