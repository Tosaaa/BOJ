// 연구소
// https://www.acmicpc.net/problem/14502

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int N, M;

int BFS(vvi map, vector<pii> virus) {
    int ret = 0;
    REP(i, 0, virus.size()) {
        queue<pii> q;
        q.push({virus[i].first, virus[i].second});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            map[x][y] = 2;

            if (x > 0 && map[x - 1][y] == 0) {
                q.push({x - 1, y});
            }
            if (y > 0 && map[x][y - 1] == 0) {
                q.push({x, y - 1});
            }
            if (x < N - 1 && map[x + 1][y] == 0) {
                q.push({x + 1, y});
            }
            if (y < M - 1 && map[x][y + 1] == 0) {
                q.push({x, y + 1});
            }
        }
    }
    REP(i, 0, N) {
        REP(j, 0, M) {
            if (map[i][j] == 0)
                ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vvi map(N, vi(M));
    vector<pii> virus;
    vector<pii> zeros;
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({i, j});
            else if (map[i][j] == 0)
                zeros.push_back({i, j});
        }
    }

    int wall = 3;

    int ans = 0;
    REP(i, 0, zeros.size()) {
        REP(j, i, zeros.size()) {
            REP(k, j, zeros.size()) {
                if (i < j && j < k) {
                    map[zeros[i].first][zeros[i].second] = 1;
                    map[zeros[j].first][zeros[j].second] = 1;
                    map[zeros[k].first][zeros[k].second] = 1;
                    ans = max(ans, BFS(map, virus));
                    map[zeros[i].first][zeros[i].second] = 0;
                    map[zeros[j].first][zeros[j].second] = 0;
                    map[zeros[k].first][zeros[k].second] = 0;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}