// 임계경로
// https://www.acmicpc.net/problem/1948
// Topological sort?
// 이러면 메모리 초과남 (구현은 맞긴 한듯)
// 도착 지점에서 거꾸로 역추적?

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

pii topological_sort(Graph *graph, int s, int e) {
    int V = graph->getNodeSize();
    vi indegree(V, 0);
    REP(i, 0, V) {
        for (auto it = graph->bucket[i]->adj.begin(); it != graph->bucket[i]->adj.end(); it++) {
            indegree[(*it).first->idx]++;
        }
    }

    queue<int> q;
    vi maxTime(V, 0);
    vvi parents(V);
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto it = graph->bucket[v]->adj.begin(); it != graph->bucket[v]->adj.end(); it++) {
            int next = (*it).first->idx;
            int time = (*it).second;

            if (maxTime[next] < maxTime[v] + time) { // 새로 찾은 경로가 더 느릴 때
                maxTime[next] = maxTime[v] + time;
                vi tmp;
                tmp.push_back(v);
                parents[next] = tmp;
            } else if (maxTime[next] == maxTime[v] + time) {
                parents[next].push_back(v);
            }

            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    q.push(e);
    vi visited(V, 0);
    int cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) continue; // 보험
        visited[v] = 1;
        
        vi p = parents[v];
        REP(i, 0, p.size()) {
            if (!visited[p[i]]) {
                q.push(p[i]);
                cnt++;
            }
        }
    }

    

    return {maxTime[e], cnt};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    Graph *graph = new Graph(n);
    REP(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        graph->addEdge(a - 1, b - 1, c);
    }
    int s, e;
    cin >> s >> e;
    pii ans = topological_sort(graph, s - 1, e - 1);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}