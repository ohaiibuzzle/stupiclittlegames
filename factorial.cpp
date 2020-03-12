#include <bits/stdc++.h>
using namespace std;

long long factorial(long long x){
    if (x < 0) __throw_range_error("Number smaller than 0");
    if (x == 0) return 0;
    if (x == 1) return 1;
    return factorial(x-1)*x;
}

int main(){
    long long n = 6;
    cout << factorial(n);
}

//stack frame for factorial() contains (n-1) [for each x in the recursive loop] + n [return address] addresses
//stack frame **size** is underterminable as it's compiler-dependent