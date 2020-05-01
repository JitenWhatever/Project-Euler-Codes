/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
https://projecteuler.net/overview=009  
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

void bruteForce(){
    // sum >=1 000 000 then TLE
    int sum = 1000;
    for(int a=3; a < (sum - 3)/3; a++){
        for(int b=a+1; b < (sum-1-a)/2; b++){
            int c = sum - a - b;
            if(c*c == (a*a + b*b)){
                cout<<a*b*c<<"\n";
                return ;
            }  
        }
    }
}


void parametrisationPythagoreanTriplets(){
    /*
    {a, b, c} is primitive if gcd(a, b, c) = 1;
    all primitive Pythagorean triplets can be represented as
    a=m^2−n^2,   b= 2*m*n,   c=m^2+n^2  where m > n > 0 gcd(m, n) = 1 exactly one of m, n is even
    From any Pythagorean triplet you get a primitive one by dividing out
    the greatestcommon divisor, so every Pythagorean triplet has a unique
    representation i.e  a=d*(m^2−n^2),   b= 2*m*n*d,   c=d*(m^2+n^2);
    gcd(a, b, c) = d, and exactly one of m, n is even and gcd(m, n) = 1;
    a+b+c= 2*m*(m + n)*d
    This implementation is rather fast and scales well,sum >= 10^10 are processed in fractionsof a second
    ,it can still beimproved a bit by making use of the primefactorisation ofs/2  
    */

   int sum = 1000;
   int sum2 = sum/2;
   int mlimit = ceil(sqrt(sum2)) - 1;
   int k = 0;
   for(int m=2; m<=mlimit; m++){
       if(sum2%m == 0){
           int sum_m = sum2/m;
           while(sum_m % 2 == 0){
            sum_m /= 2;
           }

           if(m % 2 == 1){
                k = m+2;
           }
           else{
               k = m+1;
           }

           while((k < (2 * m)) && (k <= sum_m) ){
               if((sum_m % k == 0) && __gcd(k, m) == 1){
                   
                   int d = sum2/(k*m);
                   int n = k - m;
                   int a = d*(m*m-n*n);
                   int b = 2*d*m*n;
                   int c = d*(m*m + n*n);
                   cout<<a*b*c<<"\n";
                   return ;
               }
               k = k + 2;
           }
       }
   }    
}



void solve(){
//    bruteForce();
parametrisationPythagoreanTriplets();
}

int main(){
	boost;
	int t; cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}