// 외판원 순회
// https://www.acmicpc.net/problem/2098

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'
#define INF 10000000

int DFS(vvi &DP, vvi &cost, int visited, int depth, int cur, int N) {
    if (DP[visited][cur] != -1) {
        return DP[visited][cur];
    }

    if (depth == N-1) {
        if (cost[cur][0] == 0) 
            return INF;
        else
            return cost[cur][0];
    }
    
    DP[visited][cur] = INF;
    for (int i = 0; i < N; i++) {
        int v = (visited >> i) & 1;
        if (!v && cost[cur][i] != 0) {
            DP[visited][cur] = min(DP[visited][cur], cost[cur][i] + DFS(DP, cost, visited | (1 << i), depth + 1, i, N));
        }
    }
    return DP[visited][cur];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vvi cost(N, vi(N));
    REP(i, 0, N) {
        REP(j, 0, N) {
            cin >> cost[i][j];
        }
    }

    vvi DP(1 << N, vi(N, -1));
    cout << DFS(DP, cost, 1, 0, 0, N) << endl;

    return 0;
}