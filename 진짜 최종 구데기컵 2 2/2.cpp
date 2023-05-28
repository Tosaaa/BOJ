// 2
// https://www.acmicpc.net/problem/

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

    int N;
    cin >> N;
    REP(i, 0, N + 1) {
        switch (i) {
            case 0:
                cout << "0";
                break;
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "10";
                break;
            case 3:
                cout << "11";
                break;
            case 4:
                cout << "100";
                break;
            case 5:
                cout << "101";
                break;
            case 6:
                cout << "110";
                break;
            case 7:
                cout << "111";
                break;
            case 8:
                cout << "1000";
                break;
            case 9:
                cout << "1001";
                break;
            case 10:
                cout << "1010";
                break;
        }
    }
    cout << endl;

    return 0;
}