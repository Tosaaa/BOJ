// 절댓값 힙
// https://www.acmicpc.net/problem/11286

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

struct cmp {
    bool operator()(int a, int b) {
        if (a + b == 0) {
            return a > b;
        } else {
            return abs(a) > abs(b);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, cmp> pq;
    int N;
    cin >> N;
    REP(i, 0, N) {
        int a;
        cin >> a;
        if (a == 0) {
            if (pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else {
            pq.push(a);
        }
    }

    return 0;
}