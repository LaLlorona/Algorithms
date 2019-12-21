/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fence;

int FindMaximumArea(int left,int right){
    if (left == right){
        return fence[left];
    }
    
    int middle = (left + right) / 2;
    
    //Find maximum area that does not include the middle fence
    int max_candidate = max(FindMaximumArea(left,middle),FindMaximumArea(middle + 1, right));
    
    int low = middle;
    int high = middle + 1;
    int height = min(fence[low],fence[high]);
    int maximum_area_including_middle = height * 2;
   
    
    while (left <= low && right >= high) {
        if (right == high && left == low) {
            return maximum_area_including_middle;
            
        }
        
        else if (right == high || fence[low - 1] > fence[high]) {
                low -= 1;
                height = min(height, fence[low]);
                maximum_area_including_middle = max(maximum_area_including_middle, height * (high - low + 1));
            }
        
        else if (left == low || fence[high + 1] > fence[low]) {
            high +=1;
            height = min(height, fence[high]);
            maximum_area_including_middle = max(maximum_area_including_middle, height * (high - low + 1));
            
            
        }
    }
    return max(maximum_area_including_middle, max_candidate);
    
    
    

}

int main()
{
    cout<<"Hello World";

    return 0;
}
