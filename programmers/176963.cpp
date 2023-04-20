#include <bits/stdc++.h>

using namespace std;





vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {

	map<string, int> yearningMap;
	vector<int> answer;

	for (int i = 0; i < name.size(); i++) {
		yearningMap[name[i]] = yearning[i];
	}

	

	for (int i = 0; i < photo.size(); i++) {
		int currrentPhotoYearning = 0;
		for (int j = 0; j < photo[i].size(); j++) {
			string name = photo[i][j];
			currrentPhotoYearning += yearningMap[name];
		}
		answer.push_back(currrentPhotoYearning);
	}
    
    return answer;
}

int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

	vector<string> name = {"may", "kein", "kain", "radi"};
	vector<int> yearning = {5, 10, 1, 3};

	vector<vector<string>> photo = {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};

    

    vector<int> mySolution = solution(name, yearning, photo);

	for (int i = 0; i < mySolution.size(); i++) {
		cout << mySolution[i] << "\n";
	}

}


  