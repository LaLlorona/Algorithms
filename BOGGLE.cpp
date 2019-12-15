/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int testcase_num;
char input_bingo_board[5][5];
int cache[5][5];
int words_num;
string word;




    
int eight_direction_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int eight_direction_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 

bool outOfRange(int y, int x){
    if ((x < 0) || (x > 4) || (y < 0) || (y > 4)){
        return true;
    }
    return false;
}

bool hasWord(int y, int x, const string& word){
    if (outOfRange(y,x)){
        return false;
    }
    
    if (input_bingo_board[y][x] != word[0]){
        return false;
    }
    
    if (word.size() == 1){
        return true;
    }
    
    int& ret = cache[y][x];
    
    if (ret != -1){
        if (ret == 0){
            return false;
        }
        return true;
    }
    
    
    for (int i = 0 ; i < 8; i ++){
        if (hasWord(y + eight_direction_y[i], x + eight_direction_x[i], word.substr(1))){
            return true;
        }
    }
    return false;
    
}

string check_answers(){
    cin >> testcase_num;
    
    for (int i = 0; i < testcase_num; i++){
        string found_word = "NO";
        memset(cache,-1,sizeof(cache));
        //filling input_bingo_board
        for (int y = 0; y < 5; y++){
            string row_bingo_board;
            cin >> row_bingo_board;
            for (int x = 0; x < 5; x++){
                input_bingo_board[y][x] = row_bingo_board[x];
            }
        }
        
        cin >> words_num;
        
        for (int j = 0; j < words_num; j++){
            cin >> word;
            for (int y = 0; y < 5; y++){
                for (int x = 0; x < 5; x++){
                    if (hasWord(y,x,word)){
                        found_word = "YES";
                    }
                }
            }
            
        }
        cout << found_word;
    }
}

int main()
{
    
    
    check_answers();
    return 0;
}
