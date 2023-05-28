// 웜홀
// https://www.acmicpc.net/problem/1865

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

#define INF INT_MAX
#define REP(i, a, b) for (int i = a; i < b; i++)
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

bool shortest_distance(Graph *graph, int s, vector<int> &visited) {
    int V = graph->getNodeSize();
    int E = graph->getEdgeSize(true);
    vector<int> d(V, INF);  // storing distances
    d[s] = 0;
    vector<tuple<int, int, int>> edges;
    for (auto it1 = graph->bucket.begin(); it1 != graph->bucket.end(); it1++) {
        for (auto it2 = (*it1)->adj.begin(); it2 != (*it1)->adj.end(); it2++) {
            edges.push_back({(*it1)->idx, (*it2).first->idx, (*it2).second});
        }
    }

    REP(i, 0, V - 1) {  // repeat v-1 times
        REP(j, 0, E) {
            int a, b, w;
            tie(a, b, w) = edges[j];
            if (d[a] < INF && d[b] > d[a] + w) {
                d[b] = d[a] + w;
            }
        }
    }

    int valid = 1;
    REP(j, 0, E) {
        int a, b, w;
        tie(a, b, w) = edges[j];
        if (d[a] < INF && d[b] > d[a] + w) {
            valid = 0;
            break;
        }
    }
    REP(i, 0, V) {
        if (d[i] != INF) {
            visited[i] = 1;
        }
    }
    if (!valid) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin >> TC;
    REP(t, 0, TC) {
        int N, M, W;
        cin >> N >> M >> W;
        Graph *graph = new Graph(N);
        int a, b, c;
        REP(i, 0, M) {
            cin >> a >> b >> c;
            graph->addEdge(a - 1, b - 1, c);
            graph->addEdge(b - 1, a - 1, c);
        }
        REP(i, 0, W) {
            cin >> a >> b >> c;
            graph->addEdge(a - 1, b - 1, -c);
        }
        bool valid = 0;
        vector<int> visited(N, 0);
        REP(i, 0, N) {
            if (!visited[i]) {
                if (shortest_distance(graph, i, visited)) {
                    valid = 1;
                    break;
                }
            }
        }
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        delete graph;
    }

    return 0;
}