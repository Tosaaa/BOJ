// 오븐 시계
// https://www.acmicpc.net/problem/2525

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int hh, mm, t;
    cin >> hh >> mm >> t;

    while (mm + t >= 60) {
        hh++;
        t -= 60;
    }
    mm += t;
    while (hh >= 24) {
        hh -= 24;
    }

    cout << hh << " " << mm << endl;    

    return 0;
}