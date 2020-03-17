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
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {1, -1} }
};

//return true when it is possible to cover board in 'type' of the block 
bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool possible_to_cover = true;
    
    for (int i = 0; i < 3; i++){
        
        int ny = y + coverType[type][i][0]; //y coordinate of place to cover 
        int nx = x + coverType[type][i][1]; // x coordinate of place to cover
        
        if (ny >= board.size() || ny < 0 || nx >= board[0].size() || nx < 0) {
            possible_to_cover = false;
        }
        
        else if ((board[ny][nx] += delta) > 1){
            possible_to_cover = false;
        }
    }
    return possible_to_cover;
}

int numberOfCovers(vector<vector<int>>& board){
    int x = -1;
    int y = -1;
    
    
    for (int i = 0 ; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    if (y == -1){
        return 1;
    }
    
    int ret = 0;
    
    for (int type = 0; type < 4; type++){
        if(set(board, y , x, type, 1)){
            ret += numberOfCovers(board);
        }
        set(board, y, x, type, -1);
    }
    return ret;
    
}

void checkAnswer(){
    cin >> num_testcase;
    
    for (int i = 0; i < num_testcase; i++){
        cin >> height;
        cin >> width;
        
        vector<vector<int> > board(height, vector<int>(width, 0));
        //filling the board
        for (int y = 0; y < height; y++){
            string line;
            cin >> line;
            for (int x = 0; x < width; x++){
                if(line[x] == '#'){
                    board[y][x] = 1;
                }
            }
        }
        cout << numberOfCovers(board) << endl;
       
    }
    
}

int main()
{
    checkAnswer();
    
    return 0;
}
