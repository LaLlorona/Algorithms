#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int num_seat, num_VIP;
ll possible_sitting[41];
int VIPs[41];




int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	possible_sitting[0] = 1;
	possible_sitting[1] = 1;
	possible_sitting[2] = 2;
	
	for (int i = 3; i < 41; i++) {
		possible_sitting[i] = possible_sitting[i - 1] + possible_sitting[i - 2];
	}
	

	while (cin >> num_seat >> num_VIP) {
		for (int i = 0; i < num_VIP; i++) {
			cin >> VIPs[i];
		}
		
		ll result = 1;
		
		if (num_VIP == 1) {
			result = possible_sitting[VIPs[0] - 1] * possible_sitting[num_seat - VIPs[0]];
			
		}
		else if (num_VIP == 0) {
			result = possible_sitting[num_seat];
		}
		else {
			result *= possible_sitting[VIPs[0] - 1];
			result *= possible_sitting[num_seat - VIPs[num_VIP - 1]];
			for (int i = 0; i < num_VIP - 1; i++) {
				result *= possible_sitting[VIPs[i + 1] - VIPs[i] - 1];
			}
		}
		cout << result << "\n";
		
	}
    

    return 0;
}

