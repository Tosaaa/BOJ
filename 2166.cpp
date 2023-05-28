// 다각형의 면적
// https://www.acmicpc.net/problem/2166

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);

    int N;
    cin >> N;

    int minx = 0, miny = 0;
    vector<pii> vertices(N);
    REP(i, 0, N) {
        int x, y;
        cin >> x >> y;
        vertices[i].first = x;
        vertices[i].second = y;
        if (minx > x) {
            minx = x;
        }
        if (miny > y) {
            miny = y;
        }
    }

    vertices.push_back({vertices[0].first, vertices[0].second});

    REP(i, 0, N + 1) {
        vertices[i].first -= minx;
        vertices[i].second -= miny;
    }

    double S = 0;
    REP(i, 0, N) {
        ll x1 = vertices[i].first;
        ll y1 = vertices[i].second;
        ll x2 = vertices[i + 1].first;
        ll y2 = vertices[i + 1].second;
        S += (y2 - y1) * (x1 + x2) * 0.5;
    }
    if (S < 0) S *= -1;

    cout << S << endl;
    return 0;
}