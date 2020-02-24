#include <bits/stdc++.h>
using namespace std;

bool is_Prime(int num){
    if (num < 2) return false;
    if (num == 2) return true;
    for (int i = 2; i <= sqrt(num)+1; i++){
        if (!(num % i)) return false;
    }
    return true;
}

int main(){
    int number;
    cin >> number;
    if (is_Prime(number)) cout << "True";
    else cout << "False";
}