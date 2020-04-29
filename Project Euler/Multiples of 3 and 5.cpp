/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

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

void solve(){
    int n; cin>>n;
    n--;
    int sum=3*int(n/3)*(1+int(n/3))/2 + 5*int(n/5)*(1+int(n/5))/2 - 15*int(n/15)*(1+int(n/15))/2;

    cout<<sum<<endl;

}

int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}