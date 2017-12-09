#include<iostream>
using namespace std;

// find C(n,r)
// Standard recursive formula for computing C(n,r)
// C(n,r) = C(n-1,r-1) + C(n-1,r)
// where C(n,0) = C(n,n) = 1
int choose(int n,int r) {
   if(r == 0 || r == n)
      return 1;
   // store C(n,r) in a matrix   
   int c[n+1][r+1];
   int i,j;
   for(i=0;i<=n;i++) {
      // C(i,0) = 1 for i = 0...n  
      c[i][0] = 1;
   }
   for(j=0;j<=r;j++) {
      // if n = 0, C(n,r) = 0 for all 'r'
      c[0][j] = 0;
   }
   for(i=1;i<=n;i++) {
      for(j=1;j<=r;j++) 
      {
	         if (i == j) {
	            // C(n,n) = 1
	            c[i][j] = 1;
	         }
	         else if (j > i) {
	            // case when r > n in C(n,r)        
	            	c[i][j] = 0;
	         }
	         else {
	            // apply the standard recursive formula        
	            c[i][j] = c[i-1][j-1] + c[i-1][j];     ////this is the main formula to calculate.ncr print the array to check
	         }
      }
   }
   
   
   return c[n][r];
}



// main
int main() {
   int n = 5,r = 2;
   int comb = choose(n,r);
   cout<<"C("<<n<<","<<r<<") :: "<<comb;
   cout<<endl;
   return 0;
}
