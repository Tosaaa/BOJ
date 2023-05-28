// ACM Craft
// https://www.acmicpc.net/problem/1005

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
    int time;
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
    time = 0;
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

int dijkstra(Graph *graph, int s) {
    int V = graph->getNodeSize();
    vector<int> visited(V, 0);
    vector<int> d(V, INF);  // storing distances.
    d[s] = graph->bucket[s]->time;
    priority_queue<pair<int, int>> q;
    q.push({-d[s], s});

    while (!q.empty()) {
        // extract max
        int max = q.top().second;
        q.pop();
        if (d[max] > q.top().first) continue; // 이렇게만 하면 TLE됨
        // if (visited[max]) continue;
        // visited[max] = 1;
        // update distance
        list<pair<GraphNode *, int>> adj = graph->bucket[max]->adj;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (d[max] + (*it).first->time < d[(*it).first->idx]) {
                d[(*it).first->idx] = d[max] + (*it).first->time;
                q.push({-d[(*it).first->idx], (*it).first->idx});
                // cout << "pushed: " << -d[(*it).first->idx] << " " << (*it).first->idx << endl;
            }
        }
    }
    int min = 0;
    REP(i, 0, V) {
        if (min > d[i])
            min = d[i];
    }
    return -min;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    REP(tc, 0, T) {
        int N, K;
        cin >> N >> K;

        Graph *graph = new Graph(N);
        REP(i, 0, N) {
            int a;
            cin >> a;
            graph->bucket[i]->time = -a;
        }

        int a, b;
        REP(i, 0, K) {
            cin >> a >> b;
            graph->addEdge(b - 1, a - 1, 1);
        }
        int W;
        cin >> W;
        // cout << dijkstra(graph, 0, W - 1) << endl;

        int ans = dijkstra(graph, W-1);

        cout << ans << endl;
    }

    return 0;
}