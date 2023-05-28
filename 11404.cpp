// 플로이드
// https://www.acmicpc.net/problem/11404

#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>

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
    // vector<GraphNode *> getBucket(); private에 있을 때 어떻게 접근하게 만들어야 되지?
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
    if (weight == INF || weight == 0) return;
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

void shortest_distance(Graph *graph, vector<vector<int>> &dst) {
    int V = graph->getNodeSize();
    for (auto it1 = graph->bucket.begin(); it1 != graph->bucket.end(); it1++) {
        for (auto it2 = (*it1)->adj.begin(); it2 != (*it1)->adj.end(); it2++) {
            if (dst[(*it1)->idx][(*it2).first->idx] == 0 || dst[(*it1)->idx][(*it2).first->idx] > (*it2).second)
                dst[(*it1)->idx][(*it2).first->idx] = (*it2).second;
        }
    }

    REP(i, 0, V) {
        REP(j, 0, V) {
            if (dst[i][j] == 0 && i != j)
                dst[i][j] = INF;
        }
    }

    int valid = 1;
    for (int k = 0; k < V && valid == 1; k++) {
        for (int i = 0; i < V && valid == 1; i++) {
            for (int j = 0; j < V && valid == 1; j++) {
                if (dst[i][k] < INF && dst[k][j] < INF && dst[i][j] > dst[i][k] + dst[k][j])
                    dst[i][j] = dst[i][k] + dst[k][j];
                if (i == j && dst[i][j] < 0) valid = 0;
            }
        }
    }

    if (!valid)
        cout << "Floyd-Warshall impossible: negative cycle detected." << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    Graph *graph = new Graph(N);
    int a, b, c;
    REP(i, 0, M) {
        cin >> a >> b >> c;
        graph->addEdge(a - 1, b - 1, c);
    }

    vector<vector<int>> ans(N, vector<int>(N, 0));
    shortest_distance(graph, ans);

    REP(i, 0, N) {
        REP(j, 0, N) {
            if (ans[i][j] == INF)
                cout << "0 ";
            else
                cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    delete graph;

    return 0;
}