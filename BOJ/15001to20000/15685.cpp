#include <bits/stdc++.h>


using namespace std;

int num_curve;
int initial_x;
int initial_y;
int initial_direction;
int generation;

int dct_x[4] = {1, 0, -1, 0};
int dct_y[4] = {0, -1, 0, 1};
bool visited[101][101]; 

bool IsInBound(int x, int y) {
	return (x >= 0 && x <= 100 && y >= 0 && y <= 100);
} 

void DragonCurveMarker(int x, int y, int d, int g) {
	vector<pair<int, int> > curve;
	curve.push_back(make_pair(0, 0));
	curve.push_back(make_pair(dct_x[d], dct_y[d]));
	
	for (int i = 0; i < g; i++) {
		int size_before_add = curve.size();
		int pivot_a = curve[size_before_add - 1].first;
		int pivot_b = curve[size_before_add - 1].second;
		
		for (int j = size_before_add - 2; j >= 0; j--) {
			int current_x = curve[j].first;
			int current_y = curve[j].second;
			curve.push_back(make_pair(pivot_a + pivot_b - current_y, current_x - pivot_a + pivot_b));
		}
	}
	for (int i = 0; i < curve.size(); i++) {
		int moved_x = curve[i].first + x;
		int moved_y = curve[i].second + y;
		if (IsInBound(moved_x, moved_y)) {
			visited[moved_y][moved_x] = true;
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	
	while (cin >> num_curve) {
		int result = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < num_curve; i++) {
			cin >> initial_x >> initial_y >> initial_direction >> generation;
			DragonCurveMarker(initial_x, initial_y, initial_direction, generation);
		}
		for (int x = 0; x < 100; x++) {
			for (int y = 0; y < 100; y++) {
				if (visited[x][y] && visited[x][y + 1] && visited[x + 1][y] && visited[x + 1][y + 1]) {
					result++;
				}
			}
			
		}
		cout << result << "\n";
	}
    

    return 0;
}

