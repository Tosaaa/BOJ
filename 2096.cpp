// 내려가기
// https://www.acmicpc.net/problem/2096

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int M1_bef = 0, M2_bef = 0, M3_bef = 0, m1_bef = 0, m2_bef = 0, m3_bef = 0;
    int M1, M2, M3, m1, m2, m3;
    int p1, p2, p3;
    REP(i, 0, N) {
        cin >> p1 >> p2 >> p3;
        M1 = max(M1_bef, M2_bef) + p1;
        M2 = max(max(M1_bef, M2_bef), M3_bef) + p2;
        M3 = max(M2_bef, M3_bef) + p3;

        m1 = min(m1_bef, m2_bef) + p1;
        m2 = min(min(m1_bef, m2_bef), m3_bef) + p2;
        m3 = min(m2_bef, m3_bef) + p3;

        M1_bef = M1;
        M2_bef = M2;
        M3_bef = M3;

        m1_bef = m1;
        m2_bef = m2;
        m3_bef = m3;
    }
    cout << max(max(M1, M2), M3) << " " << min(min(m1, m2), m3) << endl;

    return 0;
}