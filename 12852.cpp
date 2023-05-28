// 1로 만들기 2
// https://www.acmicpc.net/problem/12852

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

void buildGraph(Graph *graph, int N, vi &visited) {
    if (visited[N]) return;
    visited[N] = 1;
    if (N == 1) return;
    if (N % 3 == 0) {
        graph->addEdge(N, N / 3, 1);
        buildGraph(graph, N / 3, visited);
    }
    if (N % 2 == 0) {
        graph->addEdge(N, N / 2, 1);
        buildGraph(graph, N / 2, visited);
    }
    graph->addEdge(N, N - 1, 1);
    buildGraph(graph, N - 1, visited);
}

vi BFS(Graph *graph, int s) {
    vi visited(graph->getNodeSize());
    queue<pii> q; // current node, parent node
    q.push({s, -1});
    vi p(graph->getNodeSize(), -1);
    vi ans;

    while (!q.empty()) {
        int v = q.front().first;
        int prev = q.front().second;
        q.pop();
        //cout << v << endl;
        if (visited[v]) continue;
        visited[v] = 1;
        p[v] = prev;

        if (v == 1) {
            int tmp = v;
            while (tmp != -1) {
                ans.push_back(tmp);
                tmp = p[tmp];
            }
            reverse(ans.begin(), ans.end());
            break;
        }
        for (auto it = graph->bucket[v]->adj.begin(); it != graph->bucket[v]->adj.end(); it++) {
            int next = (*it).first->idx;
            if (!visited[next]) {
                q.push({next, v});
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    Graph *graph = new Graph(N + 1);

    vi visited(N + 1, 0);
    buildGraph(graph, N, visited);

    // graph->print();

    vi ans = BFS(graph, N);

    cout << ans.size() - 1 << endl;
    REP(i, 0, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}