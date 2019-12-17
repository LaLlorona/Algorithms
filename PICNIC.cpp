

#include <iostream>
#include <string.h>

using namespace std;

int num_testcase;
int num_children;
int num_pairs;
bool are_friends[10][10];

int countParing(bool matched[10],int number_children){
    int first_unmatched_child = -1;
    
    for (int i = 0; i < number_children; i++){
        if(matched[i] == 0 ){
            first_unmatched_child = i;
            break;
        }
    }
    
    if(first_unmatched_child == -1){
        return 1;
    }
    
    int ret = 0;
    
    for (int friend_cand = 0; friend_cand < number_children; friend_cand++){
        
        if(are_friends[first_unmatched_child][friend_cand]){
            
            matched[friend_cand] = matched[first_unmatched_child] = true;
            ret +=countParing(matched, number_children);
            matched[friend_cand] = matched[first_unmatched_child] = false;
        }
    }
    return ret;
}

void checkAnswer(){
    cin >> num_testcase;
    for (int i =0 ; i < num_testcase; i++){
        memset(are_friends,0,sizeof(are_friends));
        cin >> num_children;
        cin >> num_pairs;
        int first_friend;
        int second_friend;
        for (int j = 0; j < num_pairs; j++){
            cin >> first_friend;
            cin >> second_friend;
            are_friends[first_friend][second_friend] = 1;
            are_friends[second_friend][first_friend] = 1;
        }
        bool initial[10] = {false,false,false,false,false,false,false,false,false,false};
        
        for (int y = 0; y < 10; y++){
            for (int x = 0; x < 10; x++){
                cout<< are_friends[y][x] ;
            }
            cout << endl;
        }
        
   
        
        cout << num_children << endl;
        
        cout << num_pairs << endl;
        
        
        cout << countParing(initial,num_children);
    }
    
    
}

int main()
{
   
    checkAnswer();

    return 0;
}
