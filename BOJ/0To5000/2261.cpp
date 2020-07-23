#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 987654321;
int num_point;


ll DistanceSquare(pii point1, pii point2) {
	return (ll)(point1.first - point2.first) * (ll)(point1.first - point2.first) + (ll)(point1.second - point2.second) * (ll)(point1.second - point2.second);
}



int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
//     std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//     std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_point) {
		vector<pii> points;
		map<pii, int > candidates;
		for (int i = 0; i < num_point; i++) {
			int x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}
		sort(points.begin(), points.end());
		candidates[{points[0].second, points[0].first}] = 1;
		candidates[{points[1].second, points[1].first}] = 1;
		
		ll ans = DistanceSquare(points[0], points[1]);
		int last = 0;
		for (int i = 2; i < num_point; i++) {
			while (last < i) {
				int dx = points[i].first - points[last].first;
				if (dx * dx < ans) {
					break;
				}
				candidates.erase({points[last].second, points[last].first});
				last++;
			}
			ll dist = sqrt(ans);
			auto it_row = candidates.lower_bound({points[i].second - dist, -INF});
			auto it_high = candidates.upper_bound({points[i].second + dist, INF});
			for (auto it = it_row; it != it_high; it++) {
				ans = min(ans, DistanceSquare({it->first.second, it->first.first}, points[i]));
			}
			candidates[{points[i].second, points[i].first}] = 1;
		}
		cout << ans << "\n";
		
		
		
	}
    

    return 0;
}

