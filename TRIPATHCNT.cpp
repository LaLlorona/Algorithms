#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int triangle_path[100][100];
int cache[100][100];
int count_cache[100][100];
int triangle_size;



int MaxRoot(int y, int x) {
    int& ret = cache[y][x];
    
    if (ret != -1) {
        return ret;
    }
    
    if (y == triangle_size - 1) {
        return ret = triangle_path[y][x];
    } 
    
    
    
    ret = triangle_path[y][x];
    ret = max(ret + MaxRoot(y + 1, x) , ret + MaxRoot(y + 1, x + 1));
    
    return ret;
}

int CountMaxRoot(int y, int x) {
    int& ret = count_cache[y][x];
    
    if (ret != -1) {
        return ret;
    }
    
    if (y == triangle_size - 1) {
        return ret = 1;
    }
    
    
    if (cache[y + 1][x + 1] > cache[y + 1][x]) {
        return ret = CountMaxRoot(y + 1, x + 1);
    }
    
    else if (cache[y + 1][x + 1] < cache[y + 1][x]) {
        return ret = CountMaxRoot(y + 1, x);
    }
    else{
        return ret = CountMaxRoot(y + 1, x) + CountMaxRoot(y + 1, x + 1);
    }
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++){
        cin >> triangle_size; 
        memset(triangle_path,0,sizeof(triangle_path));
        memset(cache,-1,sizeof(triangle_path));
        memset(count_cache,-1,sizeof(count_cache));
        
        for (int y = 0 ; y < triangle_size; y++) {
            for (int x = 0; x <= y; x++){
                cin >> triangle_path[y][x];
            }
        }  
        MaxRoot(0,0);
        cout << CountMaxRoot(0,0) << endl;
    }
    

    return 0;
}
