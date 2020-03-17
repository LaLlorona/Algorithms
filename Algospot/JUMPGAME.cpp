#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;


int board[100][100];
int cache[100][100];
int board_size;

int IsItPossibleToFinish(int y,int x){
    if (y >= board_size || x >= board_size) {
        return 0;
    }
    
    if ((y == board_size - 1) && (x == board_size -1)) {
        return 1;
    }
    
    int& ret = cache[y][x];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    
    if (IsItPossibleToFinish(y + board[y][x], x) || IsItPossibleToFinish(y, x + board[y][x])) {
        ret = 1;
        return ret;
    }
    return ret;
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++){
        cin >> board_size;
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));
        int board_pannel_num;
        //filling the board;
        for (int y = 0 ; y < board_size; y++){
            for (int x = 0; x < board_size; x++){
                cin >> board_pannel_num;
                board[y][x] = board_pannel_num;
            }
        }
        
        if (IsItPossibleToFinish(0,0) == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
        
    }

    return 0;
}
