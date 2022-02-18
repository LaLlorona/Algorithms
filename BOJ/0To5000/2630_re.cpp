
#include <bits/stdc++.h>

using namespace std;
const int MAX = 128;
int max_size;
bool paper[MAX][MAX];

bool checkSameColor(int begin_y, int begin_x, int paper_size, bool check)
{
    if (paper_size == 1)
    {
        return true;
    }
    else
    {
        for (int y = 0; y < paper_size; y++)
        {
            for (int x = 0; x < paper_size; x++)
            {
                if (paper[begin_y + y][begin_x + x] != check)
                {
                    return false;
                }
            }
        }
        return true;
    }
}

int numPaper(int begin_y, int begin_x, int paper_size, bool check)
{
    // if (checkSameColor(begin_x, begin_y, paper_size, check))
    // {
    //     return 1;
    // }

    if (paper_size == 1 && paper[begin_y][begin_x] == check) {
        
        return 1;
    }
    else if (paper_size == 1 && paper[begin_y][begin_x] != check) {
        
        return 0;
    }

    else if (checkSameColor(begin_y, begin_x, paper_size, check))
    {
       
        return 1;
    }
    else
    {
        int result = numPaper(begin_y, begin_x, paper_size / 2, check) + numPaper(begin_y, begin_x + paper_size / 2, paper_size / 2, check) 
        + numPaper(begin_y + paper_size / 2, begin_x, paper_size / 2, check) + numPaper(begin_y + paper_size / 2, begin_x + paper_size / 2, paper_size / 2, check);
        
        return result;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); // seperate cin cout and stdin stdout
    std::cin.tie(NULL);                    // untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    std::cout.tie(NULL);

    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
    // std::cin.rdbuf(in.rdbuf());                // redirect std::cin to in.txt!

    while (cin >> max_size)
    {
        for (int y = 0; y < max_size; y++)
        {
            for (int x = 0; x < max_size; x++)
            {
                cin >> paper[y][x];
            }
        }
        cout << numPaper(0, 0, max_size, 0) << "\n"
             << numPaper(0, 0, max_size, 1) << "\n";
    }

    return 0;
}
