#include <iostream>
#include <vector>
using namespace std;

int num_testcase;
int height;
int width;
vector<vector<int> > board;

const int coverType[4][3][2] = {
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {1, 0}, {1, -1} }
};

//return true when it is possible to cover board in 'type' of the block 
bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool possible_to_cover = true;
    for (int i = 0; i < 3; i++){
        int ny = y + coverType[type][i][0]; //y coordinate of place to cover 
        int nx = x + coverType[type][i][1]; // x coordinate of place to cover
        
        if (ny >= board.size() || nx >= board[0].size() || (board[ny][nx] + delta) > 1){
            possible_to_cover = false;
        }
    }
    return possible_to_cover;
}

int main()
{
    
    

    return 0;
}
