#include <bits/stdc++.h>
using namespace std;

int getRandomNumber()
{
    return 4; //chosen by fair dice roll.
              //guaranteed to be random.
}

int main()
{
    int value;
    cin >> value;
    if (value <=50) {cout<<"That";}
    else cout << "This";
}