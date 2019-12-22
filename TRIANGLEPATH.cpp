
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int triangle_path[100][100];
int cache[100][100];
int triangle_size;



int MaxRoot(int y, int x) {
    if (y == triangle_size - 1) {
        return triangle_path[y][x];
    } 
    
    int& ret = cache[y][x];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = triangle_path[y][x];
    ret = max(ret + MaxRoot(y + 1, x) , ret + MaxRoot(y + 1, x + 1));
    
    return ret;
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++){
        cin >> triangle_size; 
        memset(triangle_path,0,sizeof(triangle_path));
        memset(cache,-1,sizeof(triangle_path));
        
        for (int y = 0 ; y < triangle_size; y++) {
            for (int x = 0; x <= y; x++){
                cin >> triangle_path[y][x];
            }
        }  
        cout << MaxRoot(0,0) << endl;
    }
    

    return 0;
}
