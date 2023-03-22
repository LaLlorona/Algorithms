#include <bits/stdc++.h>

using namespace std;

const int MAX = 200001;
string inputString;
int numQuestions;
char alphabet;
int from, to;

int alphabetFrequency[26][MAX];

void FillAlphabetFrequency() {
	for (int i = 0; i < inputString.length(); i++) {
		char letter = inputString[i];
		if (i == 0) {
			alphabetFrequency[letter - 'a'][i] = 1;
		}
		else {
			for (int j = 0; j < 26; j++) {
				if (j == letter - 'a') {
					alphabetFrequency[letter - 'a'][i] = alphabetFrequency[letter - 'a'][i - 1] + 1; 
						
				}
				else {
					alphabetFrequency[j][i] = alphabetFrequency[j][i - 1]; 
				}
			}
		}
	}
}

int ReturnAlphabetFrequency(char alphabet, int from, int to) {
	if (from == 0) {
		return alphabetFrequency[alphabet - 'a'][to];
	}
	else {
		return alphabetFrequency[alphabet - 'a'][to] - alphabetFrequency[alphabet - 'a'][from - 1];
	}
}


int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    // std::ifstream in("in.txt");
	// std::streambuf *cinbuf = std::cin.rdbuf(); 
	// std::cin.rdbuf(in.rdbuf()); 

	while (cin >> inputString) {
		cin >> numQuestions;
		memset(alphabetFrequency, 0 ,sizeof(alphabetFrequency));
		FillAlphabetFrequency();
		for (int i = 0 ; i < numQuestions; i++) {
			cin >> alphabet >> from >> to;

		

			cout << ReturnAlphabetFrequency(alphabet, from, to) << "\n";
		}
	}

}


  