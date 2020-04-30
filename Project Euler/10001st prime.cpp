/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
https://projecteuler.net/overview=007
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define l long
#define lld long long double
#define ld long double
#define loop(i, a, b) for(i=a; i<b; i++)
#define rloop(i, a, b) for(i=a; i>=b; i--)
#define MAX INT_MAX
#define MIN INT_MIN
#define size(a) a.size()
#define len(a) a.length()
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define read(a) cin>>a
#define echo(a) cout<<a
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int INF = 1e9 + 5;


bool isPrime(int n){
	if(n == 1) return false;
	else if(n < 4) return true;
	else if(n % 2 == 0) return false;
	else if(n < 9) return true;
	else if(n % 3 == 0) return false;
	else{
		int root = floor(sqrt(n));
		int f = 5;
		while(f <= root){
			if(n % f == 0) return false;
			else if(n % (f + 2) == 0) return false;
			f += 6;
		}
		return true;
	}	
}


void solve(){
   int limit = 10001;
   int count = 1;
   int num = 1;
   while(count != limit){
	   num += 2;
	   if(isPrime(num)){
		   count++;
	   }
	   cout<<num<<" ";
   }

   cout<<num<<endl;
}

int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}