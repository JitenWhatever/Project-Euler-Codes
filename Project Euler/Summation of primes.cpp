/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
https://projecteuler.net/best_posts=010
https://projecteuler.net/overview=010
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

int n = 2000000;
vector<ll> primes(n + 1, 0);

void sieve(){
    for(ll i=2; i*i<=n; i++){
        if(primes[i] == 0){
            for (ll j = i * i; j <= n; j += i) {
                if (primes[j] == 0) {
                    primes[j] = i;
                }
            }
        }
    }

    ll sum = 0; 
    for (ll i = 2; i <= n; ++i) {
        if (primes[i] == 0) {
            primes[i] = i;
            sum += i;
        }
    }

    cout<<sum<<endl;
}

int L, R;
vector<bool> isPrime(R - L + 1, true);

void sieveOnSegments(){
    for (ll i = 2; i * i <= R; ++i) {
        for (ll j = max(i * i, (L + (i - 1)) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    for (ll i = max(L, 2); i <= R; ++i) {
        if (isPrime[i - L]) {
            //then i is prime
        }
    }
}

void optimisedSieve(){
    ll limit;
    cin>>limit;

    --limit;
    ll crossLimit = (sqrt(limit+1) - 1);
    crossLimit = crossLimit >> 1;
    limit = limit >> 1;
    vector<bool> prime(limit + 1 , false);

    for(ll i = 1; i <= crossLimit + 1; i++){
        if(!prime[i]){
            for(ll j = 2*i*(i+1); j<=limit; j += ((2*i) + 1) ){
                prime[j] = true;
            }
        }
    }

    ll sum = 2;
    for(ll i=1; i<=limit; i++){
        if(!prime[i]){
            sum += ((2*i) + 1);
        }
    }

    cout<<sum<<endl;
}
    

void solve(){
    // sieve();
    optimisedSieve();
}

int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}