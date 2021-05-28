#include <bits/stdc++.h>


using namespace std;
const int INF = 987654321;

const int MAX = 10001;

int num_doll;
int doll_size[MAX];
bool is_chosen[MAX];

int clean_doll(int max_index) {
	if (max_index == 0 && is_chosen[max_index]) {
		return 0;
	}
	if (max_index == 0 && !is_chosen[max_index]) {
		return 1;
	}
	if (is_chosen[max_index]) {
		return clean_doll(max_index - 1);
	}
	int current_size = doll_size[max_index];
	int min_cand = 0;
	for (int i = 0; i <= max_index; i++) {
		if (!is_chosen[i]) {
			min_cand++;
		}
	}
	for (int i = max_index - 1; i >= 0; i--) {
		if (!is_chosen[i] && doll_size[i] <= current_size / 2) {
			is_chosen[max_index] = true;
			is_chosen[i] = true;
			min_cand = min(min_cand, clean_doll(max_index - 1) + 1);
			is_chosen[max_index] = false;
			is_chosen[i] = false;
		}
	}
	return min_cand;
}

//int clean_doll_two() {
//	for (int i = num_doll - 1; i >= 0; i--) {
//		int current_size = doll_size[i];
//		if (current_size == INF) {
//			continue;
//		}
//		for (int j = i - 1; j >= 0; j--) {
//			if (doll_size[j] <= current_size / 2) {
//				doll_size[j] = INF;
//				break;
//			}
//		}
//	}
//	int out_doll = 0;
//	for (int i = 0; i < num_doll; i++) {
//		if (doll_size[i] != INF) {
//			out_doll++;
//		}
//	}
//	return out_doll;
//}
int main()
{
	cin >> num_doll;
	for (int i = 0; i < num_doll; i++) {
		cin >> doll_size[i];
		is_chosen[i] = false;
	}
	sort(doll_size, doll_size + num_doll);
	/*if (num_doll > 500) {
		cout << clean_doll_two();
	}
	else {
		cout << clean_doll(num_doll - 1);
	}*/
	cout <<  clean_doll(num_doll - 1);
	return 0;
}

