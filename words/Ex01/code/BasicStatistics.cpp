#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp; 
        cin >> tmp;
        numbers.push_back(tmp);
    }
    double sum = 0;
    for (auto i = numbers.begin(); i != numbers.end(); i++) sum += *i;
    cout << "Mean: " << sum/numbers.size() << endl;
    cout << "Max: " << *max_element(numbers.begin(), numbers.end()) << endl;
    cout << "Min: " << *min_element(numbers.begin(), numbers.end()) << endl;
}