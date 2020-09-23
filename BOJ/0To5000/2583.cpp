#include <bits/stdc++.h>


using namespace std;

int width, height;
int num_rectangle;

int current_area;
int dct_y[4] = {-1, 0, 1, 0};
int dct_x[4] = {0, 1, 0, -1};

bool visited[100][100];


bool IsInBound(int y, int x) {
	return (y >= 0 && y < height && x >= 0 && x < width);
}
void FillSafeZone(int current_y, int current_x) {
	visited[current_y][current_x] = true;
	current_area++;
	for (int i = 0; i < 4; i++) {
		int next_y = current_y + dct_y[i];
		int next_x = current_x + dct_x[i];
		if (IsInBound(next_y, next_x) && !visited[next_y][next_x]) {
			FillSafeZone(next_y, next_x);
		}
	}
}

void FillRectangle(int y1, int x1, int y2, int x2) {
	for (int y = y1; y < y2; y++) {
		for (int x = x1; x < x2; x++) {
			visited[y][x] = true;
		}
	}
}



int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	while (cin >> height >> width >> num_rectangle) {
		memset(visited, 0, sizeof(visited));
		vector<int> areas;
		for (int i = 0; i < num_rectangle; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			FillRectangle(y1, x1, y2, x2);
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (!visited[y][x]) {
					current_area = 0;
					FillSafeZone(y, x);
					areas.push_back(current_area);
				}
				
			}
		}
		sort(areas.begin(), areas.end());
		cout << areas.size() << "\n";
		for (int i = 0; i < areas.size(); i++) {
			cout << areas[i] << " ";
		}
	}
    

    return 0;
}

