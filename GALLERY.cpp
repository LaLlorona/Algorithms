#include <iostream>
#include <vector>

using namespace std;

int UNWATCHED = 0; // when the node is not WATCHED
int WATCHED = 1; // Eventhough camera is not INSTALLED in this node, this node is WATCHED because adjacent to the INSTALLED node
int INSTALLED = 2; // camera is INSTALLED

int num_gallery;
int num_hallway;
vector<bool> visited;
vector<vector<int> > gallery;

int num_total_camera;



int DepthFirstSearch(int here) { // return state of 'here'
    visited[here] = true;
    int children_status[3] = {0, 0, 0};
    for (int i = 0; i < gallery[here].size(); i++) {
        int there = gallery[here][i];
        if (!visited[there]) {
            ++children_status[DepthFirstSearch(there)];
        }
    }
    
    if (children_status[UNWATCHED]) {
        num_total_camera++;
        return INSTALLED;
    }
    
    if (children_status[WATCHED]) { // when all of its children is WATCHED
        return WATCHED;
    }
    return UNWATCHED;
}
int InstallCamera() {
    num_total_camera = 0;
    for (int i = 0; i < num_gallery; i++) {
        if(!visited[i] && DepthFirstSearch(i) == UNWATCHED) {
            num_total_camera++;
        }
    }
    return num_total_camera;
}
int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_gallery;
        cin >> num_hallway;
        gallery = vector<vector<int> > (num_gallery, vector<int>(0));
        visited = vector<bool> (num_gallery, false);
        int first, second;
        for (int j = 0; j < num_hallway; j++) {
            cin >> first;
            cin >> second;
            gallery[first].push_back(second);
            gallery[second].push_back(first);
        }
        cout << InstallCamera() << endl;
    }
    
    

    return 0;
}
