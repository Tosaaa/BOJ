// 수 찾기
// https://www.acmicpc.net/problem/1920

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

    int N, M;
    cin >> N;
    set<int> s;
    REP(i, 0, N) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cin >> M;
    REP(i, 0, M) {
        int a;
        cin >> a;
        cout << (s.insert(a).second ? 0 : 1) << endl;
    }

    return 0;
}