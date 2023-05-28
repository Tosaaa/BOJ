// Strongly Connected Components
// https://www.acmicpc.net/problem/2150

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

void DFS(Graph *graph, int v, vi &visited, stack<int> &s);
void DFS(Graph *graph, int v, vi &visited, priority_queue<int, vector<int>, greater<int>> &pq);

vector<priority_queue<int, vector<int>, greater<int>>> kosaraju(Graph *graph) {
    int V = graph->getNodeSize();
    stack<int> s;
    vi visited(V);
    REP(i, 0, V) {
        if (!visited[i])
            DFS(graph, i, visited, s);
    }

    Graph *trans = new Graph(V);
    REP(i, 0, V) {
        for (auto it = graph->bucket[i]->adj.begin(); it != graph->bucket[i]->adj.end(); it++) {
            trans->addEdge((*it).first->idx, i, (*it).second);
        }
    }

    REP(i, 0, V) {
        visited[i] = 0;
    }

    vector<priority_queue<int, vector<int>, greater<int>>> scc;
    while (!s.empty()) {
        if (!visited[s.top()]) {
            priority_queue<int, vector<int>, greater<int>> pq;
            DFS(trans, s.top(), visited, pq);
            scc.push_back(pq);
        }
        s.pop();
    }
    delete trans;
    return scc;
}

void DFS(Graph *graph, int v, vi &visited, stack<int> &s) {
    visited[v] = 1;

    for (auto it = graph->bucket[v]->adj.begin(); it != graph->bucket[v]->adj.end(); it++) {
        if (!visited[(*it).first->idx]) {
            DFS(graph, (*it).first->idx, visited, s);
        }
    }
    s.push(v);
    return;
}

void DFS(Graph *graph, int v, vi &visited, priority_queue<int, vector<int>, greater<int>> &pq) {
    visited[v] = 1;
    pq.push(v + 1);

    for (auto it = graph->bucket[v]->adj.begin(); it != graph->bucket[v]->adj.end(); it++) {
        if (!visited[(*it).first->idx]) {
            DFS(graph, (*it).first->idx, visited, pq);
        }
    }
    return;
}

bool cmp(priority_queue<int, vector<int>, greater<int>> a, priority_queue<int, vector<int>, greater<int>> b) {
    return a.top() < b.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    Graph *graph = new Graph(V);

    int a, b;
    REP(i, 0, E) {
        cin >> a >> b;
        graph->addEdge(a - 1, b - 1, 1);
    }

    vector<priority_queue<int, vector<int>, greater<int>>> ans = kosaraju(graph);
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    REP(i, 0, ans.size()) {
        while (!ans[i].empty()) {
            cout << ans[i].top() << " ";
            ans[i].pop();
        }
        cout << -1 << endl;
    }

    delete graph;

    return 0;
}