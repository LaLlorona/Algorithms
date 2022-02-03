
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int LCS[MAX][MAX];
string str1, str2;

void FillLCS()
{
    string appended1 = '0' + str1;
    string appended2 = '0' + str2;
    for (int i = 0; i < appended1.size(); i++)
    {
        for (int j = 0; j < appended2.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
            else if (appended1[i] == appended2[j])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    cout << LCS[str1.size()][str2.size()] << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
    std::cout.tie(NULL);

    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf());                //redirect std::cin to in.txt!

    while (cin >> str1 >> str2)
    {
        FillLCS();
    }
    return 0;
}
