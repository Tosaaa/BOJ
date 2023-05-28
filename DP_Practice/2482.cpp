// 색상환
// https://www.acmicpc.net/problem/2482

#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'
#define DIV 1000000003

using namespace std;
int S[1001][1001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    REP(i, 1, N + 1) {
        S[i][1] = i;
        S[i][0] = 1;
    }

    REP(n, 3, N + 1) {
        REP(k, 2, (n + 1) / 2 + 1) {
            S[n][k] = (S[n - 2][k - 1] % DIV + S[n - 1][k] % DIV) % DIV;
            // cout << n << " " << k << ": " << S[n][k] << endl;
        }
    }
    
    int ans;
    if (N > 2) {
        ans = (S[N - 3][K - 1] + S[N - 1][K]) % DIV;
        //cout << S[N][K] << endl;
    } else if (N == 1) {
        ans = 1;
    } else if (N == 2) {
        ans = S[N][K];
    }

    cout << ans << endl;

    return 0;
}