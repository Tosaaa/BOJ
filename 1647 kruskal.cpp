// 도시 분할 계획
// https://www.acmicpc.net/problem/1647

#include <bits/stdc++.h>

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

class UnionFind {
   public:
    vector<pii> root;  // root[i][0]은 root, root[i][1]은 height(rank)
    UnionFind(int n) {
        REP(i, 0, n) {
            root.push_back({i, 0});
        }
    }
    int find(int x) {
        if (root[x].first == x) return x;
        return (root[x].first = find(root[x].first));  // Path Compression
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // Union-by-Height
        if (root[x].second > root[y].second) {
            root[y].first = x;
        } else if (root[x].second < root[y].second) {
            root[x].first = y;
        } else {
            root[y].first = x;
            root[x].second++;
        }
    }
    bool isSame(int x, int y) {
        return find(x) == find(y);
    }
};

Graph *kruskal(Graph *graph) {
    int V = graph->getNodeSize();
    int E = (graph->E) / 2;
    vector<tuple<int, int, int>> edges;
    REP(i, 0, V) {
        for (auto it = graph->bucket[i]->adj.begin(); it != graph->bucket[i]->adj.end(); it++) {
            int next = (*it).first->idx;
            if (i < next) {
                edges.push_back({(*it).second, i, next});
            }
        }
    }
    sort(edges.begin(), edges.end());

    Graph *ret = new Graph(V);
    UnionFind *uf = new UnionFind(V);
    REP(i, 0, E) {
        int w, u, v;
        tie(w, u, v) = edges[i];
        if (!uf->isSame(u, v)) {
            uf->unite(u, v);
            ret->addEdge(u, v, w);
            ret->addEdge(v, u, w);
        }
    }

    delete uf;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    Graph *graph = new Graph(N);
    REP(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        graph->addEdge(a-1, b-1, c);
        graph->addEdge(b-1, a-1, c);
    }

    Graph *mst = kruskal(graph);

    priority_queue<int> edges;
    REP(i, 0, N) {
        for (auto it = mst->bucket[i]->adj.begin(); it != mst->bucket[i]->adj.end(); it++) {
            int next = (*it).first->idx;
            if (i < next) {
                edges.push((*it).second);
            }
        }
    }
    edges.pop();
    int ans = 0;
    while (!edges.empty()) {
        ans += edges.top();
        edges.pop();
    }
    cout << ans << endl;

    return 0;
}