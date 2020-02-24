#include <bits/stdc++.h>
using namespace std;

int main(){
    int year;
    cin >> year;
    if (year % 400 == 0) {cout << "true"; return 0;}
    else if (year % 100 == 0) {cout << "false"; return 0;}
    else if (year % 4 == 0) {cout << "true"; return 0;}
}