// 벡터 매칭
// https://www.acmicpc.net/problem/1007

#include <algorithm>
#include <iostream>
#include <vector>
#include <float.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

double solve(vector<pair<ll, ll>> &points, int N, int depth, vi &selected, int s) {
    if (depth >= N / 2) {
        pair<ll, ll> sum1 = {0, 0};
        pair<ll, ll> sum2 = {0, 0};
        REP(i, 0, N) {
            if (selected[i]) {
                //out << "selected: " << i << endl;
                sum1.first += points[i].first;
                sum1.second += points[i].second;
            } else {
                //cout << "not selected: " << i << endl;
                sum2.first += points[i].first;
                sum2.second += points[i].second;
            }
        }
        //cout << sum1.first << " " << sum1.second << endl;
        //cout << sum2.first << " " << sum2.second << endl;
        //cout << endl;
        double distance = sqrt((sum1.first - sum2.first) * (sum1.first - sum2.first) + (sum1.second - sum2.second) * (sum1.second - sum2.second));

        return distance;
    }
    double minDist = DBL_MAX;
    REP(i, s, N) {
        if (!selected[i]) {
            selected[i] = 1;
            minDist = min(minDist, solve(points, N, depth + 1, selected, i + 1));
            selected[i] = 0;
        }
    }
    return minDist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(12);

    int T;
    cin >> T;
    REP(tc, 0, T) {
        int N;
        cin >> N;
        vector<pair<ll, ll>> points(N);
        REP(i, 0, N) {
            cin >> points[i].first >> points[i].second;
        }
        vi selected(N, 0);
        cout << solve(points, N, 0, selected, 0) << endl;
    }

    return 0;
}