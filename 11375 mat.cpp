// 열혈 강호
// https://www.acmicpc.net/problem/11375

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <utility>

#define INF INT_MAX
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

class Graph {
   public:
    int V;
    int E;  // # of directed edges
    vector<vector<int>> adj;

    // constructor
    Graph(int _V);

    // Graph() : V(0), E(0) { nodes.clear(); }
    // Graph(int _nc, bool _d = false) : V(_nc), E(0){};
    //  copy constructor
    //  move constructor
    //  destructor

    void addNode();
    void addEdge(int v, int w, int weight);  // v->w (directed)
    bool isEdge(int v, int w);               // returns 1 if there is an edge from v to w, otherwise 0.
    void print();
    int getNodeSize();
    int getEdgeSize(bool isDirected);
};

Graph::Graph(int _V) {
    V = _V;
    E = 0;
    adj.resize(V);
    for (int i = 0; i < V; i++) {
        adj[i].resize(V);
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int v, int w, int weight) {
    if (v >= V || w >= V || v < 0 || w < 0) return;
    if (weight == INF || weight == 0) return;
    E++;
    adj[v][w] += weight;
}

void Graph::print() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == INF)
                cout << "- ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::getNodeSize() {
    return V;
}

int maxFlow(Graph *graph, int s, int t);
bool findPath(Graph *graph, int s, int t, vector<int> &path);

int maxFlow(Graph *graph, int s, int t) {
    if (s == t)
        cout << "source is equal to sink" << endl;
    else if (t >= graph->V)
        cout << "sink too large" << endl;

    int maxflow = 0;

    while (1) {
        vector<int> path(graph->getNodeSize(), -1);

        if (!findPath(graph, s, t, path)) {
            // cout << "max flow found: " << maxflow << endl;
            break;
        } else {
            int len = 0;
            REP(i, 0, graph->getNodeSize()) {
                if (path[i] == -1) break;
                // cout << path[i] << " ";
                len++;
            }
            // cout << endl;

            int min = INF;
            REP(i, 0, len - 1) {
                if (min > graph->adj[path[i]][path[i + 1]]) {
                    min = graph->adj[path[i]][path[i + 1]];
                }
            }
            maxflow += min;
            // cout << "incremented flow: " << min << ", current flow: " << maxflow << endl;
            //  graph->print();

            REP(i, 0, len - 1) {
                graph->adj[path[i]][path[i + 1]] -= min;
            }

            // graph->print();

            for (int i = len - 1; i >= 1; i--) {
                graph->addEdge(path[i], path[i - 1], min);
            }

            // graph->print();
        }
    }
    return maxflow;
}

bool findPath(Graph *graph, int s, int t, vector<int> &path) {
    vector<int> visited(graph->getNodeSize());
    queue<int> q;
    vector<int> p(graph->getNodeSize(), -1);
    stack<int> path_stack;

    visited[s] = 1;
    q.push(s);
    bool valid = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == t) {
            valid = true;
            break;
        }

        REP(i, 0, graph->getNodeSize()) {
            if (i == v) continue;
            if (!visited[i] && graph->adj[v][i] > 0) {
                q.push(i);
                visited[i] = 1;
                p[i] = v;
            }
        }
    }

    if (valid) {
        int tmp = t;
        while (tmp != s) {
            path_stack.push(tmp);
            tmp = p[tmp];
        }
        path_stack.push(s);

        int idx = 0;
        while (!path_stack.empty()) {
            path[idx++] = path_stack.top();
            path_stack.pop();
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    Graph *graph = new Graph(N + M + 2);

    REP(i, 1, N + 1) {
        graph->addEdge(0, i, 1);
    }
    REP(i, N + 1, N + M + 1) {
        graph->addEdge(i, N + M + 1, 1);
    }

    int m, tmp;
    REP(i, 1, N + 1) {
        cin >> m;
        REP(j, 0, m) {
            cin >> tmp;
            graph->addEdge(i, tmp + N, 1);
        }
    }

    cout << maxFlow(graph, 0, N + M + 1) << endl;

    return 0;
}