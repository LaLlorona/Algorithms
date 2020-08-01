#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const ll MAX = 200001;

vector<ll> num_planted_here;
vector<ll> dist_planted_here;
vector<ll> number_tree;
vector<ll> dist_tree;

ll num_input;

const ll MOD = 1000000007;

ll init (vector<ll> &input_arr, vector<ll> &tree, ll node, ll start, ll end) { // when the node deals with sum from start to end
	if (start == end) {
		return tree[node] = input_arr[start];
	}
	else {
		ll mid = (start + end) / 2;
		return tree[node] = init(input_arr, tree, 2 * node, start, mid) + init(input_arr, tree, 2 * node + 1, mid + 1, end);
	}
}

ll sum(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {//when node covers start to end, and we want to calculate sum from left to right 
	if (end < left || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		ll mid = (start + end) / 2;
		return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
	}
}

ll update(vector<ll> &tree, ll node, ll start, ll end, ll index, ll diff) {//when node covers start to end, we want to change indexth item 
	if (index < start || end < index) {
		return tree[node];
	}
	
	else if (start == end) { // when the node is leaf node
		return tree[node] += diff;
	}
	else { // when this node is not leaf node 
		ll mid = (start + end) / 2;
		return tree[node] = update(tree, node * 2, start, mid, index, diff) + update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
	
}





int main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	
// 	std::ifstream in("in.txt");
// 	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
// 	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	while (cin >> num_input) {
		num_planted_here.resize(MAX);
		dist_planted_here.resize(MAX);
		
		number_tree.resize(MAX * 4);
		dist_tree.resize(MAX * 4);
		
		ll total_cost = 1;
		ll here;
		cin >> here;
		num_planted_here[here]++;
		dist_planted_here[here] += here;
		update(number_tree, 1, 0, MAX - 1, here, 1);
		update(dist_tree, 1, 0, MAX - 1, here, here);
		
		for (int i = 0; i < num_input - 1; i++) {
			ll current_cost = 0;
			cin >> here;
			ll num_until = sum(number_tree, 1, 0, MAX - 1, 0, here - 1); // number of trees planted until here - 1
			ll sum_until = sum(dist_tree, 1, 0, MAX - 1, 0, here - 1); // sum of dist of trees planted until here - 1
			current_cost += num_until * here - sum_until; 
			
			ll num_from = sum(number_tree, 1, 0, MAX - 1, here + 1, MAX - 1); // number of trees planted from here + 1 to 200000
			 // sum of dist of trees planted from here + 1 to 200000
			ll sum_from = sum(dist_tree, 1, 0, MAX - 1, here + 1, MAX - 1);
			current_cost += sum_from - num_from * here;
			
			//cout << here << " " << num_until << " " << sum_until << " " << num_from << " " << sum_from << " " << current_cost << "\n";
			
			total_cost = ((current_cost % MOD) * (total_cost % MOD)) % MOD;
			
			num_planted_here[here]++;
			dist_planted_here[here] += here;
			update(number_tree, 1, 0, MAX - 1, here, 1);
			update(dist_tree, 1, 0, MAX - 1, here, here);
			
		}
		//cout << "fianl result is ";
		cout << total_cost << "\n";
	}
    

    return 0;
}

