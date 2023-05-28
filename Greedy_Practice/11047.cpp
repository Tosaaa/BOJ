// 동전
// https://www.acmicpc.net/problem/11047

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    int val[10];
    REP(i, 0, N) {
        cin >> val[i];
    }

    int cnt = 0;
    int Q = 0;
    for (int i = N-1; i >= 0 && K != 0; i--) {
        Q = K / val[i];
        if (Q != 0) {
            K -= Q * val[i];
            cnt += Q;
        }
    }

    cout << cnt << endl;


    return 0;
}