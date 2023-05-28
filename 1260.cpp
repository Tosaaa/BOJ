// DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF INT_MAX
#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

class GraphNode {
   public:
    int idx;
    list<pair<GraphNode *, int>> adj;
    GraphNode(int _idx);
};

class Graph {
   public:
    int V;
    int E;  // # of directed edges
    vector<GraphNode *> bucket;

    // constructor
    Graph(int _V);

    // Graph() : V(0), E(0) { nodes.clear(); }
    // Graph(int _nc, bool _d = false) : V(_nc), E(0){};
    //  copy constructor
    //  move constructor
    //  destructor

    ~Graph();

    void addNode();
    void addEdge(int v, int w, int weight);  // v->w (directed)
    bool isEdge(int v, int w);               // returns 1 if there is an edge from v to w, otherwise 0.
    void print();
    int getNodeSize();
    int getEdgeSize(bool isDirected);
};

GraphNode::GraphNode(int _idx) {
    idx = _idx;
    adj.clear();
}

// constructor
Graph::Graph(int _V) {
    V = _V;
    E = 0;
    bucket.clear();
    for (int i = 0; i < V; i++)
        bucket.push_back(new GraphNode(i));
}

Graph::~Graph() {
    for (int i = 0; i < V; i++)
        delete bucket[i];
}

void Graph::addNode() {
    bucket.push_back(new GraphNode(V++));
}

void Graph::addEdge(int v, int w, int weight) {
    if (v >= V || w >= V || v < 0 || w < 0) return;
    if (weight == INF) return;  // or weight == 0
    E++;
    bucket[v]->adj.push_back({bucket[w], weight});
}

bool Graph::isEdge(int v, int w) {
    if (v >= V || w >= V || v < 0 || w < 0) return false;

    for (auto it = bucket[v]->adj.begin(); it != bucket[v]->adj.end(); it++)
        if (w == (*it).first->idx) return true;

    return false;
}

void Graph::print() {
    for (auto it1 = bucket.begin(); it1 != bucket.end(); it1++) {
        for (auto it2 = (*it1)->adj.begin(); it2 != (*it1)->adj.end(); it2++) {
            cout << (*it1)->idx << "->" << (*it2).first->idx << ": " << (*it2).second << endl;
        }
        cout << "------------------------------------" << endl;
    }
}

int Graph::getNodeSize() {
    return V;
}

int Graph::getEdgeSize(bool isDirected) {
    return isDirected ? E : E / 2;
}

void DFS_Util(Graph *graph, int s, vector<int> &visited);

void DFS(Graph *graph, int s) {
    vector<int> visited(graph->getNodeSize());
    DFS_Util(graph, s, visited);
    cout << endl;
    return;
}

void DFS_Util(Graph *graph, int s, vector<int> &visited) {
    visited[s] = 1;
    cout << s + 1 << " ";

    list<pair<GraphNode *, int>> adj = graph->bucket[s]->adj;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        if (!visited[(*it).first->idx]) {
            DFS_Util(graph, (*it).first->idx, visited);
        }
    }
    return;
}

void BFS(Graph *graph, int s) {
    vector<int> visited(graph->getNodeSize());
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (visited[v]) continue;
        visited[v] = 1;
        cout << v + 1 << " ";

        list<pair<GraphNode *, int>> adj = graph->bucket[v]->adj;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (!visited[(*it).first->idx]) {
                q.push((*it).first->idx);
            }
        }
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    vector<pii> input(2 * M);

    REP(i, 0, M) {
        int a, b;
        cin >> a >> b;
        input[i].first = a;
        input[i].second = b;
        input[i + M].first = b;
        input[i + M].second = a;
    }
    sort(input.begin(), input.end());

    Graph *graph = new Graph(N);
    REP(i, 0, 2 * M) {
        graph->addEdge(input[i].first - 1, input[i].second - 1, 1);
    }

    DFS(graph, V - 1);
    BFS(graph, V - 1);

    return 0;
}