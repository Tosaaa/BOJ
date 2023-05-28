// RGB거리 2
// https://www.acmicpc.net/problem/17404

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
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

    int m;
    if (N == 2) {
        SG[1] = SR[0] + G[1];
        SB[1] = SR[0] + B[1];
        m = min(SG[1], SB[1]);
        SR[1] = SG[0] + R[1];
        SB[1] = SG[0] + B[1];
        m = min(m, min(SR[1], SB[1]));
        SR[1] = SB[0] + R[1];
        SG[1] = SB[0] + G[1];
        m = min(m, min(SR[1], SG[1]));
        cout << m << endl;
        return 0;
    }

    // when R is start
    REP(i, 1, N) {
        if (i == 1) {
            SG[i] = SR[0] + G[1];
            SB[i] = SR[0] + B[1];
        } else if (i == 2) {
            SR[i] = min(SG[i - 1], SB[i - 1]) + R[i];
            SG[i] = SB[i - 1] + G[i];
            SB[i] = SG[i - 1] + B[i];
        } else {
            SR[i] = min(SG[i - 1], SB[i - 1]) + R[i];
            SG[i] = min(SR[i - 1], SB[i - 1]) + G[i];
            SB[i] = min(SR[i - 1], SG[i - 1]) + B[i];
        }
    }
    m = min(SG[N-1], SB[N-1]);
    REP(i, 1, N) {
        if (i == 1) {
            SR[i] = SG[0] + R[1];
            SB[i] = SG[0] + B[1];
        } else if (i == 2) {
            SR[i] = SB[i - 1] + R[i];
            SG[i] = min(SR[i - 1], SB[i - 1]) + G[i];
            SB[i] = SR[i - 1] + B[i];
        } else {
            SR[i] = min(SG[i - 1], SB[i - 1]) + R[i];
            SG[i] = min(SR[i - 1], SB[i - 1]) + G[i];
            SB[i] = min(SR[i - 1], SG[i - 1]) + B[i];
        }
    }
    m = min(m, min(SR[N-1], SB[N-1]));
    REP(i, 1, N) {
        if (i == 1) {
            SR[i] = SB[0] + R[1];
            SG[i] = SB[0] + G[1];
        } else if (i == 2) {
            SR[i] = SG[i - 1] + R[i];
            SG[i] = SR[i - 1] + G[i];
            SB[i] = min(SR[i - 1], SG[i - 1]) + B[i];
        } else {
            SR[i] = min(SG[i - 1], SB[i - 1]) + R[i];
            SG[i] = min(SR[i - 1], SB[i - 1]) + G[i];
            SB[i] = min(SR[i - 1], SG[i - 1]) + B[i];
        }
    }
    m = min(m, min(SR[N-1], SG[N-1]));

    cout << m << endl;
    return 0;
}