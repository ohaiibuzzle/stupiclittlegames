#include<bits/stdc++.h>
using namespace std;


int getRandomNumber(){
    srand (time(NULL));
    return rand()%100;
}
int main(){
    auto secret = getRandomNumber();
    bool gameOver = false;
    while (!gameOver){
        int inp;
        cin >> inp;
        if (inp > secret){cout << "Too large" << endl;}
        else if (inp < secret) {cout << "Too small" << endl;}
        else gameOver = true;
    }
    printf("Guessed Correctly!");
    return 0;
}
