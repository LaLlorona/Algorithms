#include <bits/stdc++.h>


using namespace std;

int num_students;
int skill_main_supervisor = 0;
int skill_sub_supervisor = 0;
vector<int> students;

int ceiling(int a , int b) {
	if (a % b == 0) {
		return a / b;
	}
	else{
		return a / b + 1;
	}
}
long long MinimumSupervisors() {
	long long ret = 0;
	for (int i = 0; i < students.size(); i++) {
		students[i] -= skill_main_supervisor;
		ret++;
		if (students[i] > 0) {
			ret += ceiling(students[i], skill_sub_supervisor);
			
		}
	}
	return ret;
	
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
	// std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	// std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_students) {
		students.clear();
		int inputs;
		for (int i = 0; i < num_students; i++) {
			cin >> inputs;
			students.push_back(inputs);
		}
		cin >> skill_main_supervisor >> skill_sub_supervisor;
		cout << MinimumSupervisors() << "\n";
	}
    

    return 0;
}

