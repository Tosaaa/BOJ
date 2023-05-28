// 행렬 제곱의 합
// https://www.acmicpc.net/problem/13246

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

int N;

vvi matMult(vvi &A, vvi &B) {
    vvi C(N, vi(N, 0));
    REP(i, 0, N) {
        REP(j, 0, N) {
            REP(k, 0, N) {
                C[i][j] += (A[i][k] * B[k][j]) % 1000;
            }
            C[i][j] %= 1000;
        }
    }
    return C;
}

vvi matPlusI(vvi A) {
    REP(i, 0, N) {
        A[i][i]++;
        A[i][i] %= 1000;
    }
    return A;
}

vvi makeDP(vvi &A, ll B, vector<vvi> &dp) {
    if (B == 1) {
        REP(i, 0, N) {
            REP(j, 0, N) {
                A[i][j] %= 1000;
            }
        }
        dp.push_back(A);
        return A;
    }
    vvi a = makeDP(A, B / 2, dp);
    a = matMult(a, a);
    if (B % 2 == 1) {
        a = matMult(a, A);
    }
    dp.push_back(a);
    return a;
}

vvi solution(ll B, vector<vvi> &dp, int idx) {
    if (B == 1) {
        return dp[idx + 1];
    }

    vvi a = solution(B / 2, dp, idx - 1);
    vvi tmp = matPlusI(dp[idx]);
    a = matMult(a, tmp);

    if (B % 2 == 1) {
        REP(i, 0, N) {
            REP(j, 0, N) {
                a[i][j] += dp[idx + 1][i][j];
                a[i][j] %= 1000;
            }
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll B;
    cin >> N >> B;
    vvi mat(N, vi(N));
    vector<vvi> dp(0, vvi(N, vi(N)));
    REP(i, 0, N) {
        REP(j, 0, N) {
            cin >> mat[i][j];
        }
    }

    makeDP(mat, B, dp);

    // cout << endl;
    // REP(x, 0, dp.size()) {
    //     REP(i, 0, N) {
    //         REP(j, 0, N) {
    //             cout << dp[x][i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    vvi ans = solution(B, dp, dp.size() - 2);
    REP(i, 0, N) {
        REP(j, 0, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}