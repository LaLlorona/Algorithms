
#include <bits/stdc++.h>

using namespace std;
const int MAX = 301;
int num_stairs;
int cache[MAX];
int score[MAX];

int maxStairScore(int step)
{
    if (step == 0)
    {
        return score[step];
    }

    else if (step == 1)
    {
        return score[step] + score[step - 1];
    }

    else if (step == 2)
    {
        return score[step] + max(score[step - 1], score[step - 2]);
    }

    int &ret = cache[step];

    if (ret != -1)
    {
        return ret;
    }

    ret = score[step] + max(maxStairScore(step - 2), maxStairScore(step - 3) + score[step - 1]);
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL);                    //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    std::cout.tie(NULL);

    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf());                //redirect std::cin to in.txt!

    while (cin >> num_stairs)
    {
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < num_stairs; i++)
        {
            cin >> score[i];
        }
        // for (int i = 0; i < num_stairs; i++)
        // {
        //     cout << maxStairScore(i) << "\n";
        // }
        cout << maxStairScore(num_stairs - 1) << "\n";
    }

    return 0;
}
