
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cost[MAX][3];
int num_house;
int accumulate_cost_with_last_color[MAX][3];

void fillAAccumulateCostWithLastColor()
{
    for (int i = 0; i < 3; i++)
    {
        accumulate_cost_with_last_color[0][i] = cost[0][i];
    }
    for (int i = 1; i < num_house; i++)
    {
        accumulate_cost_with_last_color[i][0] = cost[i][0] + min(accumulate_cost_with_last_color[i - 1][1], accumulate_cost_with_last_color[i - 1][2]);
        accumulate_cost_with_last_color[i][1] = cost[i][1] + min(accumulate_cost_with_last_color[i - 1][0], accumulate_cost_with_last_color[i - 1][2]);
        accumulate_cost_with_last_color[i][2] = cost[i][2] + min(accumulate_cost_with_last_color[i - 1][1], accumulate_cost_with_last_color[i - 1][0]);
    }
    cout << min(min(accumulate_cost_with_last_color[num_house - 1][0], accumulate_cost_with_last_color[num_house - 1][1]), accumulate_cost_with_last_color[num_house - 1][2]) << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL);                    //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    std::cout.tie(NULL);

    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> num_house)
    {
        for (int i = 0; i < num_house; i++)
        {
            int r, g, b;
            cin >> r >> g >> b;
            cost[i][0] = r;
            cost[i][1] = g;
            cost[i][2] = b;
        }
        fillAAccumulateCostWithLastColor();
    }

    return 0;
}
