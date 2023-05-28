// 최소비용 구하기
// https://www.acmicpc.net/problem/1916
// graph based on adjacency list

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

int dijkstra(Graph *graph, int s, int e) {
    int V = graph->getNodeSize();
    vector<int> visited(V);
    int visited_nodes = 0;
    vector<int> d(V, INF);  // storing distances.
    d[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});

    while (!q.empty()) {
        // extract min
        int min = q.top().second;
        q.pop();
        if (visited[min]) continue;
        // when the given graph is not connected graph: how ?

        visited[min] = 1;
        if (min == e) break;
        // update distance
        list<pair<GraphNode *, int>> adj = graph->bucket[min]->adj;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (d[min] + (*it).second < d[(*it).first->idx]) {
                d[(*it).first->idx] = d[min] + (*it).second;
                q.push({-d[(*it).first->idx], (*it).first->idx});
            }
        }
    }

    return d[e];
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
    
    int s, e;
    cin >> s >> e;
    int ans = dijkstra(graph, s-1, e-1);

    //graph->print();
    cout << ans << endl;
    return 0;
}