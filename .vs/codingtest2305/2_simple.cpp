#include <bits/stdc++.h>

using namespace std;

const int INF = 1987654321;

int NumPossibleFruitBySmallestGiraff(int k, vector<int> giraffe, vector<int> fruits) {
	int minCand = giraffe[0];
	int ans = 0;

	for (int i = 0; i < fruits.size(); i++) {
		if (fruits[i] == minCand) {
			ans++;
		}
	}

	return ans;

}

int solution(int k, vector<int> giraffe, vector<int> fruits) {
    int answer = -1;

	sort(giraffe.begin(), giraffe.end());
	sort(fruits.begin(), fruits.end());

	// cout << "num possible to eat by smallest is " << NumPossibleFruitBySmallestGiraff(k, giraffe, fruits) << "\n";

	return max(0, ((int)giraffe.size() * k- NumPossibleFruitBySmallestGiraff(k, giraffe, fruits)));
}

bool PossibleToEat(int k, vector<int> giraffe, vector<int> fruits, int numAdditionalFruit) {
	int numFullGiraffe = numAdditionalFruit / k;
	int lastGiraffeEat = numAdditionalFruit % k;
	int numTotalGiraffe = giraffe.size();

	map<int, int> fruitNeedToEat; // giraffeHeight, needToEat

	for (int i = 0; i < numTotalGiraffe - numFullGiraffe; i++) {
		if (i == numTotalGiraffe - numFullGiraffe - 1) {
			fruitNeedToEat[giraffe[i]] += k - lastGiraffeEat;
		}
		else {
			fruitNeedToEat[giraffe[i]] += k;
		}
	}

	int currentFeedFood = -1;

	for (auto iter = fruitNeedToEat.rbegin(); iter != fruitNeedToEat.rend(); iter++) {
		// cout << "current giraffe height is " << iter->first << " and need to eat fruits num is " << iter->second << "\n";
		currentFeedFood += iter->second;
		if (currentFeedFood >= fruits.size() || fruits[currentFeedFood] > iter->first) {
			return false;
		}
	}
	return true;
}

int BinarySearch(int k, vector<int> giraffe, vector<int> fruits) {
	int lo = 0;
	int hi = k * giraffe.size();
	int mid = -1;
	int ans = -1;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (PossibleToEat(k,giraffe, fruits, mid)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
		}

	}
	return ans;
}

int solution2(int k, vector<int> giraffe, vector<int> fruits) {
    int answer = -1;

	sort(giraffe.begin(), giraffe.end());
	sort(fruits.begin(), fruits.end());

	return BinarySearch(k,giraffe, fruits);



}



int main()
{
 
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

    

    std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(in.rdbuf()); 

	cout << solution(2, {1,3,5}, {1,2,3,4,5}) << "\n";

	cout << solution2(2, {1,3,5}, {1,2,3,4,5}) << "\n";

	cout << solution(1, {2,2,3}, {2,2,3,4}) << "\n";

	cout << solution2(1, {2,2,3}, {2,2,3,4}) << "\n";

	cout << solution(1, {1,1,3}, {1, 1, 1, 1}) << "\n";

	cout << solution2(1, {1, 1,3}, {1, 1, 1, 1}) << "\n";

	cout << solution(1, {1,1,3, 3, 3}, {1, 1, 1, 1}) << "\n";

	cout << solution2(1, {1, 1,3, 3, 3}, {1, 1, 1, 1}) << "\n";

	cout << solution(2, {1,1,3, 3, 3}, {1, 1, 1, 1}) << "\n";

	cout << solution2(2, {1, 1,3, 3, 3}, {1, 1, 1, 1}) << "\n";

}


  