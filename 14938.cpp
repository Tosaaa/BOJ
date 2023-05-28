// 서강 그라운드
// https://www.acmicpc.net/problem/14938

#include <algorithm>
#include <climits>
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
    int val;
    list<pair<GraphNode *, int>> adj;
    GraphNode(int _idx, int _val);
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

GraphNode::GraphNode(int _idx, int _val) {
    idx = _idx;
    val = _val;
    adj.clear();
}

// constructor
Graph::Graph(int _V) {
    V = _V;
    E = 0;
    bucket.clear();
    for (int i = 0; i < V; i++)
        bucket.push_back(new GraphNode(i, 0));
}

Graph::~Graph() {
    for (int i = 0; i < V; i++)
        delete bucket[i];
}

void Graph::addNode() {
    bucket.push_back(new GraphNode(V++, 0));
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

int n, m, r;

int dijkstra(Graph *graph) {
    int ans = 0;
    REP(s, 0, n) {
        int V = graph->getNodeSize();
        vector<int> visited(V);
        vector<int> d(V, INF);  // storing distances.
        d[s] = 0;
        priority_queue<pair<int, int>> q;
        q.push({0, s});
        while (!q.empty()) {
            // extract min
            int min = q.top().second;
            q.pop();
            if (visited[min]) continue;
            visited[min] = 1;

            // update distance
            list<pair<GraphNode *, int>> adj = graph->bucket[min]->adj;
            for (auto it = adj.begin(); it != adj.end(); it++) {
                if (d[min] + (*it).second < d[(*it).first->idx]) {
                    d[(*it).first->idx] = d[min] + (*it).second;
                    q.push({-d[(*it).first->idx], (*it).first->idx});
                }
            }
        }

        int farm = 0;
        REP(i, 0, V) {
            if (m >= d[i]) {
                farm += graph->bucket[i]->val;
            }
        }
        ans = max(ans, farm);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;

    Graph *graph = new Graph(n);
    REP(i, 0, n) {
        cin >> graph->bucket[i]->val;
    }
    REP(i, 0, r) {
        int a, b, c;
        cin >> a >> b >> c;
        graph->addEdge(a - 1, b - 1, c);
        graph->addEdge(b - 1, a - 1, c);
    }

    cout << dijkstra(graph) << endl;

    return 0;
}