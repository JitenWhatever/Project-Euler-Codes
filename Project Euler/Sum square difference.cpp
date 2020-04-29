/*
The sum of the squares of the first ten natural numbers is,
12+22+...+102=385
The square of the sum of the first ten natural numbers is,
(1+2+...+10)2=552=3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include<bits/stdc++.h>

using namespace std;
//1667096-TrIWOAOHd2kPAVm1gT7nDTpxYTHFVGccPQYP6PRR
int main(int argc, char *argv[]){

    int n; cin>>n;
    int sum = (n*(n+1)*(3*n*n - n - 2))/12;
    cout<<sum<<endl;
    return 0;   
}