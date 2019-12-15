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
int cache[5][5][10];
int words_num;
string word;




    
int eight_direction_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int eight_direction_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 

int outOfRange(int y, int x){
    if ((x < 0) || (x > 4) || (y < 0) || (y > 4)){
        return 1;
    }
    return 0;
}

int hasWord(int y, int x, int index, const string& word){
    if (outOfRange(y,x) == 1){
        return 0;
    }
    
    int& ret = cache[y][x][index];
    
    if (ret != -1){
        return ret;
    }
    
     if (input_bingo_board[y][x] != word[index]){
        ret = 0;
        return 0;
    }
    
    if ((index +1) >= word.size()){
        ret = 1;
        return 1;
    }
    
    
    
    
    for (int i = 0 ; i < 8; i ++){
        if (hasWord(y + eight_direction_y[i], x + eight_direction_x[i], index+1, word)){
            ret = 1;
            return 1;
        }
        
    }

    return ret = 0;
    
}

void check_answers(){
    cin >> testcase_num;
    
    for (int i = 0; i < testcase_num; i++){
        string found_word;
        
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
            found_word = "NO";
           
            for (int y = 0; y < 5; y++){
                for (int x = 0; x < 5; x++){
                    memset(cache,-1,sizeof(cache));
                    if (hasWord(y,x,0,word) == 1){
                        found_word = "YES";
                        break;
                    }
                }
                if(found_word == "YES"){
                    break;
                }
            }
            cout << word;
            cout << " ";

            cout << found_word << endl;
            
        }
        
    }
}

int main()
{
    
    
    check_answers();
    return 0;
}
