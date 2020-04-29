/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
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

bool isPrime(ll n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

set<ll> factorize(ll n) {
    set<ll> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.insert(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.insert(n);
    }
    return res;
}

void solve(){
    
    ll n = 600851475143;
    set<ll> factors = factorize(n);

    ll res = -INF;
    for(ll x : factors){
        if(isPrime(x)){
            res = max(res, x);
        }
    }

    cout<<res<<endl;
}


int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
