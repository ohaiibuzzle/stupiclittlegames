#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[2];
    char b[5] = {'t', 'e', 's', 't', NULL};
    for (int i = 0; i < 3; i++){
        cout << "a[" << i << "] is at: " << addressof(a[i]) << endl; //4 bytes long each
    }
        for (int i = 0; i < 3; i++){
        printf("b[%d] is at: %p \n", i, addressof(b[i])); //1 bytes long each
    }
}

//each new variables before the arrays shifts it by sizeof([varieble]) bytes