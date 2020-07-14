/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define l long
#define lld long long double
#define ld long double
#define REP(index, l, r) for(index = l; index < r; ++index)
#define rREP(index, l, r) for(index = l; index >= r; --index)
#define MAX INT_MAX
#define MIN INT_MIN
#define size(a) a.size()
#define len(a) a.length()
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define read(a) cin>>a
#define echo(a) cout<<a
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

void solve() {

   FILE *file = fopen("problem13.txt", "r");
    char ch;
   vector<int> num;
   vector<int> sum(60);
   vector<int> result;
   for(int row = 0; row < 100; row++){
       for(int col = 0; col < 50; col++){
           fread(&ch, 1, 1, file);
           num.push_back(ch - '0');
       }
       fread(&ch, 1, 1, file);
       reverse(all(num));
       for(int index = 0; index < (int)size(num); ++index) {
           sum[index] += num[index];

           if(sum[index] >= 10) {
               sum[index + 1]++;
               sum[index] -= 10;
           }
       }

       num.clear();
   }

   auto index = sum.rbegin();
   while(*index == 0){
      ++index;
   }

    int first = 10;
    while(--first) {
        cout<<*index++;
    }
}

int main(){
    boost;
    solve();

    return 0;
}
