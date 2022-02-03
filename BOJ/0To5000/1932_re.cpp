
#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;
const int INF = 987654321;
int cost[MAX][MAX];
int max_cost[MAX][MAX];
int triangle_size;

void FillCost()
{
    max_cost[0][0] = cost[0][0];
    for (int y = 1; y < triangle_size; y++)
    {
        for (int x = 0; x <= y; x++)
        {
            if (x == 0)
            {
                max_cost[y][x] = max_cost[y - 1][x] + cost[y][x];
            }
            else if (x == y)
            {
                max_cost[y][x] = max_cost[y - 1][x - 1] + cost[y][x];
            }
            else
            {
                max_cost[y][x] = cost[y][x] + max(max_cost[y - 1][x], max_cost[y - 1][x - 1]);
            }
        }
    }
    int max_cand = -INF;
    // for (int y = 0; y < triangle_size; y++) {
    //     for (int x = 0; x <= y; x++) {
    //         cout << max_cost[y][x] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int x = 0; x < triangle_size; x++)
    {
        max_cand = max(max_cand, max_cost[triangle_size - 1][x]);
    }
    cout << max_cand << "\n";
}

int main()
{
    // std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    // std::cin.tie(NULL);                    //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    // std::cout.tie(NULL);

    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());                //redirect std::cin to in.txt!

    while (cin >> triangle_size)
    {
        for (int y = 0; y < triangle_size; y++)
        {
            for (int x = 0; x <= y; x++)
            {
                int input_cost;
                cin >> input_cost;
                cost[y][x] = input_cost;
            }
        }
        FillCost();
    }
    return 0;
}
