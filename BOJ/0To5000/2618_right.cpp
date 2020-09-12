#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
int num_city, num_incident;

int distance_when[1001][1001];

pii path_a[1001];
pii path_b[1001];
pii incidents[1001];

int dist_between(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int MinDistFrom(int first_car, int second_car) {
	if (first_car == num_incident || second_car == num_incident) {
		return 0;
	}
	
	int& ret= distance_when[first_car][second_car];
	if (ret != -1) {
		return ret;
	}
	int next_incident = max(first_car, second_car) + 1;
	
	int first_car_solve_next = MinDistFrom(next_incident, second_car) + dist_between(incidents[next_incident], path_a[first_car]);
	int second_car_solve_next = MinDistFrom(first_car, next_incident) + dist_between(incidents[next_incident], path_b[second_car]);
	
	return ret = min(first_car_solve_next, second_car_solve_next);
}

void PrintPath() {
	int first_car = 0;
	int second_car = 0;
	
	for (int i = 1; i <= num_incident; i++) {
		int next_incident = max(first_car, second_car) + 1;
		int first_car_solve_next = MinDistFrom(next_incident, second_car) + dist_between(incidents[next_incident], path_a[first_car]);
		int second_car_solve_next = MinDistFrom(first_car, next_incident) + dist_between(incidents[next_incident], path_b[second_car]);
		
		if (first_car_solve_next < second_car_solve_next) {//choose first car
			cout << "1\n";
			first_car = next_incident;
		}
		else {
			cout << "2\n";
			second_car = next_incident;
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
	
	while (cin >> num_city >> num_incident) {
		memset(distance_when, -1, sizeof(distance_when));
		
		path_a[0] = {1, 1};
		path_b[0] = {num_city, num_city};
		
		for (int i = 1; i <= num_incident; i++) {
			int a, b;
			cin >> a >> b;
			incidents[i] = {a, b};
			path_a[i] = {a, b};
			path_b[i] = {a, b};
		}
		cout << MinDistFrom(0, 0) << "\n";
		PrintPath();
		
	}
    

    return 0;
}

