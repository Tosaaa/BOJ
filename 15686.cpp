// 치킨 배달
// https://www.acmicpc.net/problem/15686

#include <algorithm>
#include <climits>
#include <cstdlib>
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

int N, M;
vector<pii> chicken;
vector<pii> house;
vvi map;

int find(vi visited) {
    // cout << endl;
    // REP(i, 0, N) {
    //     REP(j, 0, N) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    REP(i, 0, house.size()) {
        int dist = INF;
        REP(j, 0, chicken.size()) {
            if (!visited[j]) {
                if (dist > abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second)) {
                    dist = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
                }
            }
        }
        ans += dist;
    }

    return ans;
}

int temp = 0;

int recursive(vi visited, int cnt, int s) {
    temp++;
    if (cnt == chicken.size() - M) {
        REP(i, 0, chicken.size()) {
            if (visited[i] == 1) {
                map[chicken[i].first][chicken[i].second] = 0;
            }
        }
        int result = find(visited);
        REP(i, 0, chicken.size()) {
            if (visited[i] == 1) {
                map[chicken[i].first][chicken[i].second] = 2;
            }
        }
        //cout << result << endl;
        return result;
    }
    int ret = INF;
    REP(i, s, chicken.size()) {
        visited[i] = 1;
        ret = min(ret, recursive(visited, cnt + 1, i + 1));
        visited[i] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    map.resize(N);
    REP(i, 0, N) {
        map[i].resize(N);
        REP(j, 0, N) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                chicken.push_back({i, j});
            else if (map[i][j] == 1)
                house.push_back({i, j});
        }
    }

    vi visited(chicken.size(), 0);
    cout << recursive(visited, 0, 0) << endl;
    //cout << temp << endl;

    return 0;
}