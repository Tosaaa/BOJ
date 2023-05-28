// 행렬 제곱
// https://www.acmicpc.net/problem/10830

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

vvi solution(vvi &A, ll B) {
    if (B == 1) {
        REP(i, 0, N) {
            REP(j, 0, N) {
                A[i][j] %= 1000;
            }
        }
        return A;
    }
    vvi a = solution(A, B / 2);
    a = matMult(a, a);
    if (B % 2 == 1) {
        a = matMult(a, A);
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

    REP(i, 0, N) {
        REP(j, 0, N) {
            cin >> mat[i][j];
        }
    }

    vvi ans = solution(mat, B);
    REP(i, 0, N) {
        REP(j, 0, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}