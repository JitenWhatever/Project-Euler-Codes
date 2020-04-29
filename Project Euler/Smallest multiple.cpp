/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
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
// https://projecteuler.net/overview=005 

ll prime[]  = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29};


// O(n) binary exponentiation   
int pow2(int x, int n) {
    if (n < 0){
        x = 1/ x;
    }

    int  result = 1;
    int power = x;
    
    while (n != 0){
        if (n % 2 != 0){
            result *= power;
        }
        n /= 2;
        power = power * power;
    }
    return result;
}

// O(log(n)) recusrion  

int pow1(int x, int n){
    if(n == 0){
        return 1;
    }

    int temp = pow1(x, n/2);

    if(n%2 == 0){
        return temp * temp;
    }
    else{
        if(n > 0){
            return x*temp*temp;
        }
        else{
            return (temp * temp) / x; 
        }
    }
}

void solve(){

    int k; cin>>k;
    int N = 1;
    bool check = true;
    int limit = sqrt(k);
    int i = 0;
    int ai = 1;
    while(prime[i] <= k){
        ai = 1;
        if(check){
            if(prime[i] <= limit){      
                ai = floor(log10(k)/log10(prime[i]));
            }
            else{
                check = false;
            }
        }
        N = N * pow1(prime[i], ai);
        i++;
    }

    cout<<N<<endl;
}

int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}