/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
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

/*
https://www.xarg.org/puzzle/project-euler/problem-4/
*/

bool isPalindrome(ll num){
    ll n = 0;
    ll m = num;
    while(num > 0){
        n = n * 10 + num % 10;
        num = num / 10 | 0;
    }

    return n == m;
}
void solve(){
    ll res = 0;

    for(ll a = 990; a > 99; a = a - 11) {
        for(ll b = 999; b > 99; b--){
            ll temp = a*b;
            if(res < temp && isPalindrome(temp)){
                res = temp;
                break;
            }
            else if (res > temp){
                break;
            }
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
