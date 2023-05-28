// ACM Craft
// https://www.acmicpc.net/problem/1005
// based on topological sort

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

int topological_sort(Graph *graph, int e) {
    int V = graph->getNodeSize();
    vi indegree(V, 0);
    REP(i, 0, V) {
        for (auto it = graph->bucket[i]->adj.begin(); it != graph->bucket[i]->adj.end(); it++) {
            indegree[(*it).first->idx]++;
        }
    }

    queue<pii> q;
    REP(i, 0, V) {
        if (!indegree[i]) q.push({i, graph->bucket[i]->time});
    }

    vi maxTime(V, 0);
    maxTime[0] = time[0];
    int ans;
    REP(i, 0, V) {
        if (q.empty()) {
            cout << "Topological Sort Impossible";
            return -1;
        }
        int v = q.front().first;
        int t = q.front().second;
        q.pop();

        if (v == e) {
            ans = t;
            break;
        }
        for (auto it = graph->bucket[v]->adj.begin(); it != graph->bucket[v]->adj.end(); it++) {
            int next = (*it).first->idx;
            indegree[next]--;
            if (maxTime[next] < t + graph->bucket[next]->time) {
                maxTime[next] = t + graph->bucket[next]->time;
            }
            if (indegree[(*it).first->idx] == 0) q.push({next, maxTime[next]});
        }
    }

    return ans;
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
            cin >> graph->bucket[i]->time;
        }

        int a, b;
        REP(i, 0, K) {
            cin >> a >> b;
            graph->addEdge(a - 1, b - 1, 1);
        }
        int W;
        cin >> W;

        int ans = topological_sort(graph, W - 1);

        cout << ans << endl;
    }

    return 0;
}