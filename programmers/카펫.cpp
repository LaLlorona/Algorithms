#include <bits/stdc++.h>

using namespace std;



vector<int> solution(int brown, int yellow) {
    int a = 1;
	int b = 2 - brown / 2;
	int c = yellow;

	vector<int> answer;

	int answer1 = (-b + (int)sqrt(b * b - 4 * a * c)) / (2 * a);
	int answer2 = (-b - (int)sqrt(b * b - 4 * a * c)) / (2 * a);

	answer.push_back(answer1 + 2);
	answer.push_back(answer2 + 2);

	// cout << answer1 + 2<< " " << answer2 + 2<< "\n";
	sort(answer.begin(), answer.end(), greater<int>());

    return answer;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf());

	solution(10, 2);
	solution(8, 1);
	solution(24, 24);

	

}


  