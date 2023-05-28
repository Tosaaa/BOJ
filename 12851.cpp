// 숨바꼭질 2
// https://www.acmicpc.net/problem/12851

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <utility>

#define INF INT_MAX
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

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
    if (weight == INF) return;
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

pair<int, int> BFS(Graph *graph, int s, int e) {
    vector<int> visited(graph->getNodeSize());
    queue<pair<int, int>> q;

    visited[s] = 1;
    q.push({s, 0});

    int ans = 0;
    int ans_depth = -1;
    while (!q.empty()) {
        int v = q.front().first;
        int depth = q.front().second;
        q.pop();
        visited[v] = 1;
        if (ans_depth != -1 && ans_depth != depth) {
            break;
        }
        if (v == e) {
            ans++;
            ans_depth = depth;
        }

        list<pair<GraphNode *, int>> adj = graph->bucket[v]->adj;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (!visited[(*it).first->idx]) {
                q.push(make_pair((*it).first->idx, depth + 1));
            }
        }
    }
    return make_pair(ans_depth, ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    Graph *graph = new Graph(100001);
    graph->addEdge(0, 1, 1);
    REP(i, 1, 100000) {
        if (2 * i <= 100000) {
            graph->addEdge(i, 2 * i, 1);
        }
        graph->addEdge(i, i + 1, 1);
        graph->addEdge(i, i - 1, 1);
    }
    graph->addEdge(100000, 99999, 1);

    pair<int, int> ans = BFS(graph, N, K);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}