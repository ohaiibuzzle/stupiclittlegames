#include <bits/stdc++.h>
using namespace std;

string gen_fib(long times){
    string f0 = "a", f1 = "b";
    if(times == 0) return f0;
    else if(times == 1) return f1;
    else
    {
        return gen_fib(times-1) + gen_fib(times-2);
    }
}

int main(){
    long times;
    cin >> times;
    cout << gen_fib(times);
}