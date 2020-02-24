#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main(){
    struct tm time_proc;
    string time_str;
    getline(cin, time_str);
    strptime(time_str.c_str(), "%d %m %Y", &time_proc);
    switch (time_proc.tm_wday)
    {
    case 0:
        cout << "Sunday";
        break;
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    default:
        break;
    }
}