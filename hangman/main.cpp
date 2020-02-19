#include<bits/stdc++.h>
using namespace std;

class Hangman{
    private:
        int state;
        string hang_state[7];
    public:
        Hangman(){
            state = 0;
            hang_state[0]="    +---+\n\
    |   |\n\
        |\n\
        |\n\
        |\n\
        |\n\
=========";
            hang_state[1]="    +---+\n\
    |   |\n\
    0   |\n\
        |\n\
        |\n\
        |\n\
=========";
            hang_state[2]="    +---+\n\
    |   |\n\
    0   |\n\
    |   |\n\
        |\n\
        |\n\
=========";
            hang_state[3]="    +---+\n\
    |   |\n\
    0   |\n\
   /|   |\n\
        |\n\
        |\n\
=========";
            hang_state[4]="    +---+\n\
    |   |\n\
    0   |\n\
   /|\\  |\n\
        |\n\
        |\n\
=========";
            hang_state[5]="    +---+\n\
    |   |\n\
    0   |\n\
   /|\\  |\n\
   / \\  |\n\
        |\n\
=========";
            hang_state[6]="    +---+\n\
    |   |\n\
    0   |\n\
   /|\\  |\n\
   / \\  |\n\
        |\n\
=========";
        }
        void one_more(){
            state++;
        }
        bool check_death(){
            if (state < 5) return false;
            else return true;
        }
        void render(){
            cout << hang_state[state];
        }
};

int get_random_number(){
    srand(time(NULL));
    return rand()%3000;
}

vector<string> get_random_word_list(string filename){
    ifstream wordlist;
    wordlist.open(filename);
    vector<string> wl;
    string word;
    if (!wordlist.fail()){
        for (int i=0; i < 3000; i++){
            getline(wordlist, word);
            wl.push_back(word);
        }
    }
    return wl;
}

string get_random_word_from_list(string filename){
    vector<string> words = get_random_word_list(filename);
    string retstr = words[get_random_number()];
    return retstr;
}

int main(){
    string secret_word = "something", working_set;
    secret_word = get_random_word_from_list("words");
    for (auto it = secret_word.begin(); it != secret_word.end(); it++){
        working_set += "_";
        }
    bool game_over = false, win=false;
    Hangman man;
    man.render();
    cout << endl;
    cout << working_set << endl;
    while (!game_over){
        char ch;
        int counter = 0;
        bool got_one = false;
        cin >> ch;
        for (auto it = secret_word.begin(); it != secret_word.end(); it++){
            if (*it == ch){
                working_set[counter]=secret_word[counter];
                got_one = true;
            }
            counter++;
        }
        if (!got_one){man.one_more();}
        man.render();
        cout << endl;
        cout << working_set << endl;
        if (working_set == secret_word){
            cout << "Great. You get a 404" << endl;
            game_over=true; win=true;
        }
        else
        {
            game_over=man.check_death();
        }
        
    }
    if (!win){cout << "You are dead!";}
    return 0;
}