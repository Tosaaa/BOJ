// RGB거리
// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    vector<int> R(N);
    vector<int> G(N);
    vector<int> B(N);
    REP(i, 0, N) {
        cin >> R[i] >> G[i] >> B[i];
    }

    vector<int> SR(N);
    vector<int> SG(N);
    vector<int> SB(N);
    SR[0] = R[0];
    SG[0] = G[0];
    SB[0] = B[0];
    REP(i, 1, N) {
        SR[i] = min(SG[i-1], SB[i-1]) + R[i];
        SG[i] = min(SR[i-1], SB[i-1]) + G[i];
        SB[i] = min(SR[i-1], SG[i-1]) + B[i];
    }
    
    int ans = min(SR[N-1], SG[N-1]);
    ans = min(ans, SB[N-1]);

    cout << ans << endl;
    return 0;
}