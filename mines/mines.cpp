#include<bits/stdc++.h>
using namespace std;

#define numCol 9
#define numRow 9

string play_board[numCol][numRow], real_board[numCol][numRow];

string numbertostr(int x){
    stringstream a;
    a << x;
    return a.str();
}

bool check_mine(int col, int row){
    if (real_board[col][row]=="*") return true;
    else return false;
}

long long get_random_number(){
    return rand()%100;
}
bool decide_mines(){
    if (get_random_number() % 17 == 0) return true;
    else return false;
}

bool is_mine(int col, int row){
    if (real_board[col][row] == "*") return true;
    else return false;
}

int calculate_mine(int row, int col){
    int mines = 0;
    for (int i = row - 1; i <= row + 1; i++){
        if (i < 0 || i >= numRow) continue;
        for (int j = col-1; j <= col + 1; j++){
            if (j < 0 || j >= numCol) continue;
            if (real_board[i][j] == "*"){
                mines++;
            }
        }
    }
    return mines;
}

int replace_explode(int col, int row){
    if (real_board[col][row] == "*"){
        play_board[col][row] == "*";
        return -1;
    }
    else{
        int bombs = calculate_mine(col, row);
        if (bombs != 0){
            play_board[col][row] = numbertostr(bombs);
        }
        else {
            play_board[col][row] = "0";
        }
        return 0;
    }
}

void wipe_board(){
    for(int i = 0; i < numCol; i++){
        for (int j = 0; j < numRow; j++){
            play_board[i][j] = "-";
            real_board[i][j] = "-";
        }
    }
}

int set_up_board(){
    int bomb_amount = 0;
    for(int i = 0; i < numCol; i++){
        for (int j = 0; j < numRow; j++){
            if (decide_mines()){
                real_board[i][j] = "*";
                bomb_amount++;
            }
            
        }
    }
}

void render_board(){
    for (int i = 0; i <= numCol; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < numCol; i++){
        cout << i + 1 << " ";
        for (int j = 0; j < numRow; j++){
            cout << play_board[i][j] << " ";
        }
        cout << endl;
    }
}


void cheat_board(){
    for (int i = 0; i <= numCol; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < numCol; i++){
        cout << i + 1 << " ";
        for (int j = 0; j < numRow; j++){
            cout << real_board[i][j] << " ";
        }
        cout << endl;
    }
}


void game(){
    srand(time(NULL));
    wipe_board();
    int bomb_amount = set_up_board();
    int choices = 0;
    bool exploded = false;
    cout << "cheat:" << endl;
    cheat_board();
    while (!exploded){
        render_board();
        int chose_col, chose_row;
        cout << "Enter your choice [column row]: ";
        cin >> chose_col >> chose_row;
        if (replace_explode(chose_col - 1, chose_row - 1)==-1){render_board(); cout << "You Exploded!"; exploded = true; return;}
        choices++;
        if (bomb_amount == (numCol*numRow) - choices){
            cout << "You Win!" << endl;
            break;
        }
        }
    cout << "cheat:" << endl;
    cheat_board();
}

int main(){
    bool game_over = false;
    while(!game_over){
        game();
        cout << "Play again?";
        string tmp;
        cin >> tmp;
        if (tmp == "y"){game_over = false;}
        else game_over = true;
    }
}