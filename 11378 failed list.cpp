// 열혈 강호 4
// https://www.acmicpc.net/problem/11378

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
    for (auto it = bucket[v]->adj.begin(); it != bucket[v]->adj.end(); it++) {
        if ((*it).first->idx == w) {
            (*it).second += weight;
            return;
        }
    }
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
            // cout << "Max Flow Found!: " << maxflow << endl;
            break;
        } else {
            int len = 0;
            REP(i, 0, graph->getNodeSize()) {
                if (path[i] == -1) break;
                //cout << path[i] << " ";
                len++;
            }
            //cout << endl;

            GraphNode *node;
            int min = INF;
            REP(i, 0, len) {
                node = graph->bucket[path[i]];
                for (auto it = node->adj.begin(); it != node->adj.end(); it++) {
                    if ((*it).first->idx == path[i + 1] && (*it).second < min) {
                        min = (*it).second;
                    }
                }
            }
            maxflow += min;
            // cout << "incremented flow: " << min << ", current flow: " << maxflow << endl;
            // graph->print();

            REP(i, 0, len) {
                node = graph->bucket[path[i]];
                for (auto it = node->adj.begin(); it != node->adj.end(); it++) {
                    if ((*it).first->idx == path[i + 1]) {
                        (*it).second -= min;
                    }
                }
            }

            // graph->print();

            for (int i = len - 1; i > 0; i--) {
                bool isEdge = false;
                node = graph->bucket[path[i]];
                for (auto it = node->adj.begin(); it != node->adj.end(); it++) {
                    if ((*it).first->idx == path[i - 1]) {
                        (*it).second += min;
                        isEdge = true;
                    }
                }
                if (!isEdge) graph->addEdge(path[i], path[i - 1], min);
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

        list<pair<GraphNode *, int>> adj = graph->bucket[v]->adj;
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (!visited[(*it).first->idx] && (*it).second > 0) {
                q.push((*it).first->idx);
                visited[(*it).first->idx] = 1;
                p[(*it).first->idx] = v;
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

bool cmp(queue<int> a, queue<int> b) {
    if (a.size() == b.size()) {
        return a.front() < b.front();
    }
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

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
    //graph->print();
    int ans = maxFlow(graph, 0, N + M + 1);
    //graph->print();
    vector<queue<int>> vq(M);
    REP(i, 1, N + 1) {
        for (auto it = graph->bucket[i]->adj.begin(); it != graph->bucket[i]->adj.end(); it++) {
            if ((*it).second == 1 && (*it).first->idx != 0) {
                vq[(*it).first->idx - N - 1].push(i);
            }
        }
    }

    sort(vq.begin(), vq.end(), cmp);

    REP(i, 0, M) {
        while (K > 0 && !vq[i].empty()) {
            graph->addEdge(0, vq[i].front(), 1);
            vq[i].pop();
            K--;
        }
        if (K == 0) break;
    }
    ans += maxFlow(graph, 0, N + M + 1);
    // graph->print();
    cout << ans << endl;

    return 0;
}