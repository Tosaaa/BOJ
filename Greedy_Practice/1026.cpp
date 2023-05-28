// 보물
// https://www.acmicpc.net/problem/1026

#include <algorithm>
#include <iostream>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, A[50], B[50];
    cin >> N;
    REP(i, 0, N) {
        cin >> A[i];
    }
    REP(i, 0, N) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, cmp);

    int ans = 0;

    REP(i, 0, N) {
        ans += A[i] * B[i];
    }

    cout << ans << endl;

    return 0;
}