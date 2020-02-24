#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers;
    for (int i = 0; i<5; i++){
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[2];
}
