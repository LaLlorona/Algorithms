#include <bits/stdc++.h>


using namespace std;

int n, a, b;
string alphabet[26] = {"a", "b", "c", "d" , "e", "f", "g", "h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

string MakeString() {
	string ret = "";
	for (int i = 0; i < n; i++) {
		ret += alphabet[i % b];
	}
	return ret;
} 


int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	int num_testcase;
	
	cin >> num_testcase;
	while (num_testcase--) {
		cin >> n >> a >> b;
		cout << MakeString() << "\n";
	}
	
    

    return 0;
}

