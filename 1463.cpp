// 1로 만들기
// https://www.acmicpc.net/problem/1463

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

    int N;
    cin >> N;
    vi S(N + 1, -1);
    S[1] = 0;
    REP(i, 1, N + 1) {
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX;
        if (i % 2 == 0) {
            s1 = S[i / 2] + 1;
        }
        if (i % 3 == 0) {
            s2 = S[i / 3] + 1;
        }
        s3 = S[i - 1] + 1;
        S[i] = min(min(s1, s2), s3);
    }

    cout << S[N] << endl;

    return 0;
}