#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>



using namespace std;

int papers[3];
int arr[2200][2200];
int paper_size = 0;

void PreProcess() {
	for (int y = 0; y < paper_size; y++) {
		for (int x = 0; x < paper_size; x++) {
			cin >> arr[y][x];	
		}
	} 
	memset(papers, 0, sizeof(papers));
	
}

int CheckSame(int size, int begin_y, int begin_x) {
	int check = arr[begin_y][begin_x];
	for (int y = begin_y; y < begin_y + size; y++) {
		for (int x = begin_x; x < begin_x + size; x++) {
			if (arr[y][x] !=check) {
				return 2;
			}
		}
	}
	return check;
}

void CountPapers(int size, int begin_y, int begin_x) {
	int same = CheckSame(size, begin_y, begin_x);
	
	if (same != 2) {
		papers[same + 1]++;
	}
	else {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				CountPapers(size / 3, begin_y + y * (size / 3) , begin_x + x * (size / 3));
			}
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
	
	while (cin >> paper_size) {
		PreProcess();
		CountPapers(paper_size, 0, 0);
		for (int i = 0 ; i < 3; i++) {
			cout << papers[i] << "\n";
		}
	}
    

    return 0;
}

