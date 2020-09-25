#include <bits/stdc++.h>


using namespace std;

int num_vertice, num_edge;
int graph[10][2];

void InOrder(int root) {
	if (graph[root][0] != -1) {
		InOrder(graph[root][0]);
	}
	cout << root << " ";
	if (graph[root][1] != -1) {
		InOrder(graph[root][1]);
	}
}
void PreOrder(int root) {
	cout << root << " ";
	if (graph[root][0] != -1) {
		PreOrder(graph[root][0]);
	}
	if (graph[root][1] != -1) {
		PreOrder(graph[root][1]);
	}
}
void InOrderIterative(int root) {
	stack<int> st;
	int current_node = root;
	while (current_node != -1 || !st.empty()) {
		while (current_node != -1) {
			st.push(current_node);
			current_node = graph[current_node][0];
		}
		if (current_node == -1) {
			int here = st.top();
			cout << here << " ";
			st.pop();
			current_node = graph[here][1];
		}
	}
}


void PreOrderIterative(int root) {
	stack<int> st;
	int current_node = root;
	while(current_node != -1 || !st.empty()) {
		while (current_node != -1) {
			st.push(current_node);
			cout << current_node << " ";
			current_node = graph[current_node][0];
		}
		if (current_node == -1) {
			int here = st.top();
			st.pop();
			current_node = graph[here][1];
		}
	}
}
void PostOrder(int root) {
	
	if (graph[root][0] != -1) {
		PostOrder(graph[root][0]);
	}
	if (graph[root][1] != -1) {
		PostOrder(graph[root][1]);
	}
	cout << root << " ";
}
void PostOrderIterative(int root) {
	stack<int> first_st;
	stack<int> second_st;
	int current_node = root;
	first_st.push(current_node);
	while (!first_st.empty()) {
		int here = first_st.top();
		first_st.pop();
		second_st.push(here);
		if (graph[here][0] != -1) {
			first_st.push(graph[here][0]);
		}
		if (graph[here][1] != -1) {
			first_st.push(graph[here][1]);
		}
	}
	while (!second_st.empty()) {
		cout << second_st.top() << " ";
		second_st.pop();
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false); //seperate cin cout and stdin stdout
	std::cin.tie(NULL); //untie cin and cout. When execute cin, it empties cout buffer, which takes time.
	std::cout.tie(NULL);
	
	std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> num_edge;
	memset(graph, -1, sizeof(graph));
	for (int i = 0; i < num_edge; i++) {
		
		int parent, child;
		char direction;
		cin >> parent >> child >> direction;
		if (direction == 'l') {
			graph[parent][0] = child;
		}
		else {
			graph[parent][1] = child;
		}
	}
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 2; j++) {
	// 		if (graph[i][j] != -1) {
	// 			cout << i <<  " " << graph[i][j] << "\n";
	// 		}
	// 	}
	// }
	PostOrder(1);
	cout << "\n";
	PostOrderIterative(1);
	
	
    

    return 0;
}

