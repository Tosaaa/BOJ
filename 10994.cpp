// 별 찍기 -19
// https://www.acmicpc.net/problem/10994

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

    int mid = (-3 + 4 * N) / 2;

    REP(i, 0, -3 + 4 * N) {
        if (i < mid) {
            if (i % 2) {
                REP(j, 0, (i+1)/2) {
                    cout << "* ";
                }
                REP(j, 0, -3 + 4*N - 2*(i+1)) {
                    cout << " ";
                }
                REP(j, 0, (i+1)/2) {
                    cout << " *";
                }
                cout << endl;
            } else {
                REP(j, 0, i / 2) {
                    cout << "* ";
                }
                REP(j, 0, -3 + 4 * N - 2 * i) {
                    cout << "*";
                }
                REP(j, 0, i / 2) {
                    cout << " *";
                }
                cout << endl;
            }
        } else if (i == mid) {
            REP(j, 0, 2*N - 1) {
                cout << "* ";
            }
            cout << endl;
        } else {
            if (i % 2) {
                REP(j, 0, N - (i-mid+1)/2) {
                    cout << "* ";
                }
                REP(j, 0, -3 + 4*((i-mid)+1)/2) {
                    cout << " ";
                }
                REP(j, 0, N - (i-mid+1)/2) {
                    cout << " *";
                }
                cout << endl;
            } else {
                REP(j, 0, N - 1 - (i-mid)/2) {
                    cout << "* ";
                }
                REP(j, 0, (i-mid)*2 + 1) {
                    cout << "*";
                }
                REP(j, 0, N - 1 - (i-mid)/2) {
                    cout << " *";
                }
                cout << endl;
            }
        }
    }

    return 0;
}