#include <bits/stdc++.h>
using namespace std;

int get_random_number(int max){
    srand(time(NULL));
    return rand()%max;
}

int main(){
    bool game_over = false;
    while (!game_over){
        int min = 0, max = 1337; // Change max value here
        int random = get_random_number(max);
        int number;
        char tmp;
        cout << "[M]achine or [H]uman input?:";
        cin >> tmp;
        if (tmp == 'H'){
            cout << "Your selection (" << min << "-" << max << "):";
            cin >> number;
            if (number > max || number < min){cout << "Invalid input. Quitting..." << endl; return -1;}
        }
        else if (tmp == 'M'){
            number = random;
        }    
        else{
            cout << "Invilid input. Quitting..." << endl;
            return -1;
        }
        
        int pivot = ((max + min)/2);
        cout << "Now finding..." << endl;
        if (number == min || number == max){cout << "Got it:" << number << endl; return 0;}
        while (pivot != number){
            if (pivot < number){
                min = pivot;
                pivot = (min + max)/2;
                cout << pivot << "...";
            }
            else if (pivot > number){
                max = pivot;
                pivot = (min + max)/2;
                cout << pivot << "...";
            }
            }
        cout << "Got it: " << pivot << endl;
        cout << "Play again? [y/n]: ";
        cin >> tmp;
        if (tmp != 'y') {game_over = true;}
    }
    return 0;
}