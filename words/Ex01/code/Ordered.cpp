#include <bits/stdc++.h>
using namespace std;

int main(){
    long a, b, c;
    cin >> a >> b >> c;
    auto bo = (a < b && b < c);
    if (bo) cout << "true";
    else cout << "false";
}