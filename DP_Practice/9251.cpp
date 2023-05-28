// LCS
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <queue>
#include <string>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

string s1, s2;
int LCS[1001][1001];

int getLCS(int idx1, int idx2) {
    //cout << idx1 << " " << idx2 << endl;
    if (!idx1 || !idx2) {
        //cout << 1 << endl;
        LCS[idx1][idx2] = 0;
    } else if (LCS[idx1][idx2] != -1) {
        //cout << 2 << endl;
    } else if (s1[idx1 - 1] == s2[idx2 - 1]) {
        //cout << 3 << endl;
        LCS[idx1][idx2] = getLCS(idx1 - 1, idx2 - 1) + 1;
    } else {
        //cout << 4 << endl;
        LCS[idx1][idx2] = max(getLCS(idx1 - 1, idx2), getLCS(idx1, idx2 - 1));
    }
    return LCS[idx1][idx2];
}

int main() {
    // LCS(s1(x), s2(y))
    // = 0 (if x == 0 or y == 0)
    // = LCS(s1(x-1) + s2(y-1)) + 1 (if w1(x) = w2(y))
    // = max(LCS(s1(x-1), s2(y)), LCS(s1(x), s2(y-1)))

    cin >> s1 >> s2;

    REP(i, 0, max(s1.size(), s2.size()) + 1) {
        REP(j, 0, max(s1.size(), s2.size()) + 1) {
            LCS[i][j] = -1;
        }
    }
    cout << getLCS(s1.size(), s2.size()) << endl;

    return 0;
}