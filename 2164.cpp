// 카드 2
// https://www.acmicpc.net/problem/2164

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
    deque<int> dq;

    int N;
    cin >> N;
    REP(i, 1, N+1) {
        dq.push_back(i);
    }
    while (dq.size() != 1) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }

    cout << dq.front() << endl;

    return 0;
}