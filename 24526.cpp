// 전화 돌리기
// https://www.acmicpc.net/problem/24526

// check for cycle (directed graph)
// 부모 노드가 여러개인 경우(cycle이 겹쳐있는 경우 어떻게 함??)

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
    bool cycle;
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
    cycle = false;
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

void isCycle_Util(Graph *graph, int s, vi &visited, vi &finished, vi &parent);

int isCycle(Graph *graph) {
    int V = graph->getNodeSize();
    vi visited(V, 0);
    vi finished(V, 0);
    vi parent(V, -1);
    REP(i, 0, V) {
        if (!visited[i]) {
            isCycle_Util(graph, i, visited, finished, parent);
        }
    }

    int ans = 0;
    REP(i, 0, V) {
        if (!graph->bucket[i]->cycle) {
            ans++;
        }
    }
    return ans;
}

void isCycle_Util(Graph *graph, int s, vi &visited, vi &finished, vi &parent) {
    visited[s] = 1;

    for (auto it = graph->bucket[s]->adj.begin(); it != graph->bucket[s]->adj.end(); it++) {
        if (!visited[(*it).first->idx]) {
            parent[(*it).first->idx] = s;
            isCycle_Util(graph, (*it).first->idx, visited, finished, parent);
        } else if (!finished[(*it).first->idx] || (*it).first->cycle) {  // back edge (cycle!)
            int tmp = s;
            while (tmp != -1 && graph->bucket[tmp]->cycle == false) {
                graph->bucket[tmp]->cycle = true;
                tmp = parent[tmp];
            }
        }
    }
    finished[s] = 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;


    Graph *graph = new Graph(N);
    int a, b;
    REP(i, 0, M) {
        cin >> a >> b;
        graph->addEdge(a - 1, b - 1, 1);
    }

    cout << isCycle(graph) << endl;

    return 0;
}