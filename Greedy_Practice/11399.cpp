// ATM
// https://www.acmicpc.net/problem/11399

#include <algorithm>
#include <iostream>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int P[1000];
    REP(i, 0, N) {
        cin >> P[i];
    }

    sort(P, P + N);

    int ans = 0;
    REP(i, 0, N) {
        ans += P[i] * (N - i);
    }

    cout << ans << endl;
    
    return 0;
}