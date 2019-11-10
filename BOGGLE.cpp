/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

char bingo_board[5][5] = 
    {{'U','R','L','P','M'},
    {'X','P','R','E','T'},
    {'G','I','A','E','T'},
    {'X','T','N','Z','Y'},
    {'X','O','Q','R','S'}};
    
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
    
    if (bingo_board[y][x] != word[0]){
        return false;
    }
    
    if (word.size() == 1){
        return true;
    }
    
    
    for (int i = 0 ; i < 8; i ++){
        if (hasWord(y + eight_direction_y[i], x + eight_direction_x[i], word.substr(1))){
            return true;
        }
    }
    return false;
    
}

int main()
{
    
    
    
  
    
    
    
    cout << hasWord(0, 3, "PRETTY");

    return 0;
}


