// 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(tc, 0, T) {
        int k;
        cin >> k;
        priority_queue<pii> maxPQ;
        priority_queue<pii, vector<pii>, greater<pii>> minPQ;
        vi valid(k + 1, 0);

        REP(i, 0, k) {
            char c;
            int val;
            cin >> c >> val;
            if (c == 'I') {
                maxPQ.push({val, i});
                minPQ.push({val, i});
                valid[i] = 1;
            } else if (val == 1) {
                while (!maxPQ.empty() && !valid[maxPQ.top().second]) {
                    maxPQ.pop();
                }
                if (!maxPQ.empty()) {
                    valid[maxPQ.top().second] = 0;
                    maxPQ.pop();
                }

            } else if (val == -1) {
                while (!minPQ.empty() && !valid[minPQ.top().second]) {
                    minPQ.pop();
                }
                if (!minPQ.empty()) {
                    valid[minPQ.top().second] = 0;
                    minPQ.pop();
                }
            }
        }
        while (!maxPQ.empty() && !valid[maxPQ.top().second]) {
            maxPQ.pop();
        }
        while (!minPQ.empty() && !valid[minPQ.top().second]) {
            minPQ.pop();
        }
        if (maxPQ.empty() && minPQ.empty()) {
            cout << "EMPTY" << endl;

        } else {
            cout << maxPQ.top().first << " " << minPQ.top().first << endl;
        }
    }

    return 0;
}