#include <iostream>
#include <algorithm>
using namespace std;


void coinchange()
{
	int coin,amount;
	cin>>coin>>amount;
	
	int coins[coin+2]={};
	
	for(int i=0;i<coin;i++)
	{
	   cin>>coins[i];
	}

	
	int possible[amount+2]={},way[amount+2]={};
	
	possible[0]=1;
	way[0]=1;
	
	for(int b=0;b<coin;b++)
	{
                 for(int a=1;a<=amount;a++)
                 {
                     if(coins[b]<=a && possible[a-coins[b]]==1)
                     {
                     	way[a]+=way[a-coins[b]];
                  
                     	possible[a]=1;
                     }
                 }
            
	}
	
	cout<<way[amount]<<endl;
	
	
}

int main() {
	
	coinchange();
	return 0;
}
