// 색상환
// https://www.acmicpc.net/problem/2482

#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'
#define DIV 1000000003

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // S(x, k) = x/k * x-k-1Ck-1
    // S(x, k) = S(x, k-1) * (x-2k+2)(x-2k+1) / (k)(x-k)

    // 이렇게 하면 수가 너무 커져서 답 없음.
    // 나누기 때문에 중간중간에 mod DIV를 할 수가 없는 듯

    int N, K;
    cin >> N >> K;

    long long S[1001] = {0};
    S[1] = N;
    REP(k, 2, K + 1) {
        if (N < 2 * k) {
            S[k] = 0;
        } else {
            S[k] = S[k - 1] * (N - 2 * k + 2);
            S[k] *= (N - 2 * k + 1);
            S[k] /= (k * (N - k));
            if (S[k] > DIV) {
                S[k] %= DIV;
                //cout << k << ": DIV" << endl;           
            }
        }
    }

    cout << S[K] << endl;

    return 0;
}