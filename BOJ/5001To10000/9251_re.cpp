
#include <bits/stdc++.h>


using namespace std;
const int MAX = 1001;
const int INF = 987654321;
int cache[MAX][MAX];
string str1, str2;


int LCS(int index1, int index2) { //str1[index1] 과 str2[index2] 가 꼭 같을 필요는 없다.
    if (index1 >= str1.size()) {
        return 0;
    }


    int& ret = cache[index1][index2];
    if (ret != -1) {
        return ret;   
    }
    ret = 0;
    int matchedIndex2 = -1;
    for (int i = index2; i < str2.size(); i++) {
        if (str1[index1] == str2[i]) {
            matchedIndex2 = i;
            break;
        }
    }
    if (matchedIndex2 == -1) {
        ret = LCS(index1 + 1, index2);
        return ret;
    }
    ret = max(LCS(index1 + 1, matchedIndex2 + 1) + 1, LCS(index1 + 1, index2));
    return ret;


    
    
    return ret;

}




int main()
{
    std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
    std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    while (cin >> str1 >> str2) {
        memset(cache, -1, sizeof(cache));
        cout << LCS(0, 0) << "\n";
    }
    return 0;
}


