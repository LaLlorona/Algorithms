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


int MaximumTeams(int girl, int boy, int intern) {
	int teams = 0;
	int left_people = 0;
	if (girl >= boy * 2) {
		teams = boy;
	}
	else {
		teams = girl / 2;
	}
	left_people = girl + boy - teams * 3;
	if (left_people >= intern) {
		return teams;
	}
	else{
		return teams - ceil(double(intern - left_people) / 3);
	}
}



int main()
{
	// std::ios_base::sync_with_stdio(false); 
	// std::cin.tie(NULL); 
	// std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	int n_girl, n_boy, n_intern;
	
	while (cin >> n_girl >> n_boy >> n_intern) {
		cout << MaximumTeams(n_girl, n_boy, n_intern);
	}
    

    return 0;
}

