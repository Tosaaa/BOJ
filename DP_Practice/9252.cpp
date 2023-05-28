// LCS 2
// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <queue>
#include <string>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

string s1, s2;
int LCS[1001][1001];
string str[1001][1001];

int getLCS(int idx1, int idx2, string &s) {
    //cout << "start: " << s1.substr(0, idx1) << " " << s2.substr(0, idx2) << endl;
    if (!idx1 || !idx2) {
        //cout << 1 << endl;
        LCS[idx1][idx2] = 0;
    } else if (LCS[idx1][idx2] != -1) {
        //cout << 2 << endl;
        s = str[idx1][idx2];
    } else if (s1[idx1 - 1] == s2[idx2 - 1]) {
        //cout << 3 << endl;
        LCS[idx1][idx2] = getLCS(idx1 - 1, idx2 - 1, s) + 1;
        s += s1[idx1 - 1];
        str[idx1][idx2] = s;
        //cout << "current s: " << s << endl;
    } else {
        //cout << 4 << endl;
        string s1 = s;
        string s2 = s;
        LCS[idx1][idx2] = max(getLCS(idx1 - 1, idx2, s1), getLCS(idx1, idx2 - 1, s2));
        //cout << "s1: " << s1 << " s2: " << s2 << endl;
        if (s2.size() >= s1.size()) {
            s = s2.append(s);
            //cout << "s2 chosen" << endl;
        } else {
            s = s1.append(s);
            //cout << "s1 chosen" << endl;
        }
        str[idx1][idx2] = s;
        //cout << "current2 s: " << s << endl;
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

    string s = "";
    cout << getLCS(s1.size(), s2.size(), s) << endl;
    cout << s << endl;

    return 0;
}