#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
	int to, flow, capacity;
	Edge(int to, int capacity) {
		this->to = to;
		this->flow = 0;
		this->capacity = capacity;
	}
}

vector<Edge> graph[5000];
int vertices, edges;
long long maxFlow;

long long augmentPath(int source, int destination) {
	vector<Edge *> prev(vertices);
	fill(prev.begin(), prev.end(), NULL);

	queue<int> nodes;
	nodes.push(source);

	while (!nodes.empty()) {
		int node = q.top();
		q.pop();

		for (Edge edge : graph[node]) {
			if (prev[edge.to] == NULL && edge.capacity > edge.flow) {
				prev[edge.to] = &edge;
				nodes.push(edge.to);
			}
		}
	}

	if (prev[destination] == 0)
		return 0;

	long long flow = 0;
	for (Edge edge : graph[destination]) {

	}
}

int main() {
	cin >> vertices >> edges;
	for (int i = 0; i < edges; i++) {
		int from, to, capacity;
		cin >> from >> to >> capacity;
		graph[from - 1].push_back(Edge(to - 1, capacity));
		graph[to - 1].push_back(Edge(from - 1, capacity));
	}

	maxFlow = 0;
	while (long long flow = augmentPath(0, vertices - 1))
		maxFlow += flow;

	return 0;
}