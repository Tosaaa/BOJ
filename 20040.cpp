// 사이클 게임
// https://www.acmicpc.net/problem/20040

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF INT_MAX
#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

class UnionFind {
   public:
    vector<pii> root;  // root[i][0]은 root, root[i][1]은 height(rank)
    UnionFind(int n) {
        REP(i, 0, n) {
            root.push_back({i, 0});
        }
    }
    int find(int x) {
        if (root[x].first == x) return x;
        return (root[x].first = find(root[x].first));  // Path Compression
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // Union-by-Height
        if (root[x].second > root[y].second) {
            root[y].first = x;
        } else if (root[x].second < root[y].second) {
            root[x].first = y;
        } else {
            root[y].first = x;
            root[x].second++;
        }
    }
    bool isSame(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    UnionFind *uf = new UnionFind(n);
    vector<pii> input(m);
    REP(i, 0, m) {
        cin >> input[i].first >> input[i].second;
    }
    int ans = 0;
    REP(i, 0, m) {
        int x = input[i].first;
        int y = input[i].second;
        if (uf->isSame(x, y)) {
            ans = i + 1;
            break;
        } else {
            uf->unite(x, y);
        }
    }

    cout << ans << endl;

    return 0;
}