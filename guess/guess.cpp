#include<bits/stdc++.h>
using namespace std;


int getRandomNumber(int max_num){
    srand (time(NULL));
    return rand()%max_num;
}
int main(){
    bool gameRepeat = true; 
    while (gameRepeat){
        int max = 1337;
        auto secret = getRandomNumber(max);
        bool gameOver = false;
        while (!gameOver){
            cout << "Place your bet:";
            int inp;
            cin >> inp;
            if (inp > secret){cout << "Too large" << endl;}
            else if (inp < secret) {cout << "Too small" << endl;}
            else gameOver = true;
        }
        printf("Guessed Correctly! \n");
        printf("Would you like to play again? [y/N]");
        string yesNo;
        cin >> yesNo;
        if (yesNo != "y" || yesNo==""){gameRepeat = false;}
        else printf("Restarting... \n");
    }
    printf("Done!");
    return 0;
}
