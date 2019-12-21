
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> 
using namespace std;

vector<int> fence(20000);

int FindMaximumArea(int left,int right){
    if (left == right){
        return fence[left];
    }
    
    int middle = (left + right) / 2;
    //Find maximum area that does not include the middle fence
    int max_candidate = 0;
    max_candidate = max(FindMaximumArea(left,middle),FindMaximumArea(middle + 1, right));
    
    int low = middle;
    int high = middle + 1;
    int height = min(fence[low],fence[high]);
    int maximum_area_including_middle = height * 2;
    
    while (left <= low && right >= high) {
        if (right == high && left == low) {
            max_candidate = max(max_candidate, maximum_area_including_middle);
            break;
        }
        else if (right == high || fence[low - 1] >= fence[high + 1]) {
            low -= 1;
            height = min(height, fence[low]);
            maximum_area_including_middle = max(maximum_area_including_middle, height * (high - low + 1));
        }
        else if (left == low || fence[high + 1] > fence[low - 1]) { 
            high += 1;
            height = min(height, fence[high]);
            maximum_area_including_middle = max(maximum_area_including_middle, height * (high - low + 1));
        }
        max_candidate = max(max_candidate, maximum_area_including_middle);
    }
    return max_candidate;
}

int main()
{
    int num_testcase;
    int fence_length;
    int fence_size;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++){
        cin >> fence_length;
        for (int j = 0; j < fence_length ; j++) {
            cin >> fence_size;
            fence[j] = fence_size;
        }
        cout << FindMaximumArea(0,fence_length - 1) << endl;
    }
    
    

    return 0;
}
