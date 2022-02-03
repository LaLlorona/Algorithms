
#include <bits/stdc++.h>


using namespace std;
const int MAX = 100001;
int num_items;
int max_weight;
int item_weights[101];
int item_values[101];

int max_happy_at_weight[MAX];

void fillMaxHappyAtWeight() {
    int current_max_weight = 0;
    for (int i = 0; i < num_items; i++) {
        int item_weight = item_weights[i];
        int item_value = item_values[i];
        for (int j = max_weight-item_weight; j  >=1; j--) {
            if (max_happy_at_weight[j] != 0 ) {
                max_happy_at_weight[j+item_weight] = max(max_happy_at_weight[j+item_weight], max_happy_at_weight[j] + item_value);
            }
        }
        max_happy_at_weight[item_weight] = max(max_happy_at_weight[item_weight], item_value);
        
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

    while(cin >> num_items >> max_weight) {
        memset(max_happy_at_weight, 0, sizeof(max_happy_at_weight));
        for (int i = 0; i < num_items; i++) {
            cin >> item_weights[i];
            cin >> item_values[i];
        }
        fillMaxHappyAtWeight();
        int max_cand = 0;
        for (int i = 0; i <= max_weight; i++) {
            // cout << i << " " << max_happy_at_weight[i] << "\n";
            max_cand = max(max_cand, max_happy_at_weight[i]);
            
        }
        cout << max_cand << "\n";
    }
    return 0;
}


