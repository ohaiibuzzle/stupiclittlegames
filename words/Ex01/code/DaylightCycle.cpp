#include <bits/stdc++.h>
using namespace std;

int main(){
    bool is_PM = true;
    int i = 12;
    do
    {
        if (i == 12 && is_PM == true) {cout << i << " midnight" << endl; i = 1; is_PM=false;}
        else if (is_PM == false) {cout << i << "am" << endl; i++;}
        else if (is_PM == true) {cout << i << "pm" << endl; i++;}
        if (i == 12 && is_PM==false) {cout << i << " noon" << endl; i = 1; is_PM=true;}
    } while (!(i == 12 && is_PM==true));
    
}